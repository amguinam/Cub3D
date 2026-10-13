/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbuf_read_exact.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:56:01 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "filesystem.h"
#include "str.h"

t_err	*rbuf_read_exact(t_rbuf *self, void *b, size_t len)
{
	t_err	*err;
	bool	eof;
	size_t	r;

	while (len > 0)
	{
		err = rbuf_fill(self, &eof);
		if (err != NULL)
			return (err);
		if (eof)
			return (err_new_fmt(err_loc(__FILE__, __LINE__),
					"unexpected EOF"));
		r = self->write - self->read;
		if (r > len)
			r = len;
		ft_memcpy(b, &self->buf[self->read], r);
		self->read += r;
		b += r;
		len -= r;
	}
	return (NULL);
}
