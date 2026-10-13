/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_type_and_type_is_ok.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:46:45 by ambre             #+#    #+#             */
/*   Updated: 2026/10/08 09:39:02 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	who_type_and_type_is_ok(char old_c, char c, t_type *type)
{
	if (c == 'O' && old_c == 'N')
		type->north = true;
	else if (c == 'O' && old_c == 'S')
		type->south = true;
	else if (c == 'E' && old_c == 'W')
		type->west = true;
	else if (c == 'A' && old_c == 'E')
		type->east = true;
	else if (old_c == 'C')
		type->sky = true;
	else if (old_c == 'F')
		type->floor = true;
	else
		return (-1);
	return (0);
}
