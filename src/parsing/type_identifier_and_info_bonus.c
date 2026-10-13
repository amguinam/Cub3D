/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_identifier_and_info_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:19:28 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:34:08 by amguinam         ###   ########.fr       */
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
		|| (type->door == true && g->texture.door[0].name.data == NULL)
		|| (type->floor == true && (g->texture.floor.r == -1
				|| g->texture.floor.g == -1 || g->texture.floor.b == -1))
		|| (type->sky == true && (g->texture.sky.r == -1
				|| g->texture.sky.g == -1 || g->texture.sky.b == -1)))
		return (-1);
	return (0);
}
