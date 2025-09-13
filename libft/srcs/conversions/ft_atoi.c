/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:53:50 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:12:39 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_booleans.h"
#include <limits.h>
#include <strings.h>

// Converts the initial portion of the string pointed to by nptr to int.
int	ft_atoi(const char *nptr)
{
	size_t	i;
	long	sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		if (nbr > ((LONG_MAX - (nptr[i] - '0')) / 10) && sign > 0)
			return (-1);
		else if (nbr > ((LONG_MAX - (nptr[i] - '0')) / 10) && sign < 0)
			return (0);
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	return (sign * nbr);
}
