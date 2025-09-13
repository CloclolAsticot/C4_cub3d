/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:37:40 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:38:39 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGS_H
# define FT_STRINGS_H

# include <string.h>

char	**ft_split(char const *str, char character);

char	**ft_split_charset(char const *str, char *charset);

char	*ft_strchr(const char *str, int character);

char	*ft_strdup(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin_realloc(char *s1, char const *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strncpy(char *dest, const char *src, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strrchr(const char *str, int character);

char	*ft_strtrim(char const *str, char const *set);

char	*ft_substr(char const *str, unsigned int start, size_t len);

#endif