/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_delta_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:29:24 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:29:25 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_delta_distance(t_ray *r)
{
	if (r->dir.x == 0)
		r->delta_distance.x = 1e30;
	else
	{
		if (r->dir.x < 0)
			r->delta_distance.x = 1.0 / -r->dir.x;
		else
			r->delta_distance.x = 1.0 / r->dir.x;
	}
	if (r->dir.y == 0)
		r->delta_distance.y = 1e30;
	else
	{
		if (r->dir.y < 0)
			r->delta_distance.y = 1.0 / -r->dir.y;
		else
			r->delta_distance.y = 1.0 / r->dir.y;
	}
}
