/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:23:31 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/05 12:55:26 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include <unistd.h>

# define BUFFER_SIZE 1

char	*ft_strchr(const char *string, int searchedChar);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strdup(const char *source);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
#endif