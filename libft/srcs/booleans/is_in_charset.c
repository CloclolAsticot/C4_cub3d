/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_charset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:02:40 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 17:50:42 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/**
 * @brief Checks if a character is part of a given charset.
 *
 * @param c The character to check.
 * @param charset The string containing the set of characters to check against.
 * @return 1 if the character is found in the charset, 0 otherwise.
 */
bool	is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (true);
		charset++;
	}
	return (false);
}
