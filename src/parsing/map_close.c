/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:42:55 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 10:30:18 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "game.h"
#include "parsing.h"
#include "error.h"

static t_err	*loop_creat_map_height(t_game *g, t_map *map)
{
	int		i;

	i = 0;
	while (i < g->map.height)
	{
		map->cell[i] = malloc(sizeof(**map->cell) * g->map.width);
		if (!map->cell[i])
			return (free_map(map, i),
				err_new_fmt(err_loc(__FILE__, __LINE__), "malloc fail"));
		ft_memcpy(map->cell[i], g->map.cell[i],
			sizeof(**map->cell) * g->map.width);
		i++;
	}
	return (NULL);
}

t_err	*map_close(t_game *g)
{
	t_map	map;
	t_err	*err;

	map.cell = malloc(sizeof(*map.cell) * g->map.height);
	if (!map.cell)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"malloc fail"));
	map.width = g->map.width;
	map.height = g->map.height;
	err = loop_creat_map_height(g, &map);
	if (err != NULL)
		return (err);
	if (path_player_in_map(&map, g->pos.y, g->pos.x))
		err = err_new_fmt(err_loc(__FILE__, __LINE__),
				"path  no close");
	free_map(&map, map.height);
	return (err);
}
