/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:24:41 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:24:45 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "error.h"

t_err	*creat_image(t_game *g)
{
	g->image.image = mlx_new_image(g->mlx, g->window.width, g->window.height);
	if (!g->image.image)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"image no creat"));
	g->image.data = mlx_get_data_addr(g->image.image, &g->image.pix_bits,
			&g->image.size_line, &g->image.pix_order);
	g->image.size.x = g->window.width;
	g->image.size.y = g->window.height;
	return (NULL);
}
