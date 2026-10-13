/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_side.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:36:52 by ambre             #+#    #+#             */
/*   Updated: 2026/10/10 09:00:24 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_player_side(t_game *g, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = g->pos.x + g->plane.x * move_speed;
	if (!is_wall(g, new_x, g->pos.y))
		g->pos.x = new_x;
	new_y = g->pos.y + g->plane.y * move_speed;
	if (!is_wall(g, g->pos.x, new_y))
		g->pos.y = new_y;
	if (g->move >= 80)
		g->move = 0;
	g->move += 1;
}
