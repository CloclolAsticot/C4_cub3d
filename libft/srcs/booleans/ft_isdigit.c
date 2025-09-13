/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:19:31 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 17:50:15 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

// Checks for a digit (0 through 9) - Returns a nonzero value if the character
// is a digit, and zero if it is not.
bool	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (true);
	else
		return (false);
}
