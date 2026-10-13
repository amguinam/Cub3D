/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:04:07 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/06 16:00:25 by Srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"
#include "error.h"

t_err	*map_valid(t_game *g, t_rbuf *file)
{
	t_lines	lines;
	t_err	*err;

	err = check_elem_map_valid(&lines, file);
	if (err != NULL)
		return (err);
	err = fill_map(g, &lines);
	if (err != NULL)
		return (free_lines(&lines), err);
	if (lines.str != NULL)
		free_lines(&lines);
	err = map_close(g);
	if (err)
	{
		free_map(&g->map, g->map.height);
		g->map.cell = NULL;
		return (err);
	}
	return (0);
}
