/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:39:40 by ambre             #+#    #+#             */
/*   Updated: 2026/10/10 14:59:48 by Srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "game.h"

void	free_dir(t_game *g)
{
	if (g->texture.season[0].north[0].name.data != NULL)
		free(g->texture.season[0].north[0].name.data);
	if (g->texture.season[0].south[0].name.data != NULL)
		free(g->texture.season[0].south[0].name.data);
	if (g->texture.season[0].west[0].name.data != NULL)
		free(g->texture.season[0].west[0].name.data);
	if (g->texture.season[0].east[0].name.data != NULL)
		free(g->texture.season[0].east[0].name.data);
	if (g->texture.door[0].name.data != NULL)
		free(g->texture.door[0].name.data);
}
