/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:39:52 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 12:21:02 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parsing.h"

void	free_lines(t_lines *lines)
{
	int	i;

	i = 0;
	while (i < lines->size)
	{
		free(lines->str[i].data);
		i++;
	}
	free(lines->str);
}
