/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_wrap_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:53:28 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

__attribute__ ((format (printf, 3, 4)))
t_err	*err_wrap_fmt(t_err *inner, t_loc loc, const char *fmt, ...)
{
	t_err	*err;
	va_list	ap;

	va_start(ap, fmt);
	err = err_wrap_vfmt(inner, loc, fmt, ap);
	va_end(ap);
	return (err);
}
