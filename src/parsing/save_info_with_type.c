/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info_with_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:45:22 by ambre             #+#    #+#             */
/*   Updated: 2026/10/08 09:34:46 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"
#include "error.h"

t_err	*save_info_with_type(t_type *type, t_game *g, uint8_t *c, t_rbuf *file)
{
	t_err	*err;

	if (type->north == true)
		err = push_char(&g->texture.season[0].north[0].name, *c);
	else if (type->south == true)
		err = push_char(&g->texture.season[0].south[0].name, *c);
	else if (type->west == true)
		err = push_char(&g->texture.season[0].west[0].name, *c);
	else if (type->east == true)
		err = push_char(&g->texture.season[0].east[0].name, *c);
	else if (type->door == true)
		err = push_char(&g->texture.door[0].name, *c);
	else if (type->floor == true || type->sky == true)
		err = save_atoi_rgb(g, c, file, type);
	else
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"no type: `%c`", *c));
	if (err != NULL)
		return (err);
	return (0);
}
