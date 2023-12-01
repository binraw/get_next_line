/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:59:11 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/11/30 17:23:05 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char    *str;
    char    *finaly;
    size_t     len;

    str = ft_calloc(BUFFER_SIZE, sizeof(char));
    read(fd, str , BUFFER_SIZE);
    len = cut_lign(str);
    finaly = malloc(len + 1 * sizeof(char));
    
    return (str);
}

size_t    cut_lign(char *str)
{
    size_t  len;
    size_t  i;

    len = 0;
    i = 0;
    if (ft_strchr(str, "\n") != 0)
    {
        while(str[i] != '\n')
        {
            i++;
        }   
    }
    return (i);
}

int main(void)
{
     int fd;
    // char buff[1024];
    // read(1, buff, 1024);
    
    fd = open("fichier.txt", O_RDONLY);
//    get_next_line(fd);
    printf("%s\n", get_next_line(fd));
}
