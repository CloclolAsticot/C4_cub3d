/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:26:37 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:21:38 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

// Calculates the length of the array pointed to by array, excluding the
// terminating null case.
size_t	ft_arraylen(const char **array)
{
	size_t	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}
