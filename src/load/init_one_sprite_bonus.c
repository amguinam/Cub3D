/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_one_sprite_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:13:26 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/10 15:06:20 by Srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "game.h"
#include "error.h"

void	init_one_sprite(t_game *g, t_dir *dir, char *path)
{
	t_err	*err;

	err = image_load(g, &dir->image, path);
	if (err == NULL)
		dir->name.data = "save";
	else
		err_free(err);
}
