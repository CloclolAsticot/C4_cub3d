/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfrilley <yfrilley@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:14:15 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/23 14:32:36 by yfrilley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"

// Appends the NUL-terminated string src to the end of dst. It will append at
// most size - ft_strlen(dst) - 1 bytes, NUL-terminating the result.
// Returns the total length of the string it tried to create.
// Safer, more consistent, and less error prone than strncat.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dst_size)
		return (size + src_size);
	while (src[i] && ((i + dst_size) < (size - 1)))
	{
		dst[i + dst_size] = src[i];
		i++;
	}
	dst[i + dst_size] = '\0';
	return (dst_size + src_size);
}
