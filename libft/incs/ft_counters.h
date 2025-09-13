/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counters.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:31:32 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:21:21 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COUNTERS_H
# define FT_COUNTERS_H

# include <string.h>

size_t	ft_arraylen(const char **array);

size_t	ft_countwords(char const *str, char sep);

size_t	ft_countwords_charset(char const *str, char *charset);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlen(const char *str);

#endif