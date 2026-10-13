/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 13:18:49 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/08 21:12:10 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	compose_image(t_game *g)
{
	int		y;
	int		x;
	t_dir	*d;

	y = 0;
	while (y < g->window.height)
	{
		x = 0;
		while (x < g->window.width)
		{
			d = (t_dir *[4]){
				&g->texture.season[0].north[0],
				&g->texture.season[0].east[0],
				&g->texture.season[0].south[0],
				&g->texture.season[0].west[0]
			}[g->rays[x].facing];
			compose_wall(g, d, y, x);
			x++;
		}
		y++;
	}
}
