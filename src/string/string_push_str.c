/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_push_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:08:42 by srichard          #+#    #+#             */
/*   Updated: 2026/10/12 09:00:02 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "str.h"
#include "error.h"

t_err	*string_push_str(t_string *self, t_str str)
{
	size_t	new_cap;
	char	*new_data;

	if (str.len == 0)
		return (NULL);
	if (self->len + str.len > self->cap)
	{
		new_cap = self->cap * 2;
		if (new_cap < 64)
			new_cap = 64;
		if (new_cap < self->len + str.len)
			new_cap = self->len + str.len;
		new_data = malloc(sizeof(*new_data) * (new_cap + 1));
		if (new_data == NULL)
			return (err_new_fmt(err_loc(__FILE__, __LINE__),
					"couldn't allocate string: %s", strerror(errno)));
		ft_memcpy(new_data, self->data, self->len);
		free(self->data);
		self->data = new_data;
		self->cap = new_cap;
	}
	ft_memcpy(&self->data[self->len], str.data, str.len);
	self->len += str.len;
	self->data[self->len] = '\0';
	return (NULL);
}
