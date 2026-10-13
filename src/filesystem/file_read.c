/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:54:49 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "error.h"
#include "filesystem.h"

t_err	*file_read(t_file *self, uint8_t *buf, size_t *len)
{
	ssize_t	r;

	r = read(self->fd, buf, *len);
	if (r == -1)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"couldn't read from file: %s", strerror(errno)));
	*len = r;
	return (NULL);
}
