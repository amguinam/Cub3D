/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 08:16:22 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:31:05 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game.h"
#include "mlx.h"
#include "parsing.h"
#include "bonus.h"

void	free_game(t_game *g)
{
	int	i;

	i = 0;
	free_dir(g);
	free_texture(g);
	while (i < 8)
	{
		free_arrow(g, &g->arrow[i]);
		i++;
	}
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
