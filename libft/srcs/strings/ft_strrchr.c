/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:45:17 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:49:58 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"

// Returns a pointer to the last occurrence of the character c in the string s.
char	*ft_strrchr(const char *str, int character)
{
	size_t	i;

	i = ft_strlen(str);
	if ((char)character == 0)
		return ((char *)str + i);
	else if (i == 0)
		return (NULL);
	else
	{
		while (i > 0)
		{
			i--;
			if (str[i] == (char)character)
				return ((char *)str + i);
		}
		return (NULL);
	}
}
