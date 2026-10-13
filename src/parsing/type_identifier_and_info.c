/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_identifier_and_info.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:46:11 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 10:33:49 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

int	type_identifier_and_info(t_game *g, t_type *type)
{
	if ((type->north == true
			&& g->texture.season[0].north[0].name.data == NULL)
		|| (type->south == true
			&& g->texture.season[0].south[0].name.data == NULL)
		|| (type->west == true
			&& g->texture.season[0].west[0].name.data == NULL)
		|| (type->east == true
			&& g->texture.season[0].east[0].name.data == NULL)
		|| (type->floor == true && (g->texture.floor.r == -1
				|| g->texture.floor.g == -1 || g->texture.floor.b == -1))
		|| (type->sky == true && (g->texture.sky.r == -1
				|| g->texture.sky.g == -1 || g->texture.sky.b == -1)))
		return (-1);
	return (0);
}
