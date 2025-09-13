/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:38:18 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:33:05 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

// Erases the data in the n bytes of the memory starting at the location
// pointed to by s, by writing zeros (bytes containing '\0') to that area.
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
