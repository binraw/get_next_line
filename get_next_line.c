/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:59:11 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/11 17:15:34 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t    cut_lign(char *str);
size_t	ft_strlcpy(char *s1,  char *s2, size_t n);
char  *finaly_str(char *buffer, size_t len);
void	*ft_memmove(void *dest, void *src, size_t n);


char *get_next_line(int fd)
{
    char		*finaly;
    static char	buffer[BUFFER_SIZE + 1] = "\0";
    size_t		len;
    size_t      i;
    size_t      y;

    len = 1;
    i = 0;
    y = 0;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0)
        return (NULL);
    finaly = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!finaly)
        return (NULL);
    while (len > 0)
    {
        len = read(fd, buffer, BUFFER_SIZE);
        buffer[len] = '\0';
        
        if (len == 0 && finaly[0] == '\0')
        {
            free(finaly);
            return (NULL);
        }
        finaly = ft_strjoin(finaly, buffer);
        if (ft_strchr(buffer,'\n'))
            break ;
    }
    len = 0;
    len = cut_lign(buffer);
    while (i < len)
        finaly[i++] = buffer[y++];
    ft_memmove(buffer,buffer + len, ft_strlen(buffer + len));
    return (finaly);
}

char  *finaly_str(char *buffer, size_t len)
{
   char *finaly;
   
    finaly = ft_calloc(len + 2 , sizeof(char));
    if (!finaly)
        return (NULL);
    ft_strlcpy(finaly, buffer, len + 1);
    if(ft_strlen(buffer) > len)
    finaly[len] = '\n';
    return (finaly);
}
void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = n - 1;
	if (dest > src)
	{
		while (n--)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i--;
		}
		return (dest);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
		return (dest);
	}
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
size_t	ft_strlcpy(char *s1, char *s2, size_t n)
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
    // fd = open("multiple_line_no_nl", O_RDONLY);
    // fd = open("multiple_nl.txt", O_RDONLY);
    //  fd = open("test.txt", O_RDONLY);
    // fd = open("41_no_nl", O_RDONLY);
    // fd = open("1char.txt", O_RDONLY);
    // fd = open("null.txt", O_RDONLY);
    while (i != 3)
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
