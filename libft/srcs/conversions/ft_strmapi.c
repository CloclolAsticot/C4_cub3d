/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:07:30 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:18:03 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"
#include "ft_memory.h"

// Applies the function f to each character of the string s, passing its index
// as the first argument and the character itself as the second.
// A new string is created to collect the results from the successive
// applications of f.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			size_str;
	char			*newstr;
	size_t			i;

	i = 0;
	size_str = ft_strlen(s);
	newstr = ft_calloc((size_str + 1), sizeof(char));
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	return (newstr);
}
