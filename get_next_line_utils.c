/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:46:52 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/08 11:06:41 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
char	*ft_strdup(const char *source);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *string, int searchedChar)
{
	size_t	i;
	char	*p;
	char	search;

	i = 0;
	p = (char *)string;
	search = (char)searchedChar;
	while (p[i] != '\0')
	{
		if (p[i] == search)
		{
			return (&p[i]);
		}
		i++;
	}
	if (p[i] == search)
	{
		return (&p[i]);
	}
	if (search == '\0')
		return (NULL);
	return (0);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*pointer;
	size_t	i;

	i = 0;
	if (!num || !size)
		return (malloc(0));
	if (SIZE_MAX / num < size)
		return (NULL);
	pointer = malloc(num * size);
	if (!pointer)
		return (NULL);
	while (i < (num * size))
	{
		pointer[i] = 0;
		i++;
	}
	return (pointer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	y;
	size_t	x;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1) + ft_strlen(s2);
	x = 0;
	y = 0;
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	while (s1[y] != '\0')
		dest[x++] = s1[y++];
	y = 0;
	while (s2[y] != '\0')
		dest[x++] = s2[y++];
	dest[x] = '\0';
	return (dest);
}
char	*ft_strdup(const char *source)
{
	size_t	i;
	size_t	y;
	char	*pointer;

	if (!source)
		return (NULL);
	y = 0;
	i = ft_strlen(source);
	pointer = malloc((i + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	while (y < i)
	{
		pointer[y] = source[y];
		y++;
	}
		// free((char*)source);
	 pointer[y] = '\0';
	return (pointer);
}



size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
        return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
