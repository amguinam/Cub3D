/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:06:36 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 10:58:46 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "game.h"

static void	init_texture_image(t_dir (*dir)[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(*dir)[i].image.image = NULL;
		i++;
	}
}

void	init_images(t_game *g)
{
	int	pos;

	pos = 0;
	while (pos < 4)
	{
		init_texture_image(&g->texture.season[pos].north);
		init_texture_image(&g->texture.season[pos].south);
		init_texture_image(&g->texture.season[pos].west);
		init_texture_image(&g->texture.season[pos].east);
		pos++;
	}
	init_texture_image(&g->texture.door);
}
