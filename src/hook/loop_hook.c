/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:31:28 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 11:21:40 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "game.h"

/// is us:  printf("%lf FPS\n", 1 / delta);
/// form look FPS
int	loop_hook(void	*param)
{
	t_game			*g;
	struct timeval	now;
	double			delta;

	g = param;
	gettimeofday(&now, NULL);
	delta = (double)(now.tv_sec - g->last_frame_tv.tv_sec)
		+ (double)(now.tv_usec - g->last_frame_tv.tv_usec) / 1000000.0;
	if (g->is_done == 1)
		return (0);
	if (g->is_done == 0)
	{
		move_player(g, delta);
	}
	display_map(g);
	g->last_frame_tv = now;
	return (0);
}
