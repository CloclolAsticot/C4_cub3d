/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:49:26 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:45:55 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// Returns a pointer to the first occurrence of the character in the string str.
char	*ft_strchr(const char *str, int character)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)character)
			return ((char *)str + i);
		i++;
	}
	if ((char)character == 0)
		return ((char *)str + i);
	else
		return (NULL);
}
