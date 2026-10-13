/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_winter_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:54:48 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:55:53 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "bonus.h"

void	init_sprite_winter_north(t_game *g)
{
	init_one_sprite(g, &g->texture.season[2].north[0],
		"./images/north_winter.xpm");
	init_one_sprite(g, &g->texture.season[2].north[1],
		"./images/north_winter1.xpm");
	init_one_sprite(g, &g->texture.season[2].north[2],
		"./images/north_winter2.xpm");
	init_one_sprite(g, &g->texture.season[2].north[3],
		"./images/north_winter3.xpm");
}

void	init_sprite_winter_south(t_game *g)
{
	init_one_sprite(g, &g->texture.season[2].south[0],
		"./images/south_winter.xpm");
	init_one_sprite(g, &g->texture.season[2].south[1],
		"./images/south_winter1.xpm");
	init_one_sprite(g, &g->texture.season[2].south[2],
		"./images/south_winter2.xpm");
	init_one_sprite(g, &g->texture.season[2].south[3],
		"./images/south_winter3.xpm");
}

void	init_sprite_winter_east(t_game *g)
{
	init_one_sprite(g, &g->texture.season[2].east[0],
		"./images/east_winter.xpm");
	init_one_sprite(g, &g->texture.season[2].east[1],
		"./images/east_winter1.xpm");
	init_one_sprite(g, &g->texture.season[2].east[2],
		"./images/east_winter2.xpm");
	init_one_sprite(g, &g->texture.season[2].east[3],
		"./images/east_winter3.xpm");
}

void	init_sprite_winter_west(t_game *g)
{
	init_one_sprite(g, &g->texture.season[2].west[0],
		"./images/west_winter.xpm");
	init_one_sprite(g, &g->texture.season[2].west[1],
		"./images/west_winter1.xpm");
	init_one_sprite(g, &g->texture.season[2].west[2],
		"./images/west_winter2.xpm");
	init_one_sprite(g, &g->texture.season[2].west[3],
		"./images/west_winter3.xpm");
}

void	init_sprite_winter(t_game *g, char c)
{
	if (c == 'N')
		init_sprite_winter_north(g);
	else if (c == 'S')
		init_sprite_winter_south(g);
	else if (c == 'E')
		init_sprite_winter_east(g);
	else if (c == 'W')
		init_sprite_winter_west(g);
}
