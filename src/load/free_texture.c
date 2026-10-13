/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 11:06:45 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:59:50 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "game.h"
#include "mlx.h"

static void	loop_destroy_image(t_game *g, t_dir (*dir)[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((*dir)[i].image.image)
			mlx_destroy_image(g->mlx, (*dir)[i].image.image);
		i++;
	}
}

void	free_texture(t_game *g)
{
	int	pos;

	pos = 0;
	while (pos < 4)
	{
		loop_destroy_image(g, &g->texture.season[pos].north);
		loop_destroy_image(g, &g->texture.season[pos].south);
		loop_destroy_image(g, &g->texture.season[pos].west);
		loop_destroy_image(g, &g->texture.season[pos].east);
		pos++;
	}
	loop_destroy_image(g, &g->texture.door);
}
