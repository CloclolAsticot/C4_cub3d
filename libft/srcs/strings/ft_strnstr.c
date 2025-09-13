/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:37:52 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:49:25 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"

// Locates the first occurrence of the null-terminated string little in the
// string big, where not more than len characters are searched.
// Characters that appear after a ‘\0’ character are not searched.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_little;
	size_t	size_little;

	i_big = 0;
	size_little = ft_strlen(little);
	if (size_little == 0)
		return ((char *)big);
	while (i_big < len && big[i_big])
	{
		i_little = 0;
		if (big[i_big] == little[i_little])
		{
			while (big[i_big + i_little] == little[i_little] && (i_big
					+ i_little < len) && little[i_little])
				i_little++;
			if (i_little == size_little)
				return ((char *)big + i_big);
		}
		i_big++;
	}
	return (NULL);
}
