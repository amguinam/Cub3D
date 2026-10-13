/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 11:02:29 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/13 08:22:25 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	cell_clear(t_game *g, t_ray *r)
{
	if (g->map.cell[r->map.y][r->map.x] == CELL_EMPTY)
		return (1);
	if (g->map.cell[r->map.y][r->map.x] == CELL_DOOR)
	{
		if ((g->pos.y + 2 >= r->map.y && g->pos.y - 2 <= r->map.y)
			&& (g->pos.x + 2 >= r->map.x && g->pos.x - 2 <= r->map.x))
			return (1);
		if ((g->pos.y + 3 >= r->map.y && g->pos.y - 3 <= r->map.y)
			&& (g->pos.x + 3 >= r->map.x && g->pos.x - 3 <= r->map.x))
			r->door_dist = DOOR_ZOOM_CLOSE;
		r->is_door = true;
	}
	return (0);
}

void	dda(t_game *g, t_ray *r)
{
	while (cell_clear(g, r))
	{
		if (r->side_distance.x < r->side_distance.y)
		{
			r->side_distance.x += r->delta_distance.x;
			r->map.x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->side_distance.y += r->delta_distance.y;
			r->map.y += r->step.y;
			r->side = 1;
		}
	}
}
