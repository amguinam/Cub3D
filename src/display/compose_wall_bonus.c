/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_wall_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 09:25:26 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 11:08:13 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "game.h"

void	compose_only_wall(t_game *g, t_dir *d, int y, int x)
{
	if (g->rays[x].is_door
		&& g->texture.door[g->rays[x].door_dist].image.image != NULL)
		my_put_pixel(&g->image, x, y,
			get_pixel_color(&g->texture.door[g->rays[x].door_dist].image,
				(int)(g->rays[x].wall_x
					* g->texture.door[g->rays[x].door_dist].image.size.x),
				(int)((double)(y - g->rays[x].draw_start)
					/ (g->rays[x].draw_end - g->rays[x].draw_start)
					* g->texture.door[g->rays[x].door_dist].image.size.y)));
	else if (!g->rays[x].is_door && d->image.image != NULL)
		my_put_pixel(&g->image, x, y, get_pixel_color(&d->image,
				(int)(g->rays[x].wall_x * d->image.size.x),
				(int)((double)(y - g->rays[x].draw_start)
					/ (g->rays[x].draw_end - g->rays[x].draw_start)
					* d->image.size.y)));
	else
		my_put_pixel(&g->image, x, y, 0x00F0F0);
}

void	compose_wall(t_game *g, t_dir *d, int y, int x)
{
	if (y < g->rays[x].draw_start)
	{
		my_put_pixel(&g->image, x, y, g->texture.sky.pixel);
	}
	else if (y < g->rays[x].draw_end)
		compose_only_wall(g, d, y, x);
	else
	{
		my_put_pixel(&g->image, x, y, g->texture.floor.pixel);
	}
}
