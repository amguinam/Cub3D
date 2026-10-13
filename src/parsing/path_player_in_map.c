/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_player_in_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:43:53 by ambre             #+#    #+#             */
/*   Updated: 2026/10/08 09:58:29 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	path_player_in_map(t_map *map, int y, int x)
{
	if (y < 0 || y >= map->height || x < 0 || x >= map->width
		|| map->cell[y][x] == CELL_NO_MAP)
		return (-1);
	if (map->cell[y][x] == CELL_WALL || map->cell[y][x] == CELL_CHECK)
		return (0);
	map->cell[y][x] = CELL_CHECK;
	if (path_player_in_map(map, y + 1, x))
		return (-1);
	if (path_player_in_map(map, y - 1, x))
		return (-1);
	if (path_player_in_map(map, y, x + 1))
		return (-1);
	if (path_player_in_map(map, y, x - 1))
		return (-1);
	return (0);
}
