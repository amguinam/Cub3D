/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   we_have_all_info_each_elem_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:18:58 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:19:16 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

int	we_have_all_info_for_each_elem(t_game *g)
{
	if (g->texture.season[0].north[0].name.data != NULL
		&& g->texture.season[0].south[0].name.data != NULL
		&& g->texture.season[0].west[0].name.data != NULL
		&& g->texture.season[0].east[0].name.data != NULL
		&& g->texture.door[0].name.data
		&& g->texture.floor.r >= 0 && g->texture.floor.g >= 0
		&& g->texture.floor.b >= 0 && g->texture.sky.r >= 0
		&& g->texture.sky.g >= 0 && g->texture.sky.b >= 0)
		return (1);
	return (0);
}
