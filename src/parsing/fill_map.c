/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:52:43 by ambre             #+#    #+#             */
/*   Updated: 2026/10/06 15:54:14 by Srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "game.h"
#include "parsing.h"
#include "error.h"

t_err	*fill_map(t_game *g, t_lines *lines)
{
	int	i;

	g->map.width = size_max_line(lines);
	g->map.height = lines->size;
	g->map.cell = malloc(sizeof(*g->map.cell) * g->map.height);
	if (!g->map.cell)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"malloc fail"));
	i = 0;
	while (i < g->map.height)
	{
		g->map.cell[i] = malloc(sizeof(**g->map.cell) * g->map.width);
		if (!g->map.cell[i])
			return (free_map(&g->map, i),
				err_new_fmt(err_loc(__FILE__, __LINE__), "malloc fail"));
		fill_line_map(&g->map, g, lines, i);
		i++;
	}
	return (NULL);
}
