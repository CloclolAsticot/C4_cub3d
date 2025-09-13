/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:56:21 by csavreux          #+#    #+#             */
/*   Updated: 2024/11/25 22:04:12 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Outputs the character ’c’ to the given file descriptor.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
