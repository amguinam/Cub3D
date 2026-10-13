/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:56:40 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "format.h"
#include "str.h"

__attribute__ ((format (printf, 2, 3)))
t_err	*fmt_format(t_string *self, const char *fmt, ...)
{
	va_list	ap;
	t_err	*err;

	va_start(ap, fmt);
	err = fmt_vformat(self, fmt, ap);
	va_end(ap);
	return (err);
}
