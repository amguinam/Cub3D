/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:33:31 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:40:29 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! File utilities

#ifndef FILESYSTEM_H
# define FILESYSTEM_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# include "error_forward.h"

/// An open file.
typedef struct s_file
{
	/// File descriptor.
	int	fd;
}	t_file;

/// Opens a file for reading.
t_err	*file_open(t_file *self, const char *path);

/// Reads some data from the file.
t_err	*file_read(t_file *self, uint8_t *buf, size_t *len);

/// Closes the file.
t_err	*file_close(t_file *self);

# define RBUF_SIZE	4096

/// A bufferized file reader.
typedef struct s_rbuf
{
	/// Actual file.
	t_file	file;
	/// Buffer data.
	uint8_t	buf[RBUF_SIZE];
	/// How many bytes have been consumed from the buffer.
	size_t	read;
	/// How many bytes are present in the buffer.
	size_t	write;
}	t_rbuf;

/// Opens a file and creates a reader.
t_err	*rbuf_open(t_rbuf *self, const char *path);

/// Fills the buffer with data from the file. `eof` is set to `true` if
/// end-of-file is reached.
t_err	*rbuf_fill(t_rbuf *self, bool *eof);

/// Reads exactly the required number of bytes or return an error.
t_err	*rbuf_read_exact(t_rbuf *self, void *b, size_t len);

/// Tries to read a single byte. `eof` is set to `true` and `b` is not set if
/// end-of-file is reached.
t_err	*rbuf_try_read_byte(t_rbuf *self, uint8_t *b, bool *eof);

/// Closes the reader.
t_err	*rbuf_close(t_rbuf *self);

#endif
