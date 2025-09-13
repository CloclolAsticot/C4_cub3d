/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:02:24 by csavreux          #+#    #+#             */
/*   Updated: 2024/11/25 19:25:11 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Applies the function ’f’ on each character of the string passed as argument,
// passing its index as first argument.
// Each character is passed by address to ’f’ to be modified if necessary.
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
