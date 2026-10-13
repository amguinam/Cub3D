/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_summer_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:52:01 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:52:04 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "bonus.h"

void	init_sprite_summer_north(t_game *g)
{
	init_one_sprite(g, &g->texture.season[0].north[1],
		"./images/north1.xpm");
	init_one_sprite(g, &g->texture.season[0].north[2],
		"./images/north2.xpm");
	init_one_sprite(g, &g->texture.season[0].north[3],
		"./images/north3.xpm");
}

void	init_sprite_summer_south(t_game *g)
{
	init_one_sprite(g, &g->texture.season[0].south[1],
		"./images/south1.xpm");
	init_one_sprite(g, &g->texture.season[0].south[2],
		"./images/south2.xpm");
	init_one_sprite(g, &g->texture.season[0].south[3],
		"./images/south3.xpm");
}

void	init_sprite_summer_east(t_game *g)
{
	init_one_sprite(g, &g->texture.season[0].east[1],
		"./images/east1.xpm");
	init_one_sprite(g, &g->texture.season[0].east[2],
		"./images/east2.xpm");
	init_one_sprite(g, &g->texture.season[0].east[3],
		"./images/east3.xpm");
}

void	init_sprite_summer_west(t_game *g)
{
	init_one_sprite(g, &g->texture.season[0].west[1],
		"./images/west1.xpm");
	init_one_sprite(g, &g->texture.season[0].west[2],
		"./images/west2.xpm");
	init_one_sprite(g, &g->texture.season[0].west[3],
		"./images/west3.xpm");
}

void	init_sprite_summer(t_game *g, char c)
{
	if (c == 'N')
		init_sprite_summer_north(g);
	else if (c == 'S')
		init_sprite_summer_south(g);
	else if (c == 'E')
		init_sprite_summer_east(g);
	else if (c == 'W')
		init_sprite_summer_west(g);
}
