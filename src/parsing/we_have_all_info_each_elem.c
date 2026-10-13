/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   we_have_all_info_each_elem.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:10:23 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:12:30 by amguinam         ###   ########.fr       */
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
		&& g->texture.floor.r >= 0 && g->texture.floor.g >= 0
		&& g->texture.floor.b >= 0 && g->texture.sky.r >= 0
		&& g->texture.sky.g >= 0 && g->texture.sky.b >= 0)
		return (1);
	return (0);
}
