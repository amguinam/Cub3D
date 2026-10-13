/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 17:57:11 by ambre             #+#    #+#             */
/*   Updated: 2026/10/12 08:30:21 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "game.h"

# define MINIMAP_HEIGHT 100
# define MINIMAP_WIDTH 200
# define MINIMAP_CELL_SIZE 16
# define MINIMAP_BORDER 64

void	free_arrow(t_game *g, t_image *arrow);

void	init_one_sprite(t_game *g, t_dir *dir, char *path);

void	init_sprite_summer(t_game *g, char c);

void	init_sprite_winter(t_game *g, char c);

void	init_sprite_spring(t_game *g, char c);

void	init_sprite_autumn(t_game *g, char c);

void	init_sprite(t_game *g, char c);

void	minimap_bonus(t_game *g);

#endif
