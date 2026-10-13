/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:28:18 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:28:19 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	compute_rays(t_game *g)
{
	int	x;

	x = 0;
	while (x < g->window.width)
	{
		init_ray(g, &g->rays[x], x);
		dda(g, &g->rays[x]);
		calculating_perpenticular_dist(&g->rays[x]);
		calculating_terminals_for_draw(g, &g->rays[x]);
		x++;
	}
}
