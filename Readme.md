*This project was created as part of the 42 curriculum by amguinam and srichard.*

# Cub3D - Our first Raycaster with miniLibX

## Description

**cub3D** is a small first-person 3D engine inspired by *Wolfenstein 3D*, the game widely considered to be the first FPS. The goal is to display "realistic" dynamic view of the inside of a maze using the **ray-casting** technique, written in C with the **miniLibX** graphic library.

The program takes a scene description file(`.cub`) sd its only argument. This file describes the wall textures (one per cardinal description), the floor and the ceiling/sky colors, and the map of the maze. The player can then walk around and look around inside the maze.

**Overview of the features**

- Strict parsing and validation of the `.cub` file (with explicit error messages).
- Ray-casting engine based on the **DDA** algorithm.
- Different wall textures depending on the wall orientation (North, South, East, West).
- Configurable floor and ceiling colors.
- Bonus part: minimap, doors that open when the player gets close, animated wall textures.

**Documentation**

You can find the project's technical documentation by doing: 

```bash
xdg-open doc/html/index.html
```
or by using doxyen:

```bash
doxygen config
```

---

## Instructions

### Requirements

- A Linux system with `cc`, `make` and the X11 development libraries (`libx11`, `libext`).
- The miniLibX library.
- The math library (`-lm`).

### Compilation

```bash
make        # standard version
make bonus  # bonus version
make clean  # remove object files
make fclean # remove objects and binary
make re     # rebuild from scratch
```

The project is compiled with `cc -Wall -Wextra -Werror`, and the Makefile does not relink unnecessarily, The `miniLibX` is compiled through is own Makefile.

### Execution

```bash
./cub3D maps/valid/minimal.cub
```

Examples of valid maps included in the project:

```bash
./cub3D maps/valid/mini.cub
./cub3D maps/valid/complex.cub
./cub3D maps/valid/bonus.cub
```

### Controls

#### Standard controls

| Key | Action |
| --- | --- |
| `W` / `S` | Move forward / backward |
| `A` / `D` | Strafe left / right |
| `<-` / `->` | Rotate the point of view left / right |
| `Shift` | Faster movement |
| `ESC` | Close the window and quit cleanly |

#### Bonus controls

| Key | Action |
| --- | --- |
| `M` | Increase movement speed |
| `N` | Decrease movement speed |
| `P` | Zoom in |
| `-` | Zoom out |
| `Mouse movement` | Bonus camera / pointer-based movement |

Bonus-specific behaviors are described in the [Bonus part](#bonus-part) section.

### Map format

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
 
F 220,100,0
C 225,30,0
 
        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

**Rules**

- Element identifiers: `NO`, `SO`, `WE`, `EA` (texture paths), `F` (floor color), `C` (ceiling/sky color).
- Colors are `R,G,B` with each value in `[0,255]`.
- The **map is always the last** element of the file.
- The map only contains `0` (empty), `1` (wall), `N`/`S`/`E`/`W` (player start position and orientation) - exactly **one** player.
- The map must be **closed / surrounded by walls**.

---

## Error handling

A major part of this project is the validation layer: before the game starts, the program verifies that the input file is structurally valid and that the world described by the map is exploitable.

### What is checked

- file extension and argument count
- presence of mandatory textures and colors
- duplicate identifiers or missing entries
- invalid characters inside the map
- map size and line consistency
- closing of the map and proper wall enclosure
- player presence and uniqueness
- clean memory release if an error occurs

### Error model

The project uses a custom error system (`err_*`) to keep errors explicit and chainable. Instead of a simple `return (1)`, errors are wrapped with structured information such as:

- the message itself,
- the source file or location when relevant,
- a linked list of nested errors if a failure is caused by a previous one.

This approach makes debugging easier and ensures that the program can report a precise reason when parsing fails.

### Failure flow

When a parsing or initialization error occurs, the program stops in a controlled way:

1. the game state is partially constructed,
2. allocated resources are freed,
3. the error is displayed to the user,
4. the process exits without leaving memory leaks or invalid pointers.

---

## Ray-casting architecture

The engine is based on ray-casting: the program sends rays from the player position into the map and computes the distance to the first wall encountered. That distance is then used to draw a vertical slice of wall on the screen.

### 1. The camera model

The player is represented by a position and a direction vector, along with a camera plane perpendicular to the direction. This is the classic ray-caster model:

- `pos` = player position in the 2D map
- `dir` = current viewing direction
- `plane` = camera plane used to build rays across the screen

Each vertical stripe on the screen corresponds to one ray. The ray direction is computed by combining the base direction, the camera plane, and the horizontal position of the column.

### 2. DDA stepping

The map is a grid, so walking cell by cell would be too slow and inefficient. Instead, the project uses the DDA algorithm (Digital Differential Analyzer), which jumps directly from one grid line to the next.

For every ray, the code computes:

- `delta_distance`: length needed to cross one cell in each axis
- `step`: direction of the next map cell to inspect
- `side_distance`: distance from the player to the next vertical/horizontal boundary

This allows the program to walk the map efficiently until it reaches a wall.

### 3. Wall distance and projection

Once the wall is hit, the engine computes the perpendicular distance to the wall. This avoids the fisheye effect that would appear if raw Euclidean distance were used directly. The result is then used to determine the wall height on screen:

- the closer the wall, the taller the stripe
- the farther the wall, the shorter the stripe

The code then calculates the beginning and end of the vertical segment to draw, which gives the proper perspective in the maze.

### 4. Texture mapping

Once the hit wall is known, the ray also determines the exact point where the ray intersects the wall. This value is then converted into a texture coordinate, allowing the engine to sample the correct part of the wall texture. Different faces are handled separately according to the direction of the impact (North, South, East, West).

### 5. Frame pipeline

Every frame follows the same process:

1. initialize the ray for each screen column
2. compute ray direction and delta distances
3. perform DDA stepping through the map
4. detect the wall hit and compute the perpendicular distance
5. determine the stripe height and screen limits
6. select the correct texture column and draw the wall
7. fill the image buffer and display it in the window

This logic is split across dedicated functions such as:

- `init_ray`
- `init_delta_distance`
- `init_step_and_side`
- `dda`
- `calculating_perpenticular_dist`
- `calculating_terminals_for_draw`
- `compose_image`
- `compose_wall`

### 6. Movement and camera rotation

The game loop continuously updates the player state according to keyboard input. The player can move forward, backward, strafe, and rotate the view. Those transformations are applied to the direction and camera plane vectors, which keeps the projection mathematically coherent while the player moves inside the maze.

---

## Bonus part

The bonus version extends the base project with additional gameplay and visual elements. It is designed to make the engine richer without changing the core ray-casting architecture.

### Minimap

A small top-down view of the map is displayed in the game window. This helps the player understand their position in the maze and is a common feature in first-person games.

### Doors and interactive elements

The bonus version introduces elements such as doors or alternate map cells that are not treated exactly like ordinary walls. These elements allow more dynamic map design and help showcase that the project supports richer scene content than a strict basic maze.

### Sprite-like content and extra rendering

The repository includes bonus-specific load and rendering code for extra elements. This is consistent with a classic ray-casting approach where decorative objects and special map features are added on top of the wall rendering.

### Enhanced controls and polish

The bonus branch also includes additional input handling and visual improvements such as:

- mouse interaction
- extra movement adjustments
- more advanced event handling
- optional visual additions in the interface

This part demonstrates how the base engine can be extended while keeping the same rendering principles and project architecture.

---

## How the project works

The game follows a simple but structured execution flow:

1. the program receives the `.cub` file as input,
2. the parser validates the file and extracts all map data,
3. textures and colors are loaded into memory,
4. the player position and orientation are initialized,
5. the window and image buffer are created,
6. the main loop starts and updates the game state each frame,
7. rays are cast, walls are rendered, and the final image is displayed.

---

## Project structure

```text
.
├── Makefile
├── Readme.md
├── include/
│   ├── bonus.h
│   ├── game.h
│   ├── parsing.h
│   └── ...
├── src/
│   ├── bin/
│   ├── display/
│   ├── error/
│   ├── filesystem/
│   ├── format/
│   ├── hook/
│   ├── load/
│   ├── move/
│   ├── parsing/
│   └── string/
├── maps/
│   ├── valid/
│   └── no_valid/
├── images/
├── minilibx-linux/
└── cub3D
```
---

## Resources

**Ray-casting and DDA**

- Lode Vandevenne - *Raycasting* tutorial : <https://lodev.org/cgtutor/raycasting.html>
- Wolfenstein 3D (original game, for reference) : <http://users.atw.hu/wolf3d/>

**miniLibX**

- 42 Docs- miniLibX: <https://harm-smits.github.io/42docs/libs/minilibx>

**Artificial Intelligence**

No AI was used for this project.