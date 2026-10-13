/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 15:59:41 by ambre             #+#    #+#             */
/*   Updated: 2026/10/03 14:29:42 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"
#include "game.h"
#include "parsing.h"
#include "error.h"

t_err	*file_valid_err(t_game *g, t_err *err_old, t_rbuf *file)
{
	t_err	*err;

	if (err_old != NULL)
	{
		free_dir(g);
		err = rbuf_close(file);
		if (err != NULL)
			return (err_wrap_fmt(err_old, err_loc(__FILE__, __LINE__),
					"couldn't close file"));
		return (err_old);
	}
	return (NULL);
}

t_err	*file_valid(t_game *g, char *path)
{
	t_rbuf	file;
	t_err	*err;

	err = rbuf_open(&file, path);
	if (err != NULL)
		return (err);
	err = recovering_info_befor_map(g, &file);
	err = file_valid_err(g, err, &file);
	if (err != NULL)
		return (err_wrap_fmt(err, err_loc(__FILE__, __LINE__),
				"file bad info"));
	err = map_valid(g, &file);
	err = file_valid_err(g, err, &file);
	if (err != NULL)
		return (err_wrap_fmt(err, err_loc(__FILE__, __LINE__), "map no valid"));
	return (rbuf_close(&file));
}
