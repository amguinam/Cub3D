/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_and_push_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:41:58 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 12:22:20 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parsing.h"

t_err	*look_and_push_char(t_lines *map, t_line *new_str, char c)
{
	t_err	*err;

	if (c == '\n')
	{
		pars_size_after_delet_space_end_str(new_str);
		err = push_str(map, *new_str);
		if (err != NULL)
			return (err);
		init_line(new_str);
	}
	if (c != '\n')
	{
		err = push_char(new_str, c);
		if (err != NULL)
			return (err);
	}
	return (NULL);
}
