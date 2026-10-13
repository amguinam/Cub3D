/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_front_and_rear.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:36:41 by ambre             #+#    #+#             */
/*   Updated: 2026/10/10 09:01:08 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_player_front_and_rear(t_game *g, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = g->pos.x + g->dir.x * move_speed;
	if (!is_wall(g, new_x, g->pos.y))
		g->pos.x = new_x;
	new_y = g->pos.y + g->dir.y * move_speed;
	if (!is_wall(g, g->pos.x, new_y))
		g->pos.y = new_y;
	if (g->move >= 80)
		g->move = 0;
	g->move += 1;
}
