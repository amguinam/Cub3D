/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:27:03 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/08 09:35:14 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stddef.h>
# include <stdint.h>

# include "filesystem.h"
# include "game.h"

/// Is it necessary to know the current type being treated.
///
///	1 if it’s him and 0 if it’s not him.
typedef struct s_type
{
	bool	sky;
	bool	floor;
	bool	north;
	bool	south;
	bool	west;
	bool	east;
	bool	door;
}	t_type;

/// To store all the map initially.
typedef struct s_lines
{
	t_line	*str;
	int		size;
	int		capacity;
}	t_lines;

/// To move forward if it’s a space.
int		while_is_space(t_rbuf *file, uint8_t *c);

/// Allows you to know if the type we found already exists.
///
/// If it does, return an error.
t_err	*is_type_exist(t_game *g, char c);

/// Let me know if our char is the co-owner of the first letter of a direction.
int		is_dir(char c);

/// Lets you know if our char corresponds to a direction, the sky, or the floor.
int		is_type(char c);

/// Current backup type if one exists,check the second character if it is a dir.
int		who_type_and_type_is_ok(char old_c, char c, t_type *type);

/// Check if the current type has received any info or if it is still empty.
///
/// If it is empty, it returns -1; otherwise, it returns 0.
int		type_identifier_and_info(t_game *g, t_type *type);

/// Allows you to save the colors given in the file in the t_color struct.
t_err	*save_atoi_rgb(t_game *g, uint8_t *c, t_rbuf *file, t_type *type);

/// For the push direction, the info in the name.
///
/// For the sky and ground in t_color.
t_err	*save_info_with_type(t_type *type, t_game *g, uint8_t *c, t_rbuf *file);

/// Add a '\0' at the end of the dir to truncate if there are spaces at the end.
///
/// And also to be able to use it in the mlx.
t_err	*add_zero_end_line(t_game *g, t_type *type);

/// Gather the functions to check the entire first part of a line, so the type.
t_err	*look_type(t_game *g, uint8_t *c, t_type *type, t_rbuf *file);

/// Check if there is at least a space between the type and the information.
t_err	*space_between_type_and_info(t_rbuf *file, uint8_t *c);

/// Loop to gather all the information.
t_err	*look_info(t_game *g, t_type *type, uint8_t *c, t_rbuf *file);

/// Allows you to check whether everything is good at the end,
///
/// That there are indeed some useful information and delet spaces at the end.
t_err	*info_final_error(t_game *g, uint8_t *c, t_type *type, t_rbuf *file);

/// Look at a whole line of the file give.
t_err	*check_elem(t_game *g, uint8_t c, t_type *type, t_rbuf *file);

/// Check if we have all the elements of the map. 
int		we_have_all_info_for_each_elem(t_game *g);

/// Allows you to gather and retrieve the info of all the elem before the map.
t_err	*recovering_info_befor_map(t_game *g, t_rbuf *file);

/// Serves to initialize as NULL & 0 the line.
void	init_line(t_line *line);

/// Initialize as NULL & 0 rows.
void	init_lines(t_lines *lines);

/// Allows all the information from the struct t_type to be set to 0.
void	init_type(t_type *type);

/// Sends a character in a t_line.
///
/// Increases its size, if no more ability to copy and read the memory.
t_err	*push_char(t_line *line, char c);

/// Sends a string in a t_lines.
///
/// Increases its size, if no more ability to copy and read the memory.
t_err	*push_str(t_lines *line, t_line str);

/// If there are gaps at the end of the thong, the size decreases.
void	pars_size_after_delet_space_end_str(t_line *line);

/// Check if the char is in the char, so allow directions: 0, 1, ' ' and '\n'.
bool	is_char_authorize(char c, bool *player_dir);

/// Release the new line and the lines already on the map if they are created.
void	free_map_no_valid(t_lines *map, t_line *new_str);

/// Look at the character and the push in a line.
///
/// If we arrived at the end of this line, push this line to the map.
t_err	*look_and_push_char(t_lines *map, t_line *new_str, char c);

/// Loop on the map to see if all elem are allowed and to save it in a tmp map.
t_err	*check_elem_map_valid(t_lines *map, t_rbuf *file);

/// Calculation in this longest temporary map line.
int		size_max_line(t_lines *map);

/// Loop on the map to clear the elements.
void	free_map(t_map *map, int size_max);

/// Loop in the map to fill each cell with the corresponding elements.
///
/// Inialize the position and direction of the player.
void	fill_line_map(t_map *map, t_game *g, t_lines *lines, int pos);

/// Allocate the map we will use and fill it in.
t_err	*fill_map(t_game *g, t_lines *lines);

/// Recursive function to see if the player can leave the map.
int		path_player_in_map(t_map *map, int y, int x);

/// Make a copy of the map to be able to modify.
t_err	*map_close(t_game *g);

/// Check if the map works with the requested constraints.
t_err	*map_valid(t_game *g, t_rbuf *file);

/// Check if each direction exists in the game and let it go if it is allocated.
void	free_dir(t_game *g);

/// Releases the different lines already allocated.
void	free_lines(t_lines *lines);

#endif
