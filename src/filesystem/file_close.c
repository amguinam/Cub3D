/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:54:10 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "error.h"
#include "filesystem.h"

t_err	*file_close(t_file *self)
{
	if (close(self->fd) < 0)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"couldn't close file: %s", strerror(errno)));
	return (NULL);
}
