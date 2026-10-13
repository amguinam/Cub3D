/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovering_info_befor_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:44:37 by ambre             #+#    #+#             */
/*   Updated: 2026/10/08 17:02:48 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"
#include "game.h"
#include "parsing.h"
#include "error.h"

static void	init_name_images(t_game *g)
{
	init_line(&g->texture.season[0].north[0].name);
	init_line(&g->texture.season[0].north[1].name);
	init_line(&g->texture.season[0].north[2].name);
	init_line(&g->texture.season[0].north[3].name);
	init_line(&g->texture.season[0].south[0].name);
	init_line(&g->texture.season[0].south[1].name);
	init_line(&g->texture.season[0].south[2].name);
	init_line(&g->texture.season[0].south[3].name);
	init_line(&g->texture.season[0].west[0].name);
	init_line(&g->texture.season[0].west[1].name);
	init_line(&g->texture.season[0].west[2].name);
	init_line(&g->texture.season[0].west[3].name);
	init_line(&g->texture.season[0].east[0].name);
	init_line(&g->texture.season[0].east[1].name);
	init_line(&g->texture.season[0].east[2].name);
	init_line(&g->texture.season[0].east[3].name);
	init_line(&g->texture.door[0].name);
	init_line(&g->texture.door[1].name);
	init_line(&g->texture.door[2].name);
	init_line(&g->texture.door[3].name);
}

static void	init_game_texture(t_game *g)
{
	init_name_images(g);
	g->texture.floor.r = -1;
	g->texture.floor.g = -1;
	g->texture.floor.b = -1;
	g->texture.sky.r = -1;
	g->texture.sky.g = -1;
	g->texture.sky.b = -1;
}

t_err	*recovering_info_befor_map(t_game *g, t_rbuf *file)
{
	uint8_t	c;
	bool	eof;
	t_type	type;
	t_err	*err;

	init_game_texture(g);
	while (1)
	{
		init_type(&type);
		if (rbuf_try_read_byte(file, &c, &eof) != 0)
			return (err_new_fmt(err_loc(__FILE__, __LINE__),
					"read file fail"));
		if (eof || we_have_all_info_for_each_elem(g))
			break ;
		err = check_elem(g, c, &type, file);
		if (err != NULL)
			return (err);
	}
	return (NULL);
}
