/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_authorize_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:21:54 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:21:58 by amguinam         ###   ########.fr       */
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
	if (c == ' ' || c == '\n' || c == '1' || c == '0' || c == '2')
		return (true);
	return (false);
}
