/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:57:14 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:35:05 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

// The memcmp() function returns an integer less than, equal to, or greater
// than zero if the first n bytes of s1 is found, respectively, to be less
// than, to match, or be greater than the first n bytes of s2.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	i = 0;
	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cast_s1[i] != cast_s2[i])
			return (((int)cast_s1[i] - cast_s2[i]));
		i++;
	}
	return (0);
}
