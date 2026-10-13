/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_no_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:40:20 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:40:22 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parsing.h"

void	free_map_no_valid(t_lines *map, t_line *new_str)
{
	if (new_str->data != NULL)
		free(new_str->data);
	if (map->str != NULL)
		free_lines(map);
}
