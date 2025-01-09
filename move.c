/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:38:31 by hugozlu           #+#    #+#             */
/*   Updated: 2025/01/03 11:36:12 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == 'C')
		game->coin--;
	else if (game->map[game->player_y -1][game->player_x] == 'E')
	{
		if (game->coin == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			finishscreen(game);
		}
		else
			return ;
	}
	if (game->map[game->player_y -1][game->player_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y -1][game->player_x] = 'P';
		game->player_y--;
		game->move += 1;
	}
}

void	move_s(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == 'C')
		game->coin--;
	else if (game->map[game->player_y + 1][game->player_x] == 'E')
	{
		if (game->coin == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			finishscreen(game);
		}
		else
			return ;
	}
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y + 1][game->player_x] = 'P';
		game->player_y++;
		game->move += 1;
	}
}

void	move_a(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == 'C')
		game->coin--;
	else if (game->map[game->player_y][game->player_x - 1] == 'E')
	{
		if (game->coin == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			finishscreen(game);
		}
		else
			return ;
	}
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x - 1] = 'P';
		game->player_x--;
		game->move += 1;
	}
}

void	move_d(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == 'C')
		game->coin--;
	else if (game->map[game->player_y][game->player_x + 1] == 'E')
	{
		if (game->coin == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			finishscreen(game);
		}
		else
			return ;
	}
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x + 1] = 'P';
		game->player_x++;
		game->move += 1;
	}
}

int	key_check(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 119 || keycode == 65362)
		move_w(game);
	else if (keycode == 97 || keycode == 65361)
		move_a(game);
	else if (keycode == 115 || keycode == 65364)
		move_s(game);
	else if (keycode == 100 || keycode == 65363)
		move_d(game);
	else
		return (0);
	print_tern(game);
	return (0);
}
