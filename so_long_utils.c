/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:30:57 by hugozlu           #+#    #+#             */
/*   Updated: 2025/01/02 12:38:13 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finishscreen(t_game *game)
{
	ft_printf("\033[1;32m");
	ft_printf("*************************************************\n");
	ft_printf("*                                               *\n");
	ft_printf("              * \033[1;33mCongratulations\033[1;32m *\n");
	ft_printf("*                                               *\n");
	ft_printf("*                                               *\n");
	ft_printf("*************************************************\n");
	ft_printf("\033[0m");
	close_window(game);
}

int	handle_error(const char *msg, t_game *game, int free_check)
{
	ft_printf("%s%s\033[0m\n", RED, msg);
	if (free_check == 1)
		free_map(game);
	exit (EXIT_FAILURE);
	return (0);
}

void	print_tern(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_y)
		ft_printf("\033[32m%s\033[0m", game->map[i++]);
	ft_printf("\n\033[34mMove %d Coin %d\033[0m\n", game->move, game->coin);
}
