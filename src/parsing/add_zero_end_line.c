/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zero_end_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:37:43 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 10:18:06 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"
#include "error.h"
#include "filesystem.h"

static t_err	*delet_space_and_add_zero(t_line *str)
{
	t_err	*err;

	pars_size_after_delet_space_end_str(str);
	err = push_char(str, '\0');
	if (err != NULL)
		return (err);
	return (NULL);
}

t_err	*add_zero_end_line(t_game *g, t_type *type)
{
	t_err	*err;

	err = NULL;
	if (type->north == true && g->texture.season[0].north[0].name.size > 0)
		err = delet_space_and_add_zero(&g->texture.season[0].north[0].name);
	if (err == NULL && type->south == true
		&& g->texture.season[0].south[0].name.size > 0)
		err = delet_space_and_add_zero(&g->texture.season[0].south[0].name);
	if (err == NULL && type->west == true
		&& g->texture.season[0].west[0].name.size > 0)
		err = delet_space_and_add_zero(&g->texture.season[0].west[0].name);
	if (err == NULL && type->east == true
		&& g->texture.season[0].east[0].name.size > 0)
		err = delet_space_and_add_zero(&g->texture.season[0].east[0].name);
	if (type->door == true && g->texture.door[0].name.size > 0)
		err = delet_space_and_add_zero(&g->texture.door[0].name);
	if (err != NULL)
		return (err);
	return (NULL);
}
