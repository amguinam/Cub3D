/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbuf_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:55:33 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

t_err	*rbuf_fill(t_rbuf *self, bool *eof)
{
	t_err	*err;

	if (self->read == self->write)
	{
		self->read = 0;
		self->write = RBUF_SIZE;
		err = file_read(&self->file, self->buf, &self->write);
		if (err != NULL)
			return (err);
	}
	*eof = self->write == 0;
	return (NULL);
}
