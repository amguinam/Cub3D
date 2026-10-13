/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_is_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:46:32 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 12:21:53 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

int	while_is_space(t_rbuf *file, uint8_t *c)
{
	bool	eof;

	while (*c == ' ')
	{
		if (rbuf_try_read_byte(file, c, &eof) != 0)
			return (-1);
		if (eof)
			break ;
	}
	return (0);
}
