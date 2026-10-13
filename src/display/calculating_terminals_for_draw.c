/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating_terminals_for_draw.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:27:47 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 08:43:19 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "game.h"

void	calculating_terminals_for_draw(t_game *g, t_ray *r)
{
	int	height;

	height = (int)(g->window.height / r->perpenticular_dist);
	r->draw_start = -height / 2 + g->window.height / 2;
	r->draw_end = height / 2 + g->window.height / 2;
	if (r->side == 0)
		r->wall_x = g->pos.y + r->perpenticular_dist * r->dir.y;
	else
		r->wall_x = g->pos.x + r->perpenticular_dist * r->dir.x;
	r->wall_x -= floor(r->wall_x);
	r->facing = get_dir(*r);
	if (r->side == 0)
		r->wall_x = 1.0 - r->wall_x;
}
