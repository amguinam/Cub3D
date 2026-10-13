/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:30:51 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 11:30:52 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

bool	is_key_pressed(t_input *input, int keysym)
{
	if (0x0000 <= keysym && keysym <= 0x00ff)
		return (input->a[keysym & 0xff]);
	if (0xff00 <= keysym && keysym <= 0xffff)
		return (input->b[keysym & 0xff]);
	return (false);
}
