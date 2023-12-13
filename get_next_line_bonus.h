/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:25:46 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/13 16:24:28 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1000

# endif

char		*get_next_line(int fd);
char		*ft_strchr( char *string, int searchedChar);
char		*ft_strdup( char *source);
char		*ft_strjoin(char	*s1, char	*s2);
size_t		ft_strlen( char *str);
#endif