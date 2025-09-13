/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 04:49:10 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:46:28 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"
#include "ft_memory.h"

// Returns a pointer to a new string which is a duplicate of the string s.
char	*ft_strdup(const char *s)
{
	size_t	size_s;
	char	*newchain;

	size_s = ft_strlen(s);
	newchain = ft_calloc(size_s + 1, sizeof(char));
	if (!newchain)
		return (NULL);
	ft_memmove(newchain, s, size_s);
	return (newchain);
}
