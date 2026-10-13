/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_step_and_side.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:29:59 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:30:00 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_step_and_side(t_game *g, t_ray *r)
{
	if (r->dir.x < 0)
	{
		r->step.x = -1;
		r->side_distance.x = (g->pos.x - r->map.x) * r->delta_distance.x;
	}
	else
	{
		r->step.x = 1;
		r->side_distance.x = (r->map.x + 1.0 - g->pos.x) * r->delta_distance.x;
	}
	if (r->dir.y < 0)
	{
		r->step.y = -1;
		r->side_distance.y = (g->pos.y - r->map.y) * r->delta_distance.y;
	}
	else
	{
		r->step.y = 1;
		r->side_distance.y = (r->map.y + 1.0 - g->pos.y) * r->delta_distance.y;
	}
}
