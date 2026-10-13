/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:33:38 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:33:53 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "error.h"

t_err	*image_load(t_game *g, t_image *i, char *path_name)
{
	i->image = mlx_xpm_file_to_image(g->mlx, path_name, &i->size.x, &i->size.y);
	if (!i->image)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"image `%s` can't find", path_name));
	i->data = mlx_get_data_addr(i->image, &i->pix_bits,
			&i->size_line, &i->pix_order);
	if (!i->data)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"data `%s` can't find", path_name));
	return (NULL);
}
