/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:24:48 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:33:40 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdlib.h>

// Allocates memory for an array of nmemb elements of size bytes each and
// returns a pointer to the allocated memory.The memory is set to zero.
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb == 0 || size == 0)
	{
		array = malloc(0);
		if (!array)
			return (NULL);
		return (array);
	}
	else if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	array = malloc(size * nmemb);
	if (!array)
		return (NULL);
	ft_bzero(array, size * nmemb);
	return (array);
}
