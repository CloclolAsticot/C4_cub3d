/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:53:21 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:36:15 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

// Copies n bytes from memory area src to memory area dest. The memory areas
// may overlap, however src might be altered.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		if (src != NULL || dest != NULL)
		{
			while (i < n)
			{
				((unsigned char *)dest)[n - i - 1] = ((unsigned char *)src)[n
					- i - 1];
				i++;
			}
		}
	}
	return (dest);
}
