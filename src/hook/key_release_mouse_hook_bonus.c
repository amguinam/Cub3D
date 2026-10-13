/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_mouse_hook.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:17:43 by ambre             #+#    #+#             */
/*   Updated: 2026/10/06 14:19:53 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xutil.h>

#include "game.h"
#include "mlx.h"

int	key_release_mouse_hook(int button, int x, int y, void *param)
{
	t_game	*g;

	g = param;
	(void)y;
	if (button == Button1)
	{
		g->mouse.up = 0;
		g->mouse.x = x;
	}
	return (0);
}
