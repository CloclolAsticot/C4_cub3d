/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:38:48 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:17:14 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"
#include "ft_memory.h"

// Returns the number of digits of a number n (counts place for "-" if
// negative number).
// Doesnt't count a place for the '\0'.
static size_t	ft_size_str(unsigned long int n, char *base)
{
	size_t	size_str;
	size_t	size_base;

	size_base = ft_strlen(base);
	size_str = 1;
	while (n >= size_base)
	{
		n = n / size_base;
		size_str++;
	}
	return (size_str);
}

// Allocates with malloc and returns a string representing the int n in a
// given base.
// Doesn't handle negative numbers.
char	*ft_itoabase(unsigned long int n, char *base)
{
	size_t	size_str;
	size_t	size_base;
	char	*str;

	size_base = ft_strlen(base);
	size_str = ft_size_str(n, base);
	str = ft_calloc(size_str + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n % size_base != 0 || n / size_base != 0)
	{
		str[size_str - 1] = base[n % size_base];
		n = n / size_base;
		size_str--;
	}
	return (str);
}
