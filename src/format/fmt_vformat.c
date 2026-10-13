/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_vformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:56:57 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>

#include "error.h"
#include "format.h"
#include "str.h"

/// Look for the next format specifier and return a pointer to the rest of the
/// string or `NULL` if the end is reached.
static const char	*next_spec(const char *fmt, t_spec *spec)
{
	spec->prev.data = (char *)fmt;
	spec->prev.len = 0;
	while (fmt[spec->prev.len] != '\0' && fmt[spec->prev.len] != '%')
		spec->prev.len++;
	if (fmt[spec->prev.len] == '\0')
		return (spec->spec = SPEC_DONE, NULL);
	if (fmt[spec->prev.len + 1] == 's')
		return (spec->spec = SPEC_STR, &fmt[spec->prev.len + 2]);
	if (fmt[spec->prev.len + 1] == 'c')
		return (spec->spec = SPEC_CHAR, &fmt[spec->prev.len + 2]);
	return (spec->spec = SPEC_PERCENT, &fmt[spec->prev.len + 1]);
}

t_err	*fmt_vformat(t_string *self, const char *fmt, va_list ap)
{
	t_err	*err;
	t_spec	spec;

	while (fmt)
	{
		fmt = next_spec(fmt, &spec);
		err = string_push_str(self, spec.prev);
		if (err != NULL)
			return (err);
		if (spec.spec == SPEC_DONE)
			break ;
		if (spec.spec == SPEC_STR)
			err = string_push_str(self, str_from_cstr(va_arg(ap, char *)));
		if (spec.spec == SPEC_CHAR)
			err = string_push_char(self, (char)va_arg(ap, int));
		else if (spec.spec == SPEC_PERCENT)
			err = string_push_char(self, '%');
		if (err != NULL)
			return (err_wrap_fmt(err, err_loc(__FILE__, __LINE__),
					"could't format item"));
	}
	return (NULL);
}
