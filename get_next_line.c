/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:59:11 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/07 16:14:58 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t    cut_lign(char *str);
size_t	ft_strlcpy(char *s1, const char *s2, size_t n);
char  *finaly_str(char *buffer, size_t len);


char *get_next_line(int fd)
{
    char		*str;
    char		*finaly;
    static char	*buffer;
    char		*temp;
    size_t		len;

    len = 1;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0)
        return (NULL);
    if (!buffer)
    {
        buffer = ft_calloc(1,1);
        buffer[0] = '\0';
    }
    str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!str)
        return (NULL);
    while ( len  != 0  && (!ft_strchr(str,'\n')))
    {
        len = read(fd, str, BUFFER_SIZE);
        // if (len > 0)
        if (len == -1)
        {
            free(str);
            return (NULL);
        }
            str[len] = '\0';
        
        temp = ft_strjoin(buffer, str);
        free(buffer);
        buffer = ft_strdup(temp);
        free(temp);
        // buffer = ft_strdup(temp);
        // free(temp);
    }
    len = 0;
    len = cut_lign(buffer);
    finaly = finaly_str(buffer, len);
    if (len > 0)
        buffer = ft_strdup(buffer + len + 1);
    else
    {
        free(buffer);
    }
	free(str);
    return (finaly);
}

char  *finaly_str(char *buffer, size_t len)
{
   char *finaly;
   
    finaly = ft_calloc(len + 2 , sizeof(char));
    if (!finaly)
        return (NULL);
    ft_strlcpy(finaly, buffer, len + 1);
    // finaly[len + 1] = '\0';
 
    if(ft_strlen(buffer) > len)
    finaly[len] = '\n';
    return (finaly);
}

size_t    cut_lign(char *str)
{
    size_t  i;

    i = 0;
    if (!str)
        return (0);
    while(str[i] != '\n' && str[i] != '\0')
         i++;
    
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
     char *result;

     i = 0;
    
    fd = open("fichier.txt", O_RDONLY);
    // fd = open("null.txt", O_RDONLY);
    while (i != 6)
    {
        result =  get_next_line(fd);
        printf("%s", result);
        i++;
        free(result);
    }
    // free(get_next_line(fd));
    
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
    
	 close(fd);
}
