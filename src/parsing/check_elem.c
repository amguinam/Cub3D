/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:21:40 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/07 12:11:46 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "game.h"
#include "error.h"

t_err	*check_elem(t_game *g, uint8_t c, t_type *type, t_rbuf *file)
{
	t_err	*err;

	if (while_is_space(file, &c))
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"malloc fail"));
	if (c == '\n')
		return (NULL);
	err = look_type(g, &c, type, file);
	if (err != NULL)
		return (err);
	err = space_between_type_and_info(file, &c);
	if (err != NULL)
		return (err);
	err = look_info(g, type, &c, file);
	if (err != NULL)
		return (err);
	err = info_final_error(g, &c, type, file);
	if (err != NULL)
		return (err);
	return (NULL);
}
