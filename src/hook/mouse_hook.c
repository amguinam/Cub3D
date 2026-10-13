/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 09:03:06 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/06 14:51:04 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xutil.h>

#include "game.h"
#include "mlx.h"

int	mouse_move(int button, int x, int y, void *param)
{
	t_game	*g;

	g = param;
	(void)x;
	(void)y;
	if (button == Button1)
	{
		if (g->zoom < 120)
			g->zoom++;
	}
	return (0);
}
