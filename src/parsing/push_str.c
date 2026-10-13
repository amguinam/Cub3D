/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:44:26 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 12:02:56 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parsing.h"
#include "error.h"

t_err	*push_str(t_lines *lines, t_line str)
{
	int		new_capacity;
	t_line	*new;

	if (lines->size == lines->capacity)
	{
		new_capacity = lines->capacity * 2;
		if (new_capacity <= 0)
			new_capacity = 2;
		new = malloc(sizeof(*new) * new_capacity);
		if (!new)
			return (err_new_fmt(err_loc(__FILE__, __LINE__),
					"malloc fail"));
		ft_memcpy(new, lines->str, lines->size * sizeof(*lines->str));
		lines->capacity = new_capacity;
		free(lines->str);
		lines->str = new;
	}
	lines->str[lines->size++] = str;
	return (NULL);
}
