/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:29:54 by hugozlu           #+#    #+#             */
/*   Updated: 2025/01/03 11:52:53 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "libs/ft_printf/ft_printf.h"
# include "libs/get_next_line/get_next_line.h"

# define RED "\033[31m"

typedef struct game
{
	void	*win;
	void	*mlx;
	int		move;
	int		coin;
	int		exit;
	int		map_x;
	int		map_y;
	char	**map;
	void	*wall;
	int		error;
	void	*floor;
	int		exit_x;
	int		exit_y;
	void	*coin_m;
	void	*player;
	void	*exit_m;
	int		player_c;
	int		player_x;
	int		player_y;
	char	**map_clone;
}	t_game;

char	*ft_itoa(int n);
void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	free_map(t_game *game);
int		mapcheck(t_game *game);
void	wall_check(t_game *game);
void	print_tern(t_game *game);
char	**clonemap(t_game *game);
int		close_window(t_game *game);
char	*ft_strdup(const char *s1);
void	finishscreen(t_game *game);
void	assets_import(t_game *game);
void	assets_import(t_game *game);
void	map(char *folder, t_game *cordinat);
int		key_check(int keycode, t_game *game);
void	free_clone(char **map_clone, int map_y);
void	map_linecheck(char *folder, t_game *game);
void	map_import_window(t_game *game, int x, int y);
int		roadcheck(int x, int y, char **map, t_game *game);
void	objects(char object, t_game *game, int map_c, int p_x);
int		handle_error(const char *msg, t_game *game, int free_check);
char	**fullmap_import(char *folder, char **fullmap, t_game *game);

#endif
