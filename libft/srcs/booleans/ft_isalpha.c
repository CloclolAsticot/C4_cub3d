/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:31:25 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 17:49:46 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

// Checks for an alphabetic character - Returns a nonzero value if the character
// is alphabetic, and zero if it is not.
bool	ft_isalpha(int character)
{
	if ((character >= 'A' && character <= 'Z') || (character >= 'a'
			&& character <= 'z'))
		return (true);
	else
		return (false);
}
