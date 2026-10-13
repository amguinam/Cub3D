/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_size_after_delet_space_end_str.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:41:26 by amguinam          #+#    #+#             */
/*   Updated: 2026/09/27 10:45:25 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	pars_size_after_delet_space_end_str(t_line *line)
{
	while (line->size > 0 && line->data[line->size - 1] == ' ')
	{
		line->size--;
	}
}
