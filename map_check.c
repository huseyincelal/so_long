/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:39:25 by hugozlu           #+#    #+#             */
/*   Updated: 2025/01/03 06:58:40 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	roadcheck(int x, int y, char **map, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map_x || y >= game->map_y
		|| map[y][x] == '\0' || map[y][x] == '1' || map[y][x] == 'M'
		|| map[y][x] == '\n')
		return (0);
	if (game->coin == 0 && game->exit == 0)
		return (1);
	if (map[y][x] == 'C')
		game->coin--;
	if (map[y][x] == 'E')
		game->exit--;
	map[y][x] = 'M';
	if (roadcheck(x + 1, y, map, game)
		|| roadcheck(x - 1, y, map, game)
		|| roadcheck(x, y + 1, map, game)
		|| roadcheck(x, y - 1, map, game))
	{
		return (1);
	}
	return (0);
}

void	wall_check(t_game *game)
{
	int		i;
	char	**map;

	map = game->map;
	i = 0;
	if (game->error != 0)
		handle_error("error,unknown object", game, 1);
	while (map[0][i] != '\n' || map[game->map_y - 2][i] != '\n')
	{
		if (map[game->map_y - 1][i] == '1' && map[0][i] == '1'
		&& (ft_strlenn(map[0]) - 1) == game->map_x
		&& game->map_x == ft_strlenn(game->map[game->map_y - 1]))
			i++;
		else
			handle_error("The map is not walled or rectangular!", game, 1);
	}
	i = 1;
	while (i < game->map_y - 1)
	{
		if (map[i][0] == '1' && map[i][game->map_x - 1] == '1'
			&& (ft_strlenn(map[i]) - 1) == game->map_x)
			i++;
		else
			handle_error("The map is not walled or rectangular.", game, 1);
	}
}

void	objects(char object, t_game *game, int map_c, int p_x)
{
	if (object == 'P')
	{
		game->player_c++;
		game->player_x = p_x;
		game->player_y = map_c;
	}
	else if (object == 'C')
		game->coin++;
	else if (object == 'E')
	{
		game->exit++;
		game->exit_x = p_x + 1;
		game->exit_y = map_c + 1;
	}
	else if (object != '0' && object != '1'
		&& object != '\n' && object != '\0')
		game->error++;
}

void	map_linecheck(char *folder, t_game *game)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	fd = open(folder, O_RDONLY);
	if (fd == -1)
		handle_error("error, can't open file", game, 0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		y++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	game->map_y = y;
}
