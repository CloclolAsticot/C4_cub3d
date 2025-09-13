/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:30:38 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:19:13 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

// Returns the number of digits of a number n (counts place for "-" if
// negative number).
// Doesnt't count a place for the '\0'.
static size_t	ft_size_str(int n)
{
	size_t			size_str;
	unsigned int	nbr;

	size_str = 1;
	if (n < 0)
	{
		size_str++;
		nbr = (unsigned int)(-n);
	}
	else
		nbr = (unsigned int)n;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		size_str++;
	}
	return (size_str);
}

// Allocates with malloc and returns a string representing the int n.
// Handles negative numbers.
char	*ft_itoa(int n)
{
	unsigned int	nbr;
	size_t			size_str;
	char			*str;

	size_str = ft_size_str(n);
	str = ft_calloc(size_str + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		nbr = (unsigned int)(-n);
		str[0] = '-';
	}
	else
		nbr = (unsigned int)n;
	while (nbr % 10 != 0 || nbr / 10 != 0)
	{
		str[size_str - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		size_str--;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}
