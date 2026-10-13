/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_max_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:45:35 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:45:38 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	size_max_line(t_lines *map)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < map->size)
	{
		if (max < map->str[i].size)
			max = map->str[i].size;
		i++;
	}
	return (max);
}
