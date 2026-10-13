/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 11:00:25 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/11 11:00:30 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "game.h"
#include "error.h"

t_err	*load_game(t_game *g)
{
	t_err	*err;

	init_game(g);
	err = init_texture(g);
	if (err != NULL)
		return (err);
	return (0);
}
