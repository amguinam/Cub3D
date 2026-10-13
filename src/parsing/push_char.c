/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:44:06 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 12:02:40 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parsing.h"
#include "error.h"

t_err	*push_char(t_line *line, char c)
{
	int		new_capacity;
	char	*new;

	if (line->size == line->capacity)
	{
		new_capacity = line->capacity * 2;
		if (new_capacity <= 0)
			new_capacity = 2;
		new = malloc(sizeof(*new) * new_capacity);
		if (!new)
			return (err_new_fmt(err_loc(__FILE__, __LINE__),
					"malloc fail"));
		ft_memcpy(new, line->data, line->size * sizeof(*line->data));
		line->capacity = new_capacity;
		free(line->data);
		line->data = new;
	}
	line->data[line->size++] = c;
	return (NULL);
}
