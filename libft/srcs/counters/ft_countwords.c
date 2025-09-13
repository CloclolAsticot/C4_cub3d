/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 04:04:12 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:22:41 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_booleans.h"
#include <strings.h>

// Returns the number of words separated by the sep in the string str.
size_t	ft_countwords(char const *str, char sep)
{
	size_t			i;
	unsigned int	is_sep;
	size_t			wordcount;

	i = 0;
	is_sep = 1;
	wordcount = 0;
	while (str[i])
	{
		if (is_sep == 1 && str[i] != sep && str[i] != '\0')
		{
			is_sep = 0;
			wordcount++;
		}
		else if (is_sep == 0 && str[i] == sep)
			is_sep = 1;
		i++;
	}
	return (wordcount);
}

size_t	ft_countwords_charset(char const *str, char *charset)
{
	size_t			i;
	unsigned int	is_sep;
	size_t			wordcount;

	i = 0;
	is_sep = 1;
	wordcount = 0;
	while (str[i])
	{
		if (is_sep == 1 && is_in_charset(str[i], charset) == 0
			&& str[i] != '\0')
		{
			is_sep = 0;
			wordcount++;
		}
		else if (is_sep == 0 && is_in_charset(str[i], charset) == 1)
			is_sep = 1;
		i++;
	}
	return (wordcount);
}
