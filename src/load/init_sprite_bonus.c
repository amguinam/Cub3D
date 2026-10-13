/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 10:41:56 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 10:58:03 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "bonus.h"

void	init_sprite(t_game *g, char c)
{
	init_sprite_summer(g, c);
	init_sprite_winter(g, c);
	init_sprite_spring(g, c);
	init_sprite_autumn(g, c);
}
