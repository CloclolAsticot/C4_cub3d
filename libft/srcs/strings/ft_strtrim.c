/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:21:44 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:50:32 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"
#include "ft_strings.h"

// Allocates and returns a copy of the string s1, without the characters
// specified in set at the beginning and the end of the string.
char	*ft_strtrim(char const *str, char const *set)
{
	char	*newstr;
	size_t	newstr_size;
	size_t	i;
	size_t	start;

	start = 0;
	i = 0;
	if (ft_strlen(str) == 0)
		newstr_size = 0;
	else
	{
		while (ft_strchr(set, str[start]) != NULL && str[start])
			start++;
		if (start == ft_strlen(str))
			newstr_size = 0;
		else
		{
			i = ft_strlen(str) - 1;
			while (ft_strchr(set, str[i]) != NULL && str[i])
				i--;
			newstr_size = i - start + 1;
		}
	}
	newstr = ft_substr(str, start, newstr_size);
	return (newstr);
}
