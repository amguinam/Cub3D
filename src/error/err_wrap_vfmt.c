/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_wrap_vfmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:53:42 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "error.h"
#include "format.h"

t_err	*err_wrap_vfmt(t_err *inner, t_loc loc, const char *fmt, va_list ap)
{
	t_err	*err;
	t_err	*err2;

	err = malloc(sizeof(*err));
	if (err == NULL)
		return (err_oom(err_loc(__FILE__, __LINE__)));
	err->loc = loc;
	string_new(&err->message);
	err2 = fmt_vformat(&err->message, fmt, ap);
	if (err2 != NULL)
		return (err_wrap_fmt(err2, err_loc(__FILE__, __LINE__),
				"couldn't format error"));
	err->next = inner;
	return (err);
}
