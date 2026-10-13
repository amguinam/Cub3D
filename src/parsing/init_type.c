/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:23:27 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/08 09:43:35 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	init_type(t_type *type)
{
	type->sky = false;
	type->floor = false;
	type->north = false;
	type->south = false;
	type->west = false;
	type->east = false;
	type->door = false;
}
