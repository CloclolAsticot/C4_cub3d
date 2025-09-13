/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:59:13 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:48:10 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

// Returns an integer less than, equal to, or greater than zero if the
// first n bytes of s1 are found, respectively, to be less than, to match, or
// be greater than s2.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	i = 0;
	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	while ((cast_s1[i] || cast_s2[i]) && i < n)
	{
		if (cast_s1[i] != (cast_s2[i]))
			return (cast_s1[i] - cast_s2[i]);
		else
			i++;
	}
	return (0);
}
