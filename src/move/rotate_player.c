/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:35:55 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:36:02 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "game.h"

void	rotate_player(t_game *g, double rot_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->dir.x;
	old_plane_x = g->plane.x;
	g->dir.x = g->dir.x * cos(rot_angle) - g->dir.y * sin(rot_angle);
	g->dir.y = old_dir_x * sin(rot_angle) + g->dir.y * cos(rot_angle);
	g->plane.x = g->plane.x * cos(rot_angle) - g->plane.y * sin(rot_angle);
	g->plane.y = old_plane_x * sin(rot_angle) + g->plane.y * cos(rot_angle);
}
