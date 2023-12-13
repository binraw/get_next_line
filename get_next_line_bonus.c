/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:22:42 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/13 10:57:52 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line_bonus.h"

// size_t		cut_lign(char *str);
// size_t		ft_strlcpy(char *s1, char *s2, size_t n);
// char		*finaly_str(char *buffer, size_t len);
// void		*ft_memmove(void *dest, void *src, size_t n);
// char		*create_str(char **buffer, int fd);

// char	*get_next_line(int fd)
// {
// 	char			*finaly;
// 	char			*str;
// 	static char		buffer[1024][BUFFER_SIZE + 1] = "\0";
// 	size_t			len;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 	{
// 		len = 0;
// 		while (buffer[fd][len] != '\0')
// 			buffer[fd][len++] = '\0';
// 		return (NULL);
// 	}
// 	str = create_str(buffer[fd], fd);
// 	if (!str)
// 		return (NULL);
// 	len = 0;
// 	len = cut_lign(str);
// 	finaly = finaly_str(str, len);
// 	if (ft_strlen(str) != len)
// 		ft_memmove(buffer[fd], str + len + 1, ft_strlen(str) - cut_lign(str));
// 	else
// 		buffer[fd][0] = '\0';
// 	free(str);
// 	return (finaly);
// }

// char	*create_str(char **buffer, int fd)
// {
// 	char		*str;
// 	ssize_t		re;

// 	re = 1;
// 	str = ft_strdup(buffer[fd]);
// 	if (!str)
// 		return (NULL);
// 	while (re > 0)
// 	{
// 		re = read(fd, buffer[fd], BUFFER_SIZE);
// 		if (re != 0)
// 			buffer[fd][re] = '\0';
// 		if (re == 0 && buffer[fd][0] == '\0')
// 		{
// 			free(str);
// 			return (NULL);
// 		}
// 		if (re != 0)
// 			str = ft_strjoin(str, buffer[fd]);
// 		if (!str)
// 			return (NULL);
// 		if (ft_strchr(str, '\n'))
// 			break ;
// 	}
// 	return (str);
// }

// char	*finaly_str(char *buffer, size_t len)
// {
// 	char	*finaly;

// 	finaly = malloc((len + 2) * sizeof(char));
// 	if (!finaly)
// 		return (NULL);
// 	ft_strlcpy(finaly, buffer, len +1);
// 	if (ft_strlen(buffer) > len)
// 		finaly[len] = '\n';
// 	finaly[len + 1] = '\0';
// 	return (finaly);
// }

// void	*ft_memmove(void	*dest, void	*src, size_t	n)
// {
// 	size_t	i;

// 	if (!dest && !src)
// 		return (0);
// 	i = n - 1;
// 	if (dest > src)
// 	{
// 		while (n--)
// 		{
// 			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
// 			i--;
// 		}
// 		return (dest);
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i < n)
// 		{
// 			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
// 			i++;
// 		}
// 		return (dest);
// 	}
// }

// size_t	cut_lign(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != '\n' && str[i] != '\0')
// 		i++;
// 	return (i);
// }

// int main(void)
// {
//      int fd;
//      int i;
//      char *result;
//      i = 0;
//     // fd = open("fichier.txt", O_RDONLY);
//     // fd = open("read_error.txt", O_RDONLY);
//     // fd = open("multiple_line_no_nl", O_RDONLY);
//     // fd = open("multiple_nl.txt", O_RDONLY);
//     //  fd = open("test.txt", O_RDONLY);
//     // fd = open("41_no_nl", O_RDONLY);
//     fd = open("1char.txt", O_RDONLY);
//     // fd = open("null.txt", O_RDONLY);
//     while (i != 1)
//     {
//         result =  get_next_line(fd);
//         printf("%s", result);
//         i++;
//         free(result);
//     }
//     // free(get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	 close(fd);
// }