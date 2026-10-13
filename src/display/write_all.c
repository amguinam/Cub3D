/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 08:47:04 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:51:35 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	write_all(int fd, const char *data, size_t len)
{
	ssize_t	ret;
	size_t	written;

	written = 0;
	while (written < len)
	{
		ret = write(fd, &data[written], len - written);
		if (ret < 0)
			return (0);
		written += ret;
	}
	return (1);
}
