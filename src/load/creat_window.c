/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:25:07 by ambre             #+#    #+#             */
/*   Updated: 2026/10/10 14:11:00 by Srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "game.h"
#include "mlx.h"
#include "error.h"

t_err	*creat_window(t_game *g)
{
	char	*title;

	title = "cub3D";
	g->mlx = mlx_init();
	if (!g->mlx)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"mlx don't init"));
	mlx_get_screen_size(g->mlx, &g->window.width, &g->window.height);
	g->window.width = g->window.width * 90 / 100;
	g->window.height = g->window.height * 90 / 100;
	g->window.window = mlx_new_window(g->mlx, g->window.width, g->window.height,
			title);
	if (!g->window.window)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"windows no creat"));
	return (NULL);
}
