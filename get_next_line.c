/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:59:11 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/04 16:40:07 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t    cut_lign(char *str);
size_t	ft_strlcpy(char *s1, const char *s2, size_t n);

char *get_next_line(int fd)
{
    char		*str;
    char		*finaly;
    static char	*buffer;
    size_t		len;
	size_t		buflen;

    str = ft_calloc(BUFFER_SIZE, sizeof(char));
    read(fd, str , BUFFER_SIZE);
	str = ft_strjoin(str, buffer);
    len = cut_lign(str);
    printf("%d", len);
    finaly = malloc(len + 1 * sizeof(char));
    ft_strlcpy(finaly,str,len);
	finaly[len + 1] = '\0';
	buflen = ft_strlen( str + len + 1);
    // printf("%d", buflen);
	buffer = ft_strjoin(buffer,str + len + 1);

	buffer[buflen + 1] = '\0';
	free(str);
    return (finaly);
}

size_t    cut_lign(char *str)
{
    size_t  len;
    size_t  i;

    len = 0;
    i = 0;
    if (ft_strchr(str, '\n') != 0)
    {
        while(str[i] != '\n' && str[i] != '\0')
            i++;
    }
    return (i);
}
size_t	ft_strlcpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (s2[i] != '\0' && i < (n - 1))
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = 0;
	}
	while (s2[i] != '\0')
		i++;
	return (i);
}


int main(void)
{
     int fd;
     int i;

     i = 0;
    
    fd = open("fichier.txt", O_RDONLY);
    while (i != 4)
    {
        printf("%s\n", get_next_line(fd));
        i++;
    }
    // free(get_next_line(fd));
    
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	 close(fd);
}
