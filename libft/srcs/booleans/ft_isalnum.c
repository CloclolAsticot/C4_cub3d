/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:39:03 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 13:52:09 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_booleans.h"

// Checks for an alphanumeric character - Returns a nonzero value if the
// character is alphanumeric, and zero if it is not.
bool	ft_isalnum(int character)
{
	if (ft_isdigit(character) || ft_isalpha(character))
		return (true);
	else
		return (false);
}
