/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:59:11 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/01 13:37:25 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t    cut_lign(char *str);

char *get_next_line(int fd)
{
    char		*str;
    char		*finaly;
    static char	buffer[BUFFER_SIZE];
    size_t		len;
	size_t		buflen;
	
    str = ft_calloc(BUFFER_SIZE, sizeof(char));
    read(fd, str , BUFFER_SIZE);
	ft_strlcpy(str, str + ft_strlen(buffer),BUFFER_SIZE - ft_strlen(buffer));
    len = cut_lign(str);
    finaly = malloc(len + 1 * sizeof(char));
    ft_strlcpy(finaly,str,len);
	finaly[len] = '\0';
	buflen = ft_strlen(str + len + 1);
	ft_strlcpy(buffer,str + len + 1, buflen);
	buffer[buflen] = '\0';
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
        while(str[i] != '\n')
            i++;  
    }
    return (i);
}

int main(void)
{
     int fd;
    
    fd = open("fichier.txt", O_RDONLY);

    printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	 close(fd);
}
