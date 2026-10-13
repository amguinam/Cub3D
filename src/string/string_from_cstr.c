/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_from_cstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:38:04 by srichard          #+#    #+#             */
/*   Updated: 2026/10/12 08:59:07 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

t_err	*string_from_cstr(t_string *self, const char *cstr)
{
	return (string_from_str(self, str_from_cstr((char *)cstr)));
}
