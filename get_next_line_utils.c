/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:46:52 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/11/30 15:47:51 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

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
