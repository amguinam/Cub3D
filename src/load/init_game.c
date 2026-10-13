/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:32:41 by ambre             #+#    #+#             */
/*   Updated: 2026/10/12 08:10:13 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "game.h"

void	init_arrow(t_game *g)
{
	g->arrow[0].image = NULL;
	g->arrow[1].image = NULL;
	g->arrow[2].image = NULL;
	g->arrow[3].image = NULL;
	g->arrow[4].image = NULL;
	g->arrow[5].image = NULL;
	g->arrow[6].image = NULL;
	g->arrow[6].image = NULL;
}

void	init_game(t_game *g)
{
	init_color_pixel(&g->texture.floor.pixel, g->texture.floor);
	init_color_pixel(&g->texture.sky.pixel, g->texture.sky);
	init_arrow(g);
	g->is_done = 0;
	g->mouse.up = 0;
	g->move = 0;
	g->mouse.x = 0;
	g->rot_speed = 2.0;
	g->move_speed = 3.0;
	g->zoom = 1;
	g->input = (t_input){0};
}
