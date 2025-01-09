/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:29:44 by hugozlu           #+#    #+#             */
/*   Updated: 2025/01/02 12:06:42 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

int	ft_base(int content)
{
	if (content < 0)
	{
		ft_putchar('-');
		if (content == -2147483648)
			return (ft_turn(2147483648, "0123456789") + 1);
		content *= -1;
		return (ft_turn(content, "0123456789") + 1);
	}
	return (ft_turn(content, "0123456789"));
}

size_t	ft_strlen(const char *s)
{
	size_t	h;

	h = 0;
	while (s[h])
		h++;
	return (h);
}

int	ft_putstr(char *c)
{
	if (!c)
		return (ft_putstr("(null)"));
	return (write(1, c, ft_strlen(c)));
}

int	ft_turn(size_t data, char *base)
{
	static char	str[50];
	int			len;
	char		*ptr;

	len = ft_strlen(base);
	ptr = &str[49];
	*ptr = '\0';
	*--ptr = base[data % len];
	data = data / len;
	while (data != 0)
	{
		*--ptr = base[data % len];
		data = data / len;
	}
	return (ft_putstr(ptr));
}
