/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:40:48 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Formatting utilities

#ifndef FORMAT_H
# define FORMAT_H

# include <stdarg.h>

# include "str.h"

/// Type of format specifier.
enum e_spec
{
	/// No specifier found.
	SPEC_DONE,
	/// String (%s).
	SPEC_STR,
	/// Char (%c).
	SPEC_CHAR,
	/// Percent (%%).
	SPEC_PERCENT,
};

/// Represents a parsed format specifier.
typedef struct s_spec
{
	/// String before the specifier.
	t_str		prev;
	/// Specifiers type.
	enum e_spec	spec;
}	t_spec;

/// Formats a string (see `fmt_vformat` for details).
t_err	*fmt_format(t_string *self, const char *fmt, ...);

/// Formats a string using the provided format and items. The resulting string
/// will be appended to the end the of string.
///
/// # Warning
///
/// Only `%s` is currently supported.
t_err	*fmt_vformat(t_string *self, const char *fmt, va_list ap);

#endif
