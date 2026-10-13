/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:29:33 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 09:08:27 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_ray(t_game *g, t_ray *r, int x)
{
	double	camera;

	camera = 2 * x / (double)g->window.width -1;
	r->dir.x = g->dir.x + g->plane.x * camera;
	r->dir.y = g->dir.y + g->plane.y * camera;
	r->map.x = (int)g->pos.x;
	r->map.y = (int)g->pos.y;
	r->is_door = false;
	r->door_dist = DOOR_CLOSE;
	init_delta_distance(r);
	init_step_and_side(g, r);
}
