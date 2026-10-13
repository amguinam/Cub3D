/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:36:58 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/06 09:36:18 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <X11/Xutil.h>

#include "game.h"
#include "mlx.h"

int	key_hook(int keysym, void *param)
{
	t_game	*g;

	g = param;
	if (keysym == XK_Escape)
	{
		g->is_done = 1;
		mlx_loop_end(g->mlx);
	}
	if (0x0000 <= keysym && keysym <= 0x00ff)
		g->input.a[keysym & 0xff] = true;
	if (0xff00 <= keysym && keysym <= 0xffff)
		g->input.b[keysym & 0xff] = true;
	return (0);
}
