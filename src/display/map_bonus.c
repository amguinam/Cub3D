/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:28:37 by ambre             #+#    #+#             */
/*   Updated: 2026/10/12 09:19:49 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>

#include "game.h"
#include "bonus.h"

void	square_color_pixel(t_image *image, t_vec pos, int zoom, int color)
{
	int	col;
	int	row;
	int	*dst;

	row = 0;
	while (row < MINIMAP_CELL_SIZE * zoom)
	{
		col = 0;
		while (col < MINIMAP_CELL_SIZE * zoom)
		{
			dst = (int *)&image->data[image->size_line * (row + pos.y)];
			dst[col + pos.x] = color;
			col++;
		}
		row++;
	}
}

void	copy_image(t_image *dst, t_image *src, t_vec pos, int zoom)
{
	int		row;
	int		col;
	t_vec	max;
	int		*dst_line;
	int		*src_line;

	row = 0;
	max.y = src->size.y * zoom;
	if (max.y + pos.y > dst->size.y)
		max.y = dst->size.y - pos.y;
	while (row < max.y)
	{
		col = 0;
		max.x = src->size.x * zoom;
		if (max.x + pos.x > dst->size.x)
			max.x = dst->size.x - pos.x;
		while (col < max.x)
		{
			dst_line = (int *)&dst->data[dst->size_line * (row + pos.y)];
			src_line = (int *)&src->data[src->size_line * (row / zoom)];
			dst_line[col + pos.x] = src_line[col / zoom];
			col++;
		}
		row++;
	}
}

void	print_player_in_minimap(t_game *g, t_vec pos)
{
	if (g->dir.y <= -sqrt(3.0) / 2.0 && g->arrow[0].image != NULL)
		copy_image(&g->image, &g->arrow[0], pos, g->zoom);
	else if (g->dir.x >= sqrt(3.0) / 2.0 && g->arrow[1].image != NULL)
		copy_image(&g->image, &g->arrow[1], pos, g->zoom);
	else if (g->dir.y >= sqrt(3.0) / 2.0 && g->arrow[2].image != NULL)
		copy_image(&g->image, &g->arrow[2], pos, g->zoom);
	else if (g->dir.x <= -sqrt(3.0) / 2.0 && g->arrow[3].image != NULL)
		copy_image(&g->image, &g->arrow[3], pos, g->zoom);
	else if ((g->dir.x >= 0 && g->dir.y <= 0) && g->arrow[4].image != NULL)
		copy_image(&g->image, &g->arrow[4], pos, g->zoom);
	else if ((g->dir.x >= 0 && g->dir.y >= 0) && g->arrow[5].image != NULL)
		copy_image(&g->image, &g->arrow[5], pos, g->zoom);
	else if ((g->dir.x <= 0 && g->dir.y >= 0) && g->arrow[6].image != NULL)
		copy_image(&g->image, &g->arrow[6], pos, g->zoom);
	else if ((g->dir.x <= 0 && g->dir.y <= 0) && g->arrow[7].image != NULL)
		copy_image(&g->image, &g->arrow[7], pos, g->zoom);
	else
		square_color_pixel(&g->image, pos, g->zoom, 0xFF0000);
}

static void	put_minimap_cell(t_game *g, t_vec *map)
{
	t_vec2_double	scale;
	t_vec			pos;
	t_cell			cell;

	scale.x = (map->x - g->pos.x) * g->zoom * MINIMAP_CELL_SIZE;
	scale.y = (map->y - g->pos.y) * g->zoom * MINIMAP_CELL_SIZE;
	cell = g->map.cell[map->y][map->x++];
	if (scale.x < -MINIMAP_WIDTH || scale.x > MINIMAP_WIDTH
		|| scale.y < -MINIMAP_HEIGHT || scale.y > MINIMAP_HEIGHT)
		return ;
	pos.x = g->window.width - MINIMAP_WIDTH + scale.x
		- MINIMAP_CELL_SIZE * g->zoom - MINIMAP_BORDER;
	pos.y = g->window.height - MINIMAP_HEIGHT + scale.y
		- MINIMAP_CELL_SIZE * g->zoom - MINIMAP_BORDER;
	if (scale.x < 0 && scale.x > -MINIMAP_CELL_SIZE * g->zoom
		&& scale.y < 0 && scale.y > -MINIMAP_CELL_SIZE * g->zoom)
		print_player_in_minimap(g, pos);
	else if (cell == CELL_WALL)
		square_color_pixel(&g->image, pos, g->zoom, 0x000000);
	else if (cell == CELL_EMPTY)
		square_color_pixel(&g->image, pos, g->zoom, 0xFFFFFF);
	else if (cell == CELL_DOOR)
		square_color_pixel(&g->image, pos, g->zoom, 0x0000F0);
}

void	minimap_bonus(t_game *g)
{
	t_vec	map;

	map.y = 0;
	while (map.y < g->map.height)
	{
		map.x = 0;
		while (map.x < g->map.width)
		{
			put_minimap_cell(g, &map);
		}
		map.y++;
	}
}
