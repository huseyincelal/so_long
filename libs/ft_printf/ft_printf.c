/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:29:52 by hugozlu           #+#    #+#             */
/*   Updated: 2024/11/06 07:53:01 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_control(const char c, va_list list)
{
	unsigned long	ptr;

	if (c == 'd' || c == 'i')
		return (ft_base(va_arg(list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (c == 'p')
	{
		ptr = va_arg(list, unsigned long);
		if (ptr == 0)
			return (ft_putstr("(nil)"));
		ft_putstr("0x");
		return (ft_turn(ptr, "0123456789abcdef") + 2);
	}
	else if (c == 'u')
		return (ft_turn(va_arg(list, unsigned int), "0123456789"));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'x')
		return (ft_turn(va_arg(list, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_turn(va_arg(list, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		j;

	va_start(list, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (j);
			j += ft_type_control(str[i + 1], list);
			i++;
		}
		else
			j += write(1, &str[i], 1);
		i++;
	}
	va_end(list);
	return (j);
}
