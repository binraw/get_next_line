/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:59:11 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/06 12:26:29 by rtruvelo         ###   ########.fr       */
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
    size_t		buflen;
    size_t		len;

    len = 1;
    str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!str)
        return (NULL);
    while ( len  > 0  && (!ft_strchr(str,'\n')))
    {
        len = read(fd, str, BUFFER_SIZE);
        str[len] = '\0';
        buffer = ft_strjoin(buffer,str);
    }
    len = 0;
    len = cut_lign(buffer);
    finaly = finaly_str(buffer, len);
    if(len == 0)
    {
        free(str);
        return ("(null)");
    }
    buflen = ft_strlen(buffer + len + 1);
    // if(!buffer)
    //     return ("(null)");
    buffer = ft_strjoin(NULL, buffer + len + 1);
	buffer[buflen] = '\0';
	     free(str);
    return (finaly);
}
// char *str_egaln(char *str)
// {
//     int i;

//     i = 0;
//     if (str[i] == '\n')
//         return ("\n");
//     return ("\n");
// }
char  *finaly_str(char *buffer, size_t len)
{
   char *finaly;
   int i;

   i = 0;
   
    finaly = ft_calloc(len + 1 , sizeof(char));
    if (!finaly)
        return (NULL);
    // if(!buffer)
    //     return ("(null)");
    ft_strlcpy(finaly, buffer, len + 1); // quand cest la derniere ligne rajoute le dernier carac en double ?
    if(!finaly)
        return ("(null)");
    finaly[len] = '\n';
    return (finaly);
}

size_t    cut_lign(char *str)
{
    size_t  i;

    i = 0;
 
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
    while (i != 500)
    {
        result =  get_next_line(fd);
        printf("%s", result);
        i++;
        // free(result);
    }
    // free(get_next_line(fd));
    
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
    
	 close(fd);
}
