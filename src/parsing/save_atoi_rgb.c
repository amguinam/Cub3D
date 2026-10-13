/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_atoi_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:44:54 by ambre             #+#    #+#             */
/*   Updated: 2026/10/10 13:46:33 by Srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "filesystem.h"
#include "parsing.h"
#include "error.h"
#include "str.h"

static t_err	*ft_atoi_unsigned_char(uint8_t *c, t_rbuf *file,
	uint8_t c_final, int *color)
{
	bool	eof;
	t_err	*err;

	while (1)
	{
		if (*c >= '0' && *c <= '9')
			*color = (*color * 10) + (*c - '0');
		if (*color > 255)
			return (err_new_fmt(err_loc(__FILE__, __LINE__),
					"color > max char"));
		err = rbuf_try_read_byte(file, c, &eof);
		if (err != NULL)
			return (err);
		if (eof || *c == c_final)
			return (NULL);
		if (*c == ' ')
			break ;
		if (*c < '0' || *c > '9')
			return (err_new_fmt(err_loc(__FILE__, __LINE__),
					"%c is not number", *c));
	}
	if (while_is_space(file, c) || *c != c_final)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"bad separation"));
	return (NULL);
}

static t_err	*save_atoi_r(t_game *g, uint8_t *c, t_rbuf *file, t_type *type)
{
	int		color;
	t_err	*err;

	color = 0;
	err = ft_atoi_unsigned_char(c, file, ',', &color);
	if (err != NULL)
		return (err);
	if (type->floor == true)
		g->texture.floor.r = color;
	else
		g->texture.sky.r = color;
	if (while_is_space(file, c))
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"fail read space"));
	return (NULL);
}

static t_err	*save_atoi_g(t_game *g, uint8_t *c, t_rbuf *file, t_type *type)
{
	int		color;
	t_err	*err;

	color = 0;
	err = ft_atoi_unsigned_char(c, file, ',', &color);
	if (err != NULL)
		return (err);
	if (type->floor == true)
		g->texture.floor.g = color;
	else
		g->texture.sky.g = color;
	if (while_is_space(file, c))
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"fail read space"));
	return (NULL);
}

static t_err	*save_atoi_b(t_game *g, uint8_t *c, t_rbuf *file, t_type *type)
{
	int		color;
	t_err	*err;

	color = 0;
	err = ft_atoi_unsigned_char(c, file, '\n', &color);
	if (err != NULL)
		return (err);
	if (type->floor == true)
		g->texture.floor.b = color;
	else
		g->texture.sky.b = color;
	return (NULL);
}

t_err	*save_atoi_rgb(t_game *g, uint8_t *c, t_rbuf *file, t_type *type)
{
	t_err	*err;

	err = save_atoi_r(g, c, file, type);
	if (err != NULL)
		return (err);
	err = save_atoi_g(g, c, file, type);
	if (err != NULL)
		return (err);
	err = save_atoi_b(g, c, file, type);
	if (err != NULL)
		return (err);
	return (NULL);
}
