/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_image_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 11:09:28 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 22:11:24 by Srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "game.h"

static void	init_dir(t_game *g, t_dir **d, int x, t_vec pos)
{
	*d = (t_dir *[4]){
		&g->texture.season[pos.x].north[pos.y],
		&g->texture.season[pos.x].east[pos.y],
		&g->texture.season[pos.x].south[pos.y],
		&g->texture.season[pos.x].west[pos.y],
	}[g->rays[x].facing];
}

static void	look_season(t_game *g, t_vec *pos)
{
	if (g->move <= 20)
		pos->x = 0;
	else if (g->move > 20 && g->move <= 40)
		pos->x = 1;
	else if (g->move > 40 && g->move <= 60)
		pos->x = 2;
	else if (g->move >= 60)
		pos->x = 3;
}

static void	door_go_sprite2(t_game *g, int x)
{
	if (g->rays[x].door_dist == DOOR_CLOSE)
		g->rays[x].door_dist = DOOR_CLOSE_SPRITE;
	if (g->rays[x].door_dist == DOOR_ZOOM_CLOSE)
		g->rays[x].door_dist = DOOR_ZOOM_CLOSE_SPRITE;
}

static void	compose_image_for_time(t_game *g, t_dir **d, int x)
{
	struct timeval	tv;
	int				msec;
	int				img_sec;
	t_vec			pos;

	gettimeofday(&tv, NULL);
	msec = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	img_sec = (msec / 500) % 4;
	look_season(g, &pos);
	if (img_sec <= 0)
		pos.y = 0;
	else if (img_sec == 1)
	{
		door_go_sprite2(g, x);
		pos.y = 1;
	}
	else if (img_sec == 2)
		pos.y = 2;
	else if (img_sec == 3)
	{
		door_go_sprite2(g, x);
		pos.y = 3;
	}
	init_dir(g, d, x, pos);
}

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
			compose_image_for_time(g, &d, x);
			compose_wall(g, d, y, x);
			x++;
		}
		y++;
	}
}
