/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:46:33 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:20:02 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_booleans.h"
#include <limits.h>
#include <strings.h>

// Converts the initial portion of the string pointed to by nptr to int.
int	ft_atoi_int(const char *nptr)
{
	size_t	i;
	long	sign;
	long	nbr;

	i = -1;
	sign = 1;
	nbr = 0;
	while (nptr[++i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i++]))
	{
		if (nbr > ((INT_MAX - (nptr[i - 1] - '0')) / 10) && sign > 0)
			return (-1);
		else if (nbr > (((long)(INT_MAX) + 1 - (nptr[i - 1] - '0')) / 10)
			&& sign < 0)
			return (0);
		nbr = nbr * 10 + nptr[i - 1] - '0';
	}
	return (sign * nbr);
}
