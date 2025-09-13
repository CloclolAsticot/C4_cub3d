/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:20:36 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:56:27 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define DECIMAL "0123456789"
# define HEXA "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"
# define INITIAL_BUFFER_SIZE 64

typedef enum e_signed
{
	NUM_SIGNED,
	NUM_UNSIGNED
}			t_num_sign;

typedef struct s_buffer
{
	char	*str; // The actual string buffer
	size_t	size; // Current length of content
	size_t	capacity; // Total allocated space
}			t_buffer;

int			ft_dprintf(int fd, const char *str, ...);

// Buffer functions
int			buffer_init(t_buffer *buffer);
int			buffer_append_char(t_buffer *buffer, char c);
int			buffer_append_str(t_buffer *buffer, const char *str);

// Format functions
int			convert_char(t_buffer *buffer, va_list args);
int			convert_string(t_buffer *buffer, va_list args);
int			convert_base(t_buffer *buffer, va_list args, char *base_list,
				int is_unsigned);
int			convert_pointer(t_buffer *buffer, va_list args, char *hexa_list);

#endif