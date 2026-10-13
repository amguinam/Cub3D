/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 09:00:48 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdbool.h>
# include <stdint.h>
# include <sys/time.h>
# include <stddef.h>

# include "error_forward.h"

/// Possible element in each cell.
typedef enum e_cell
{
	CELL_NO_MAP = ' ',
	CELL_EMPTY = '0',
	CELL_WALL = '1',
	CELL_DOOR = '2',
	CELL_CHECK = 'X'
}	t_cell;

/// The map that is composed of cells.
typedef struct s_map
{
	t_cell			**cell;
	int				height;
	int				width;
}	t_map;

/// Line where the size is the end.
typedef struct s_line
{
	char	*data;
	int		size;
	int		capacity;
}	t_line;

/// Vector in double.
typedef struct s_vec2_double
{
	double	x;
	double	y;
}	t_vec2_double;

/// Vector in int.
typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

/// For directions.
typedef enum e_dir_e
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
}	t_dir_e;

// door open en close form sprite
typedef enum e_door
{
	DOOR_CLOSE = 0,
	DOOR_CLOSE_SPRITE = 1,
	DOOR_ZOOM_CLOSE = 2,
	DOOR_ZOOM_CLOSE_SPRITE = 3,
}	t_door;

/// Information for raycasting.
typedef struct s_ray
{
	/// radius direction
	t_vec2_double	dir;
	/// distance to move forward of a cell
	t_vec2_double	delta_distance;
	/// distance until the next intersection
	t_vec2_double	side_distance;
	t_vec			step;
	t_vec			map;
	/// side = 1 find a wall, side = 0 not find a wall
	int				side;
	double			perpenticular_dist;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	t_dir_e			facing;
	bool			is_door;
	t_door			door_dist;
}	t_ray;

/// This is the image displayed as each loop.
typedef struct s_image
{
	void	*image;
	char	*data;
	int		pix_bits;
	int		size_line;
	int		pix_order;
	t_vec	size;
}	t_image;

/// The color in int rgb and pixel.
typedef struct s_color
{
	int	pixel;
	int	r;
	int	g;
	int	b;
}	t_color;

/// For each image direction created from the name of the record.
typedef struct s_dir
{
	t_line	name;
	t_image	image;
}	t_dir;

typedef struct s_dirs
{
	t_dir	north[4];
	t_dir	south[4];
	t_dir	west[4];
	t_dir	east[4];
}	t_dirs;

typedef struct s_textures
{
	t_dirs	season[4];
	t_dir	door[4];
	t_color	floor;
	t_color	sky;
}	t_textures;
/*
/// For textures and colors.
typedef struct s_images
{
	t_dir	north[4];
	t_dir	south[4];
	t_dir	west[4];
	t_dir	east[4];
	t_dir	door[4];
	t_color	floor;
	t_color	sky;
}	t_images;
*/
/// Window management.
typedef struct s_window
{
	void	*window;
	int		width;
	int		height;
}	t_window;

/// Use for keys imput.
typedef struct s_input
{
	bool	a[256];
	bool	b[256];
}	t_input;

/// Stuct to use for moving the mouse.
typedef struct s_mouse
{
	bool	up;
	int		x;
}	t_mouse;

/// This is the structure that manages the entire game.
typedef struct s_game
{
	void			*mlx;
	t_window		window;
	t_textures		texture;
	t_image			image;
	t_map			map;
	t_vec2_double	pos;
	t_image			arrow[8];
	int				zoom;
	t_mouse			mouse;
	int				move;
	t_vec2_double	dir;
	t_vec2_double	plane;
	double			rot_speed;
	double			move_speed;
	int				is_done;
	t_input			input;
	t_ray			*rays;
	struct timeval	last_frame_tv;
}	t_game;

/// Main function that will allow you to manage the game.
t_err	*load_cub(int argc, char **argv);

/// See if the file name actually goes off .cub.
t_err	*file_name_valid(char *str);

/// Check if the file is correct and that the opposites are respected.
t_err	*file_valid(t_game *g, char *path);

/// Allows you to create the window thanks to the mlx.
t_err	*creat_window(t_game *g);

/// Create the image that would be sent every turn afterwards.
t_err	*creat_image(t_game *g);

/// Alloue rays that will close the size of the window length.
t_err	*creat_rays(t_game *g);

/// Create an image with the mlx according to the path.
t_err	*image_load(t_game *g, t_image *i, char *path_name);

/// Init in NULL images in texture and door.
void	init_images(t_game *g);

/// Load all images from the directions.
t_err	*init_texture(t_game *g);

/// Put the colors in a pixel to get the color.
void	init_color_pixel(int *pixel, t_color color);

/// Make the information import for the game.
void	init_game(t_game *g);

/// Allows you to load the necessary resources for beginners.
t_err	*load_game(t_game *g);

///	Calculating the side_distance and the ray step.
void	init_step_and_side(t_game *g, t_ray *r);

/// Calculation of delta_distance according to the direction of ray.
void	init_delta_distance(t_ray *r);

/// Updates the radius as each turn.
void	init_ray(t_game *g, t_ray *r, int x);

/// Cross the entire grid.
void	dda(t_game *g, t_ray *r);

/// Calculation of the perpenticular distance based on the side and deltat dist.
void	calculating_perpenticular_dist(t_ray *r);
t_dir_e	get_dir(t_ray r);

/// Calculation of the beginning and end for the drawings.
void	calculating_terminals_for_draw(t_game *g, t_ray *r);

/// Find the color of the pixel you need according to the parameters.
int		get_pixel_color(t_image *image, int x, int y);

/// Allows to send a chosen color in an image.
int		my_put_pixel(t_image *image, int x, int y, int color);

/// Allows you to calculate everything that will be put in a line of an image.
void	compute_rays(t_game *game);

/// Depending on where you put the pixel you need in the final image.
void	compose_wall(t_game *g, t_dir *d, int y, int x);

/// Permet de remplir l’image finale de pixel.
void	compose_image(t_game *g);

/// Send the compositing images to the window to see them thanks to the MLX.
void	display_map(t_game *g);

/// Allows you to change your point of view.
void	rotate_player(t_game *g, double rot_angle);

/// Lets you know if you are on an obstacle.
int		is_wall(t_game *g, int x, int y);

/// Allows the player to move this from front to back.
void	move_player_front_and_rear(t_game *g, double move_speed);

/// Allows the player to move on the coters.
void	move_player_side(t_game *g, double move_speed);

/// Realize all the player’s movements.
void	move_player(t_game *g, double delta);

/// Turns with the mouse.
int		mouse_move(int x, int y, void *param);

/// This is the loop that allows the image to be displayed.
int		loop_hook(void	*param);

/// Save the key press in an imput.
bool	is_key_pressed(t_input *input, int keysym);

/// Key press in mouse
int		key_pressed_mouse(int button, int x, int y, void *param);

/// Depending on the key, press or have actions.
int		key_hook(int keycode, void *param);

/// If the input is not part of this keysysm category.
///
/// It sets the input as false.
int		key_release_hook(int keycode, void *param);

/// Key release in mouse
int		key_release_mouse_hook(int button, int x, int y, void *param);

/// It allows you to leave the loop.
int		destroy_hook(void *param);

/// Destroy and free texture.
void	free_texture(t_game *g);

/// Released everything that had been allocated since the beginning.
void	free_game(t_game *g);

/// Print string with fd.
int		write_all(int fd, const char *data, size_t len);

#endif
