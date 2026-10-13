/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:36:58 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/07 08:54:35 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <X11/Xutil.h>
#include <limits.h>

#include "game.h"

static void	zoom_and_move_speed(t_game *g)
{
	if (is_key_pressed(&g->input, XK_m))
	{
		if (g->move_speed < INT_MAX)
			g->move_speed += 0.1;
	}
	if (is_key_pressed(&g->input, XK_n))
	{
		if (g->move_speed > 0)
			g->move_speed -= 0.1;
	}
	if (is_key_pressed(&g->input, XK_equal))
	{
		if (g->zoom < 8)
			g->zoom++;
	}
	if (is_key_pressed(&g->input, XK_minus))
	{
		if (g->zoom > 1)
			g->zoom--;
	}
}

void	move_player(t_game *g, double delta)
{
	double	move_dist;
	double	rot_angle;

	move_dist = g->move_speed * delta;
	if (is_key_pressed(&g->input, XK_Shift_L))
		move_dist *= 2.0;
	rot_angle = g->rot_speed * delta;
	if (is_key_pressed(&g->input, XK_d))
		move_player_side(g, move_dist);
	if (is_key_pressed(&g->input, XK_a))
		move_player_side(g, -move_dist);
	if (is_key_pressed(&g->input, XK_w))
		move_player_front_and_rear(g, move_dist);
	if (is_key_pressed(&g->input, XK_s))
		move_player_front_and_rear(g, -move_dist);
	if (is_key_pressed(&g->input, XK_Left))
		rotate_player(g, -rot_angle);
	if (is_key_pressed(&g->input, XK_Right))
		rotate_player(g, rot_angle);
	zoom_and_move_speed(g);
}
