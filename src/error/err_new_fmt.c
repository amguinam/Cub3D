/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_new_fmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:52:42 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

__attribute__ ((format (printf, 2, 3)))
t_err	*err_new_fmt(t_loc loc, const char *fmt, ...)
{
	t_err	*err;
	va_list	ap;

	va_start(ap, fmt);
	err = err_new_vfmt(loc, fmt, ap);
	va_end(ap);
	return (err);
}
