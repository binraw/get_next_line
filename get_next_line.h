/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:23:31 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/01 13:05:08 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

# define BUFFER_SIZE 1000

char	*ft_strchr(const char *string, int searchedChar);
void	*ft_calloc(size_t num, size_t size);
size_t	ft_strlcpy(char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
#endif