/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:08:07 by srichard          #+#    #+#             */
/*   Updated: 2026/10/12 08:58:53 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "str.h"

void	string_free(t_string *self)
{
	if (self->cap >= self->len)
		free(self->data);
	self->data = NULL;
	self->len = 0;
	self->cap = 0;
}
