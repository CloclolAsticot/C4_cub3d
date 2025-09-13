/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:41:13 by csavreux          #+#    #+#             */
/*   Updated: 2024/11/25 19:04:22 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// If the character is a lowercase, returns the uppercase equivalent - Else
// returns the character.
int	ft_toupper(int character)
{
	if (character >= 'a' && character <= 'z')
		return (character - ' ');
	else
		return (character);
}
