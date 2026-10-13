/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:42:41 by ambre             #+#    #+#             */
/*   Updated: 2026/10/07 12:11:12 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"
#include "parsing.h"
#include "game.h"
#include "error.h"

t_err	*look_type(t_game *g, uint8_t *c, t_type *type, t_rbuf *file)
{
	t_err	*err;
	char	old_c;
	bool	eof;

	err = is_type_exist(g, *c);
	if (err)
		return (err);
	if (!is_type(*c))
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"type no exist"));
	old_c = *c;
	if (is_dir(*c))
		if (rbuf_try_read_byte(file, c, &eof) != 0 || eof)
			return (err_new_fmt(err_loc(__FILE__, __LINE__),
					"info empty"));
	if (who_type_and_type_is_ok(old_c, *c, type))
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"malloc fail"));
	return (NULL);
}
