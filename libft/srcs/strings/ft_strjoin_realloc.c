/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:29:53 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:47:24 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_counters.h"
#include <stdlib.h>

// Allocates and returns a new string - being the concatenation of s1 and s2.
// Frees the s1.
char	*ft_strjoin_realloc(char *s1, char const *s2)
{
	size_t	newstr_size;
	char	*newstr;
	size_t	i;

	i = 0;
	newstr_size = ft_strlen(s1) + ft_strlen(s2);
	newstr = ft_calloc((newstr_size + 1), sizeof(char));
	if (!newstr)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		newstr[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	free(s1);
	return (newstr);
}
