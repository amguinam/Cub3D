/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:34:00 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 21:41:12 by Srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "game.h"
#include "bonus.h"

t_err	*init_texture(t_game *g)
{
	t_err	*err;

	err = NULL;
	init_images(g);
	if (g->texture.season[0].north[0].name.data != NULL)
		err = image_load(g, &g->texture.season[0].north[0].image,
				g->texture.season[0].north[0].name.data);
	if (err == NULL && g->texture.season[0].south[0].name.data != NULL)
		err = image_load(g, &g->texture.season[0].south[0].image,
				g->texture.season[0].south[0].name.data);
	if (err == NULL && g->texture.season[0].west[0].name.data != NULL)
		err = image_load(g, &g->texture.season[0].west[0].image,
				g->texture.season[0].west[0].name.data);
	if (err == NULL && g->texture.season[0].east[0].name.data != NULL)
		err = image_load(g, &g->texture.season[0].east[0].image,
				g->texture.season[0].east[0].name.data);
	if (err != NULL)
		return (err);
	return (NULL);
}
