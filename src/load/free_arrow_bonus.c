/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arrow_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 08:17:57 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:30:43 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "game.h"
#include "mlx.h"

void	free_arrow(t_game *g, t_image *arrow)
{
	if (arrow->image)
		mlx_destroy_image(g->mlx, arrow->image);
	arrow->image = NULL;
}
