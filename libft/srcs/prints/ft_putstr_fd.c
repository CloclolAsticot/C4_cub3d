/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:00:52 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:38:08 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"
#include <unistd.h>

// Outputs the string ’s’ to the given file descriptor.
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
