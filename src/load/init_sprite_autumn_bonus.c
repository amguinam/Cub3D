/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_autumn_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:52:55 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:53:55 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "bonus.h"

void	init_sprite_autumn_north(t_game *g)
{
	init_one_sprite(g, &g->texture.season[1].north[0],
		"./images/north_autumn.xpm");
	init_one_sprite(g, &g->texture.season[1].north[1],
		"./images/north_autumn1.xpm");
	init_one_sprite(g, &g->texture.season[1].north[2],
		"./images/north_autumn2.xpm");
	init_one_sprite(g, &g->texture.season[1].north[3],
		"./images/north_autumn3.xpm");
}

void	init_sprite_autumn_south(t_game *g)
{
	init_one_sprite(g, &g->texture.season[1].south[0],
		"./images/south_autumn.xpm");
	init_one_sprite(g, &g->texture.season[1].south[1],
		"./images/south_autumn1.xpm");
	init_one_sprite(g, &g->texture.season[1].south[2],
		"./images/south_autumn2.xpm");
	init_one_sprite(g, &g->texture.season[1].south[3],
		"./images/south_autumn3.xpm");
}

void	init_sprite_autumn_east(t_game *g)
{
	init_one_sprite(g, &g->texture.season[1].east[0],
		"./images/east_autumn.xpm");
	init_one_sprite(g, &g->texture.season[1].east[1],
		"./images/east_autumn1.xpm");
	init_one_sprite(g, &g->texture.season[1].east[2],
		"./images/east_autumn2.xpm");
	init_one_sprite(g, &g->texture.season[1].east[3],
		"./images/east_autumn3.xpm");
}

void	init_sprite_autumn_west(t_game *g)
{
	init_one_sprite(g, &g->texture.season[1].west[0],
		"./images/west_autumn.xpm");
	init_one_sprite(g, &g->texture.season[1].west[1],
		"./images/west_autumn1.xpm");
	init_one_sprite(g, &g->texture.season[1].west[2],
		"./images/west_autumn2.xpm");
	init_one_sprite(g, &g->texture.season[1].west[3],
		"./images/west_autumn3.xpm");
}

void	init_sprite_autumn(t_game *g, char c)
{
	if (c == 'N')
		init_sprite_autumn_north(g);
	else if (c == 'S')
		init_sprite_autumn_south(g);
	else if (c == 'E')
		init_sprite_autumn_east(g);
	else if (c == 'W')
		init_sprite_autumn_west(g);
}
