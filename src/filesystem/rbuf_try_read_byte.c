/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbuf_try_read_byte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:56:16 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

t_err	*rbuf_try_read_byte(t_rbuf *self, uint8_t *b, bool *eof)
{
	t_err	*err;

	err = rbuf_fill(self, eof);
	if (err != NULL)
		return (err);
	if (!*eof)
		*b = self->buf[self->read++];
	return (NULL);
}
