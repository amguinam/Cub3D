/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_mouse_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:10:36 by ambre             #+#    #+#             */
/*   Updated: 2026/10/06 15:10:15 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xutil.h>

#include "game.h"
#include "mlx.h"

int	key_pressed_mouse(int button, int x, int y, void *param)
{
	t_game	*g;

	g = param;
	(void)x;
	(void)y;
	if (button == Button1)
		g->mouse.up = 1;
	if (button == Button3)
	{
		if (g->zoom < 8)
			g->zoom++;
	}
	return (0);
}
