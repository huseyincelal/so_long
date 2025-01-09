/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:29:55 by hugozlu           #+#    #+#             */
/*   Updated: 2024/11/05 16:14:39 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char a);
int		ft_putstr(char *c);
int		ft_type_control(const char c, va_list list);
int		ft_turn(size_t data, char *base);
int		ft_base(int content);

size_t	ft_strlen(const char *s);

#endif
