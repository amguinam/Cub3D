/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:39:18 by ambre             #+#    #+#             */
/*   Updated: 2026/10/11 10:35:03 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <stddef.h>

#include "game.h"
#include "mlx.h"
#include "error.h"

static void	init_game_state(t_game *game)
{
	game->mlx = NULL;
	game->window.window = NULL;
	game->image.image = NULL;
	game->map.cell = NULL;
	game->rays = NULL;
	init_images(game);
	game->pos.y = -1;
	game->pos.x = -1;
}

static t_err	*file(t_game *game, int argc, char **argv)
{
	t_err	*err;

	if (argc != 2)
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"invalid arguments"));
	err = file_name_valid(argv[1]);
	if (err != NULL)
		return (err);
	err = file_valid(game, argv[1]);
	if (err != NULL)
		return (err);
	return (NULL);
}

static t_err	*creat(t_game *game)
{
	t_err	*err;

	err = creat_window(game);
	if (err != NULL)
		return (err);
	err = creat_image(game);
	if (err != NULL)
		return (err);
	err = creat_rays(game);
	if (err != NULL)
		return (err);
	return (NULL);
}

static void	loop_game(t_game *game)
{
	gettimeofday(&game->last_frame_tv, NULL);
	mlx_loop_hook(game->mlx, (void *)loop_hook, game);
	mlx_hook(game->window.window, KeyPress, KeyPressMask,
		(void *)key_hook, game);
	mlx_hook(game->window.window, KeyRelease, KeyReleaseMask,
		(void *)key_release_hook, game);
	mlx_hook(game->window.window, DestroyNotify, StructureNotifyMask,
		(void *)destroy_hook, game);
	mlx_loop(game->mlx);
	free_game(game);
}

t_err	*load_cub(int argc, char **argv)
{
	t_err	*err;
	t_game	game;

	init_game_state(&game);
	err = file(&game, argc, argv);
	if (err != NULL)
		return (err);
	err = creat(&game);
	if (err != NULL)
	{
		free_game(&game);
		return (err);
	}
	err = load_game(&game);
	if (err != NULL)
	{
		free_game(&game);
		return (err);
	}
	loop_game(&game);
	return (NULL);
}
