/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:42:07 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:45:17 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"
#include "ft_strings.h"
#include <stdlib.h>

// Returns the size of the word beginning at start in str.
static size_t	ft_wordsize(char const *str, unsigned int start, char sep)
{
	size_t	wordsize;

	wordsize = 0;
	while (str[start] != sep && str[start] != '\0')
	{
		start++;
		wordsize++;
	}
	return (wordsize);
}

// Frees each case of the array and the array itself if one of the mallocs
// fails.
static void	*ft_free_array(char **tab_words, size_t i_tab_words)
{
	size_t	i;

	i = 0;
	while (i < i_tab_words)
	{
		free(tab_words[i]);
		i++;
	}
	free(tab_words);
	return (NULL);
}

// Allocates and returns an array of strings obtained by splitting ’s’ using
// the character ’c’ as a delimiter.
char	**ft_split(char const *str, char sep)
{
	char	**tab_words;
	size_t	nb_words;
	size_t	i_str;
	size_t	i_tab_words;

	i_str = 0;
	i_tab_words = 0;
	nb_words = ft_countwords(str, sep);
	tab_words = malloc((nb_words + 1) * sizeof(char *));
	if (!tab_words)
		return (NULL);
	tab_words[nb_words] = NULL;
	while (i_tab_words < nb_words)
	{
		while (str[i_str] == sep)
			i_str++;
		tab_words[i_tab_words] = ft_substr(str, i_str, ft_wordsize(str, i_str,
					sep));
		if (!tab_words[i_tab_words])
			return (ft_free_array(tab_words, i_tab_words));
		i_str += ft_wordsize(str, i_str, sep);
		i_tab_words++;
	}
	return (tab_words);
}
