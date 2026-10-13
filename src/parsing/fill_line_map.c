/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:53:06 by ambre             #+#    #+#             */
/*   Updated: 2026/10/07 08:48:09 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "game.h"
#include "parsing.h"

static void	load_dir_player(t_game *g, t_lines *lines, int pos, int i)
{
	g->pos.x = i + 0.5;
	g->pos.y = pos + 0.5;
	g->dir.x = 0.0;
	g->dir.y = -1.0;
	g->plane.x = 0.66;
	g->plane.y = 0.0;
	if (lines->str[pos].data[i] == 'S')
		rotate_player(g, M_PI);
	else if (lines->str[pos].data[i] == 'W')
		rotate_player(g, -M_PI_2);
	else if (lines->str[pos].data[i] == 'E')
		rotate_player(g, M_PI_2);
}

void	fill_line_map(t_map *map, t_game *g, t_lines *lines, int pos)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (lines->str[pos].data == NULL || i >= lines->str[pos].size)
			map->cell[pos][i] = CELL_NO_MAP;
		else if (lines->str[pos].data[i] == 'N'
			|| lines->str[pos].data[i] == 'S' || lines->str[pos].data[i] == 'W'
			|| lines->str[pos].data[i] == 'E')
		{
			map->cell[pos][i] = CELL_EMPTY;
			load_dir_player(g, lines, pos, i);
		}
		else
			map->cell[pos][i] = lines->str[pos].data[i];
		i++;
	}
}
