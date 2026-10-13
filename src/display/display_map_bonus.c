/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 11:12:23 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 11:12:25 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "bonus.h"

void	display_map(t_game *g)
{
	compute_rays(g);
	compose_image(g);
	minimap_bonus(g);
	mlx_put_image_to_window(g->mlx, g->window.window, g->image.image, 0, 0);
}
