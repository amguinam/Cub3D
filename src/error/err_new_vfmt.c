/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_new_vfmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:52:55 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

t_err	*err_new_vfmt(t_loc loc, const char *fmt, va_list	ap)
{
	return (err_wrap_vfmt(NULL, loc, fmt, ap));
}
