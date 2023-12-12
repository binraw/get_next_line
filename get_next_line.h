/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:23:31 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/12 16:27:51 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10

# endif

char		*get_next_line(int fd);
char		*ft_strchr( char *string, int searchedChar);
char		*ft_strdup( char *source);
char		*ft_strjoin(char	*s1, char	*s2);
size_t		ft_strlen( char *str);
size_t		ft_strlcpy(char *s1, char *s2, size_t n);
#endif