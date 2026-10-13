/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:38:36 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:35:26 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game.h"
#include "mlx.h"
#include "parsing.h"

void	free_game(t_game *g)
{
	free_dir(g);
	free_texture(g);
	if (g->image.image != NULL)
		mlx_destroy_image(g->mlx, g->image.image);
	if (g->window.window != NULL)
		mlx_destroy_window(g->mlx, g->window.window);
	if (g->mlx != NULL)
		mlx_destroy_display(g->mlx);
	free(g->rays);
	free(g->mlx);
	if (g->map.cell != NULL)
		free_map(&g->map, g->map.height);
	g->mlx = NULL;
	g->window.window = NULL;
}
