/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_booleans.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:41:54 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 17:54:00 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEANS_H
# define FT_BOOLEANS_H

# include <stdbool.h>

bool	ft_isalnum(int character);

bool	ft_isalpha(int character);

bool	ft_isascii(int character);

bool	ft_isdigit(int character);

bool	ft_isprint(int character);

bool	ft_iswhitespace(char c);

bool	is_in_charset(char c, char *charset);

#endif