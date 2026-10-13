/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 11:13:29 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/12 08:47:26 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "error.h"
#include "str.h"

static void	put_nbr(int fd, size_t n)
{
	char	c;

	if (n >= 10)
		put_nbr(fd, n / 10);
	c = '0' + (n % 10);
	write_all(fd, &c, 1);
}

static void	put_msg(int fd, const t_err *err)
{
	if (err->message.data != NULL)
		write_all(fd, err->message.data, err->message.len);
}

static void	put_loc(int fd, const t_err *err)
{
	if (err->loc.file && err->loc.line > 0)
	{
		write_all(fd, " [", 2);
		write_all(fd, err->loc.file, ft_strlen(err->loc.file));
		write_all(fd, ":", 1);
		put_nbr(fd, err->loc.line);
		write_all(fd, "]", 1);
	}
}

static void	err_display(const t_err *err, int fd)
{
	size_t	index;

	write_all(fd, "Error\n", 6);
	put_msg(fd, err);
	put_loc(fd, err);
	write_all(fd, "\n", 1);
	err = err->next;
	if (err)
		write_all(fd, "Caused by:\n", 11);
	index = 0;
	while (err)
	{
		write_all(fd, "  ", 2);
		put_nbr(fd, index);
		write_all(fd, ": ", 2);
		put_msg(fd, err);
		put_loc(fd, err);
		write_all(fd, "\n", 1);
		err = err->next;
		index++;
	}
}

int	main(int argc, char **argv)
{
	t_err	*err;

	err = load_cub(argc, argv);
	if (err != NULL)
	{
		err_display(err, 2);
		err_free(err);
		return (1);
	}
	return (0);
}
