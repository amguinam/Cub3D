/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:58:16 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:42:23 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "game.h"
#include "error.h"
#include "bonus.h"

void	init_arrow_sprite(t_game *g)
{
	image_load(g, &g->arrow[0], "./images/arrow.xpm");
	if (g->arrow[0].size.y != 16 || g->arrow[0].size.x != 16)
		free_arrow(g, &g->arrow[0]);
	image_load(g, &g->arrow[1], "./images/arrow1.xpm");
	if (g->arrow[1].size.y != 16 || g->arrow[1].size.x != 16)
		free_arrow(g, &g->arrow[1]);
	image_load(g, &g->arrow[2], "./images/arrow2.xpm");
	if (g->arrow[2].size.y != 16 || g->arrow[2].size.x != 16)
		free_arrow(g, &g->arrow[2]);
	image_load(g, &g->arrow[3], "./images/arrow3.xpm");
	if (g->arrow[3].size.y != 16 || g->arrow[3].size.x != 16)
		free_arrow(g, &g->arrow[3]);
	image_load(g, &g->arrow[4], "./images/arrow4.xpm");
	if (g->arrow[4].size.y != 16 || g->arrow[4].size.x != 16)
		free_arrow(g, &g->arrow[4]);
	image_load(g, &g->arrow[5], "./images/arrow5.xpm");
	if (g->arrow[5].size.y != 16 || g->arrow[5].size.x != 16)
		free_arrow(g, &g->arrow[5]);
	image_load(g, &g->arrow[6], "./images/arrow6.xpm");
	if (g->arrow[6].size.y != 16 || g->arrow[6].size.x != 16)
		free_arrow(g, &g->arrow[6]);
	image_load(g, &g->arrow[7], "./images/arrow7.xpm");
	if (g->arrow[7].size.y != 16 || g->arrow[7].size.x != 16)
		free_arrow(g, &g->arrow[7]);
}

t_err	*load_game(t_game *g)
{
	t_err	*err;

	init_game(g);
	err = init_texture(g);
	if (err != NULL)
		return (err);
	init_arrow_sprite(g);
	return (0);
}
