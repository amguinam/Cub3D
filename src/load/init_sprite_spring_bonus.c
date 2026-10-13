/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_spring_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:36:12 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:46:20 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "bonus.h"

void	init_sprite_spring_north(t_game *g)
{
	init_one_sprite(g, &g->texture.season[3].north[0],
		"./images/north_spring.xpm");
	init_one_sprite(g, &g->texture.season[3].north[1],
		"./images/north_spring1.xpm");
	init_one_sprite(g, &g->texture.season[3].north[2],
		"./images/north_spring2.xpm");
	init_one_sprite(g, &g->texture.season[3].north[3],
		"./images/north_spring3.xpm");
}

void	init_sprite_spring_south(t_game *g)
{
	init_one_sprite(g, &g->texture.season[3].south[0],
		"./images/south_spring.xpm");
	init_one_sprite(g, &g->texture.season[3].south[1],
		"./images/south_spring1.xpm");
	init_one_sprite(g, &g->texture.season[3].south[2],
		"./images/south_spring2.xpm");
	init_one_sprite(g, &g->texture.season[3].south[3],
		"./images/south_spring3.xpm");
}

void	init_sprite_spring_east(t_game *g)
{
	init_one_sprite(g, &g->texture.season[3].east[0],
		"./images/east_spring.xpm");
	init_one_sprite(g, &g->texture.season[3].east[1],
		"./images/east_spring1.xpm");
	init_one_sprite(g, &g->texture.season[3].east[2],
		"./images/east_spring2.xpm");
	init_one_sprite(g, &g->texture.season[3].east[3],
		"./images/east_spring3.xpm");
}

void	init_sprite_spring_west(t_game *g)
{
	init_one_sprite(g, &g->texture.season[3].west[0],
		"./images/west_spring.xpm");
	init_one_sprite(g, &g->texture.season[3].west[1],
		"./images/west_spring1.xpm");
	init_one_sprite(g, &g->texture.season[3].west[2],
		"./images/west_spring2.xpm");
	init_one_sprite(g, &g->texture.season[3].west[3],
		"./images/west_spring3.xpm");
}

void	init_sprite_spring(t_game *g, char c)
{
	if (c == 'N')
		init_sprite_spring_north(g);
	else if (c == 'S')
		init_sprite_spring_south(g);
	else if (c == 'E')
		init_sprite_spring_east(g);
	else if (c == 'W')
		init_sprite_spring_west(g);
}
