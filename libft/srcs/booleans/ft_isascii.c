/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:39:50 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 17:50:04 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

// Checks whether the character is a char value  that  fits
// into the ASCII character set - Returns a nonzero value if the character
// is ascii, and zero if it is not.
bool	ft_isascii(int character)
{
	if (character >= 0 && character <= 127)
		return (true);
	else
		return (false);
}
