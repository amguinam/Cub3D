/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:35:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/05 22:23:41 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

void	display_map(t_game *g)
{
	compute_rays(g);
	compose_image(g);
	mlx_put_image_to_window(g->mlx, g->window.window, g->image.image, 0, 0);
}
