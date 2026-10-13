/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_push_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:08:33 by srichard          #+#    #+#             */
/*   Updated: 2026/10/12 08:59:44 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

t_err	*string_push_char(t_string *self, char c)
{
	return (string_push_str(self, (t_str){.data = &c, .len = 1}));
}
