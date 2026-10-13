/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:58:59 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 11:18:58 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "game.h"
#include "bonus.h"

static t_err	*sub_init_dir_texture(t_game *g)
{
	t_err	*err;

	err = NULL;
	if (g->texture.season[0].north[0].name.data != NULL)
	{
		err = image_load(g, &g->texture.season[0].north[0].image,
				g->texture.season[0].north[0].name.data);
		init_sprite(g, 'N');
	}
	if (err == NULL && g->texture.season[0].south[0].name.data != NULL)
	{
		err = image_load(g, &g->texture.season[0].south[0].image,
				g->texture.season[0].south[0].name.data);
		init_sprite(g, 'S');
	}
	if (err == NULL && g->texture.season[0].west[0].name.data != NULL)
	{
		err = image_load(g, &g->texture.season[0].west[0].image,
				g->texture.season[0].west[0].name.data);
		init_sprite(g, 'W');
	}
	return (err);
}

static t_err	*init_dir_texture(t_game *g)
{
	t_err	*err;

	err = sub_init_dir_texture(g);
	if (err == NULL && g->texture.season[0].east[0].name.data != NULL)
	{
		err = image_load(g, &g->texture.season[0].east[0].image,
				g->texture.season[0].east[0].name.data);
		init_sprite(g, 'E');
	}
	return (err);
}

t_err	*init_texture(t_game *g)
{
	t_err	*err;

	init_images(g);
	err = init_dir_texture(g);
	if (err != NULL)
		return (err);
	if (err == NULL && g->texture.door[0].name.data != NULL)
	{
		err = image_load(g, &g->texture.door[0].image,
				g->texture.door[0].name.data);
		init_one_sprite(g, &g->texture.door[1], "./images/door1.xpm");
		init_one_sprite(g, &g->texture.door[2], "./images/door2.xpm");
		init_one_sprite(g, &g->texture.door[3], "./images/door3.xpm");
	}
	if (err != NULL)
		return (err);
	return (NULL);
}
