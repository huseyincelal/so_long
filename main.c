/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:40:15 by hugozlu           #+#    #+#             */
/*   Updated: 2025/01/02 16:35:53 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mapcheck(t_game *game)
{
	int		coin;

	coin = game->coin;
	if (game->coin < 1)
		handle_error("Wrong map,no coin", game, 1);
	if (game->player_c != 1)
		handle_error("error, the number of players is not 1", game, 1);
	game->map_clone = clonemap(game);
	wall_check(game);
	if (game->exit != 1)
		handle_error("Wrong map, no exit", game, 1);
	if (roadcheck(game->player_x, game->player_y, game->map_clone, game) == 0)
		return (handle_error("error, exit or coin path is closed", game, 1));
	free_clone(game->map_clone, game->map_y);
	game->coin = coin;
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit (0);
}

int	game_loop(t_game *game)
{
	map_import_window(game, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.player_c = 0;
	if (ac == 2)
		map(av[1], &game);
	else
		handle_error("Wrong argument, please select map.", &game, 0);
	mapcheck(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		handle_error("Failed to initialize MinilibX.\n", &game, 1);
	game.win = mlx_new_window(game.mlx, (game.map_x * 32),
			(game.map_y * 32), "So Long");
	if (game.win == NULL)
		handle_error("failed to create window", &game, 1);
	assets_import(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, key_check, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
