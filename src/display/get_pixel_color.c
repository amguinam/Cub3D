/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:29:07 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:29:09 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	get_pixel_color(t_image *image, int x, int y)
{
	int	*color;

	if (x < 0 || x >= image->size.x || y < 0 || y >= image->size.y)
		return (0);
	color = (int *)&image->data[y * image->size_line + x
		* (image->pix_bits / 8)];
	return (*color);
}
