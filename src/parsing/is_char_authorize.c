/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_authorize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:41:17 by ambre             #+#    #+#             */
/*   Updated: 2026/10/08 09:02:04 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_char_authorize(char c, bool *player_dir)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (*player_dir == false)
		{
			*player_dir = true;
			return (true);
		}
	}
	if (c == ' ' || c == '\n' || c == '1' || c == '0')
		return (true);
	return (false);
}
