/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:37:03 by csavreux          #+#    #+#             */
/*   Updated: 2024/11/25 19:05:17 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// If the character is a uppercase, returns the lowercase equivalent - Else
// returns the character.
int	ft_tolower(int character)
{
	if (character >= 'A' && character <= 'Z')
		return (character + ' ');
	else
		return (character);
}
