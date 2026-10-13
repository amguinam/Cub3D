/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type_exist_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:11:27 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:11:48 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "error.h"
#include "str.h"

t_err	*is_type_exist(t_game *g, char c)
{
	if (g->texture.season[0].north[0].name.data != NULL && c == 'N')
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"The north already exists"));
	if (g->texture.season[0].south[0].name.data != NULL && c == 'S')
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"The south already exists"));
	if (g->texture.season[0].west[0].name.data != NULL && c == 'W')
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"The west already exists"));
	if (g->texture.season[0].east[0].name.data != NULL && c == 'E')
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"The east already exists"));
	if (g->texture.door[0].name.data != NULL && c == 'E')
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"The door already exists"));
	if (g->texture.sky.r != -1 && c == 'C')
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"The sky already exists"));
	if (g->texture.floor.r != -1 && c == 'F')
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"The floor already exists"));
	return (NULL);
}
