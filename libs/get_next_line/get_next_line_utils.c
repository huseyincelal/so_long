/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:59:13 by hugozlu           #+#    #+#             */
/*   Updated: 2025/01/02 11:57:00 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char *str, char *buffer)
{
	int		i;
	int		j;
	char	*res;

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	i = 0;
	j = 0;
	res = malloc(ft_strlenn(str) + ft_strlenn(buffer) + 1);
	if (res == NULL)
		return (NULL);
	while (str[j])
	{
		res[j] = str[j];
		j++;
	}
	while (buffer[i])
		res[j++] = buffer[i++];
	res[ft_strlenn(str) + ft_strlenn(buffer)] = '\0';
	free(str);
	return (res);
}

int	ft_strlenn(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*line(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	ptr = malloc(i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*new(char *str)
{
	int		j;
	int		i;
	char	*res;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	res = malloc((ft_strlenn(str) - i) + 1);
	if (!res)
		return (NULL);
	i++;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}
