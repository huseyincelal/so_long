/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:52:29 by hugozlu           #+#    #+#             */
/*   Updated: 2025/01/02 12:04:07 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_arry(char *back, int a, int backlen)
{
	long	n;

	n = a;
	if (n < 0)
	{
		back[0] = '-';
		n *= -1;
	}
	if (n >= 10)
	{
		ft_arry(back, n / 10, backlen - 1);
		ft_arry(back, n % 10, backlen);
	}
	if (n < 10)
		back[backlen] = n + 48;
}

int	step(int n)
{
	long	a;
	int		i;

	i = 0;
	a = n;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		a *= -1;
		i++;
	}
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		backlen;
	char	*back;

	backlen = step(n);
	back = malloc((sizeof(char) * backlen) + 1);
	if (!back)
		return (0);
	ft_arry(back, n, backlen - 1);
	back[backlen] = '\0';
	return (back);
}
