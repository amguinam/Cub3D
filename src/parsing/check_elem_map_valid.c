/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem_map_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:38:38 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 10:31:53 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "error.h"
#include "parsing.h"

static t_err	*is_eof(t_lines *map, t_line *str)
{
	t_err	*err;

	pars_size_after_delet_space_end_str(str);
	err = push_str(map, *str);
	if (err != NULL)
		return (free_map_no_valid(map, str), err);
	init_line(str);
	return (NULL);
}

static t_err	*loop_elem(t_lines *map, t_rbuf *file, t_line *str, bool *dir)
{
	uint8_t	c;
	t_err	*err;
	bool	eof;

	while (1)
	{
		err = rbuf_try_read_byte(file, &c, &eof);
		if (err != NULL)
			return (free_map_no_valid(map, str), err);
		if (eof)
		{
			err = is_eof(map, str);
			return (err);
		}
		if (is_char_authorize(c, dir) == false)
			return (free_map_no_valid(map, str),
				err_new_fmt(err_loc(__FILE__, __LINE__),
					"`%c` no authorize", c));
		err = look_and_push_char(map, str, c);
		if (err != NULL)
			return (free_map_no_valid(map, str), err);
	}
	return (NULL);
}

t_err	*check_elem_map_valid(t_lines *map, t_rbuf *file)
{
	t_line	new_str;
	bool	player_dir;
	t_err	*err;

	player_dir = false;
	init_lines(map);
	init_line(&new_str);
	err = loop_elem(map, file, &new_str, &player_dir);
	if (err != NULL)
		return (err);
	if (player_dir == false)
		return (free_map_no_valid(map, &new_str),
			err_new_fmt(err_loc(__FILE__, __LINE__), "player don't exist"));
	return (0);
}
