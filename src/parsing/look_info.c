/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:42:14 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 12:03:36 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"
#include "parsing.h"
#include "game.h"
#include "error.h"

t_err	*look_info(t_game *g, t_type *type, uint8_t *c, t_rbuf *file)
{
	t_err	*err;
	bool	eof;

	while (1)
	{
		err = save_info_with_type(type, g, c, file);
		if (err != NULL)
			return (err);
		if (*c == '\n')
			break ;
		err = rbuf_try_read_byte(file, c, &eof);
		if (err != NULL)
			return (err);
		if (eof || *c == '\n')
			break ;
	}
	return (NULL);
}
