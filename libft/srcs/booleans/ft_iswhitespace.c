/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:48:18 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 17:53:47 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_iswhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	else
		return (false);
}
