/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 07:55:18 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:50:59 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"
#include "ft_memory.h"

// Allocates and returns a string extracted from str. It begins at index start
// and its max size is len.
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	newstr_size;
	size_t	i_newstr;
	size_t	str_size;

	i_newstr = 0;
	str_size = ft_strlen(str);
	if (start >= str_size)
		newstr_size = 0;
	else if (start + len <= str_size)
		newstr_size = len;
	else
		newstr_size = str_size - start;
	newstr = ft_calloc((newstr_size + 1), sizeof(char));
	if (!newstr)
		return (NULL);
	while (i_newstr < newstr_size)
	{
		newstr[i_newstr] = str[start];
		i_newstr++;
		start++;
	}
	return (newstr);
}
