/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating_perpenticular_dist.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:27:35 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:27:40 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	calculating_perpenticular_dist(t_ray *r)
{
	if (r->side == 0)
		r->perpenticular_dist = r->side_distance.x - r->delta_distance.x;
	else
		r->perpenticular_dist = r->side_distance.y - r->delta_distance.y;
}
