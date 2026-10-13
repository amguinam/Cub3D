/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:28:32 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 11:12:44 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	dda(t_game *g, t_ray *r)
{
	while (g->map.cell[r->map.y][r->map.x] == CELL_EMPTY)
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
