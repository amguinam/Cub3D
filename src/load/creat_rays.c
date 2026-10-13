/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:24:58 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:25:38 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "error.h"
#include "game.h"

t_err	*creat_rays(t_game *g)
{
	g->rays = malloc(sizeof(*g->rays) * g->window.width);
	if (!g->rays)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"rays no creat: malloc fail"));
	return (NULL);
}
