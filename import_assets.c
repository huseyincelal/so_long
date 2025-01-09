/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:49:06 by hugozlu           #+#    #+#             */
/*   Updated: 2025/01/03 07:00:17 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_import_other(t_game *game)
{
	int	w;
	int	h;

	game->floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			&w, &h);
	if (game->floor == NULL)
		handle_error("xpm error floor", game, 1);
	game->coin_m = mlx_xpm_file_to_image(game->mlx, "assets/coin.xpm", &w, &h);
	if (game->coin_m == NULL)
		handle_error("xpm error coin", game, 1);
	game->exit_m = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm",
			&w, &h);
	if (game->exit_m == NULL)
		handle_error("xpm error exit", game, 1);
	game->wall = mlx_xpm_file_to_image(game->mlx, "assets/Wall.xpm",
			&w, &h);
	if (game->wall == NULL)
		handle_error("xpm error wall", game, 1);
}

void	assets_import(t_game *game)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	game->player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
			&w, &h);
	if (game->player == NULL)
		handle_error("xpm error player", game, 1);
	assets_import_other(game);
}
