/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_type_and_type_is_ok_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:09:52 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:09:54 by amguinam         ###   ########.fr       */
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
	else if (old_c == 'D')
		type->door = true;
	else if (old_c == 'C')
		type->sky = true;
	else if (old_c == 'F')
		type->floor = true;
	else
		return (-1);
	return (0);
}
