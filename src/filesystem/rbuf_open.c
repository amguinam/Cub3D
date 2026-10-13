/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbuf_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:55:51 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

t_err	*rbuf_open(t_rbuf *self, const char *path)
{
	self->read = 0;
	self->write = 0;
	return (file_open(&self->file, path));
}
