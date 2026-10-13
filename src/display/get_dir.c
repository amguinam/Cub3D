/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:28:55 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 08:46:56 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_dir_e	get_dir(t_ray r)
{
	if (r.side == 1 && r.step.y == 1)
		return (EAST);
	if (r.side == 1 && r.step.y == -1)
		return (NORTH);
	if (r.side == 0 && r.step.x == 1)
		return (SOUTH);
	return (WEST);
}
