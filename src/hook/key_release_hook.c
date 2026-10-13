/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:32:06 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:32:08 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

int	key_release_hook(int keysym, void *param)
{
	t_game	*g;

	g = param;
	if (0x0000 <= keysym && keysym <= 0x00ff)
		g->input.a[keysym & 0xff] = false;
	if (0xff00 <= keysym && keysym <= 0xffff)
		g->input.b[keysym & 0xff] = false;
	return (0);
}
