/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:45:03 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 17:50:27 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

// Checks for any printable character including space - Returns a nonzero value
// if the character is printable, and zero if it is not.
bool	ft_isprint(int character)
{
	if (character >= ' ' && character <= '~')
		return (true);
	else
		return (false);
}
