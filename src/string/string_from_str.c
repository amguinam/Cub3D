/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_from_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:59:17 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

t_err	*string_from_str(t_string *self, t_str str)
{
	string_new(self);
	return (string_push_str(self, str));
}
