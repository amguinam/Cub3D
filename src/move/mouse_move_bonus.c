/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:20:11 by ambre             #+#    #+#             */
/*   Updated: 2026/10/07 10:51:18 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xutil.h>

#include "game.h"
#include "mlx.h"

int	mouse_move(int x, int y, void *param)
{
	t_game	*g;
	double	rot_angle;

	g = param;
	(void)y;
	if (g->mouse.up == 1)
	{
		if (x != g->window.width / 2)
		{
			rot_angle = (x - g->mouse.x) * ((g->rot_speed / 100) * 0.001);
			rotate_player(g, rot_angle);
		}
	}
	return (0);
}
