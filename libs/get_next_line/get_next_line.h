/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugozlu <hugozlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:59:24 by hugozlu           #+#    #+#             */
/*   Updated: 2025/01/02 11:57:40 by hugozlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

char	*new(char *str);
char	*line(char *str);
char	*get_next_line(int fd);
int		ft_strlenn(char const *s);
char	*ft_strchr(char *s, int c);
char	*join(char *s1, char *s2);

#endif