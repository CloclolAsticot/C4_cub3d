/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:46:48 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:20:17 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_H
# define FT_CONVERSIONS_H

int		ft_atoi(const char *nptr);

int		ft_atoi_int(const char *nptr);

char	*ft_itoa(int n);

char	*ft_itoabase(unsigned long int n, char *base);

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_tolower(int character);

int		ft_toupper(int character);

#endif