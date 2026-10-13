/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_final_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:40:33 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 14:02:08 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "game.h"
#include "error.h"

t_err	*info_final_error(t_game *g, uint8_t *c, t_type *type, t_rbuf *file)
{
	t_err	*err;

	if (while_is_space(file, c))
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"malloc fail"));
	if (*c != '\n')
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"more info"));
	if (type_identifier_and_info(g, type))
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"no info after the type"));
	err = add_zero_end_line(g, type);
	if (err != NULL)
		return (err);
	return (NULL);
}
