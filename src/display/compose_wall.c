/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:28:07 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 09:26:06 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "game.h"

void	compose_wall(t_game *g, t_dir *d, int y, int x)
{
	if (y < g->rays[x].draw_start)
	{
		my_put_pixel(&g->image, x, y, g->texture.sky.pixel);
	}
	else if (y < g->rays[x].draw_end)
	{
		if (d->image.image != NULL)
			my_put_pixel(&g->image, x, y, get_pixel_color(&d->image,
					(int)(g->rays[x].wall_x * d->image.size.x),
					(int)((double)(y - g->rays[x].draw_start)
						/ (g->rays[x].draw_end - g->rays[x].draw_start)
						* d->image.size.y)));
		else
			my_put_pixel(&g->image, x, y, 0x00F0F0);
	}
	else
	{
		my_put_pixel(&g->image, x, y, g->texture.floor.pixel);
	}
}
