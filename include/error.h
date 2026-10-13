/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:39:48 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdarg.h>
# include <stddef.h>

# include "str.h"
# include "error_forward.h"

/// A location in the source code
typedef struct s_err_loc
{
	/// Source file name.
	const char	*file;
	/// Line in the source file.
	int			line;
}	t_loc;

/// Represents an error report
///
/// Errors can be wrapped with some context.
struct s_err
{
	/// Formatted error message.
	t_string		message;
	/// Location in the code where the error occurred.
	t_loc			loc;
	/// Inner error if any.
	struct s_err	*next;
};

/// An error for when errors cannot be allocated.
t_err	*err_oom(t_loc loc);

/// Creates a new error with given formatted message.
t_err	*err_new_fmt(t_loc loc, const char *fmt, ...);

/// Creates a new error with given formatted message.
t_err	*err_new_vfmt(t_loc loc, const char *fmt, va_list ap);

/// Wraps an error with given context.
t_err	*err_wrap_fmt(t_err *inner, t_loc loc, const char *fmt, ...);

/// Wraps an error with given context.
t_err	*err_wrap_vfmt(t_err *inner, t_loc loc, const char *fmt, va_list ap);

/// Releases ressources allocated for the error.
void	err_free(t_err *self);

/// Returns a location with the given file/line.
t_loc	err_loc(const char *file, int line);

#endif
