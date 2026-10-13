/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:41:15 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! String utilities

#ifndef STR_H
# define STR_H

# include <stddef.h>

# include "error_forward.h"

/// A string slice.
typedef struct s_str
{
	/// A pointer to the strings data.
	char	*data;
	/// The string slice length in bytes.
	size_t	len;
}	t_str;

/// Copies `len` bytes from `src` into `dst` (see `memcpy`).
void	ft_memcpy(void *dst, const void *src, size_t len);

/// Count the numbers of bytes before the terminating `\0` byte (see `strlen`).
size_t	ft_strlen(const char *self);

/// Creates a string slice from a nul-terminated C-string.
t_str	str_from_cstr(char *str);

/// Releases ressources allocated for the string slice.
///
/// # Warning
///
/// Only use this function if the string slice is dynamically allocated.
void	str_free(t_str *self);

/// A nul-terminated string.
///
/// If `len > cap` then the string is not heap allocated.
typedef struct s_string
{
	/// A pointer to the strings data.
	char	*data;
	/// Strings length in bytes.
	size_t	len;
	/// Strings total capacity in bytes.
	size_t	cap;
}	t_string;

/// Initializes a new string.
void	string_new(t_string *self);

/// Duplicates a string slice into a new string.
t_err	*string_from_str(t_string *self, t_str str);

/// Duplicates a C-string into a new string.
t_err	*string_from_cstr(t_string *self, const char *cstr);

/// Adds a char to the end of the string.
t_err	*string_push_char(t_string *self, char c);

/// Adds a string slice to the end of the string.
t_err	*string_push_str(t_string *self, t_str str);

/// Releases ressources allocated to the string.
void	string_free(t_string *self);

#endif
