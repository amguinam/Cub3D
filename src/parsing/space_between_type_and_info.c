/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_between_type_and_info.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:45:45 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:59:24 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"
#include "parsing.h"
#include "game.h"
#include "error.h"

t_err	*space_between_type_and_info(t_rbuf *file, uint8_t *c)
{
	bool	eof;

	if (rbuf_try_read_byte(file, c, &eof) != 0 || eof)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"info empty"));
	if (*c != ' ')
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"no space between type and info"));
	if (while_is_space(file, c))
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"malloc fail"));
	return (NULL);
}
