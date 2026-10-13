/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:30:07 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:30:08 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	my_put_pixel(t_image *image, int x, int y, int color)
{
	int	*dst;

	if (x < 0 || x >= image->size.x || y < 0 || y >= image->size.y)
		return (-1);
	dst = (int *)&image->data[y * image->size_line + x * (image->pix_bits / 8)];
	*dst = color;
	return (0);
}
