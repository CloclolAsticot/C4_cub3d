/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfrilley <yfrilley@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:53:09 by yfrilley          #+#    #+#             */
/*   Updated: 2025/06/19 14:57:57 by yfrilley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include <stdlib.h>

/**
 * @brief Error handling function for buffer operations
 *
 * This function cleans up the buffer resources and returns an error code when
 * an error occurs during buffer manipulation. It frees the buffer string and
 * resets all buffer properties to their initial values.
 *
 * @param buffer Pointer to the buffer structure that needs cleanup
 * @return Always returns -1 to indicate an error occurred
 */
static int	f_error(t_buffer *buffer, va_list args)
{
	if (buffer && buffer->str)
	{
		free(buffer->str);
		buffer->str = NULL;
		buffer->size = 0;
		buffer->capacity = 0;
	}
	va_end(args);
	return (-1);
}

/**
 * @brief Parses a conversion specifier and calls the appropriate handler.
 *
 * This function examines the character following a '%' in the format string and
 * calls the corresponding conversion function based on the specifier type.
 * Supported format specifiers:
 * - %c: character
 * - %s: string
 * - %p: pointer (in hexadecimal)
 * - %d/%i: signed decimal integer
 * - %u: unsigned decimal integer
 * - %x: lowercase hexadecimal integer
 * - %X: uppercase hexadecimal integer
 * - %%: literal '%' character
 *
 * @param buffer The output buffer where converted data will be stored.
 * @param args Variable argument list containing data to be converted.
 * @param str The format string position currently being parsed.
 * @return int 0 on success, negative value on error.
 */
static int	parse_conversion(t_buffer *buffer, va_list args, const char *str)
{
	if (*str == 'c')
		return (convert_char(buffer, args));
	else if (*str == 's')
		return (convert_string(buffer, args));
	else if (*str == 'p')
		return (convert_pointer(buffer, args, HEXA));
	else if (*str == 'd' || *str == 'i')
		return (convert_base(buffer, args, DECIMAL, NUM_SIGNED));
	else if (*str == 'u')
		return (convert_base(buffer, args, DECIMAL, NUM_UNSIGNED));
	else if (*str == 'x')
		return (convert_base(buffer, args, HEXA, NUM_UNSIGNED));
	else if (*str == 'X')
		return (convert_base(buffer, args, HEXA_UPPER, NUM_UNSIGNED));
	else if (*str == '%')
		return (buffer_append_char(buffer, '%'));
	else
	{
		write(2, "ft_dprintf: invalid directive", 29);
		return (0);
	}
}

/**
 * @brief Outputs formatted text to a specified file descriptor.
 *
 * This function works like printf but writes to a file descriptor instead of
 * stdout. It processes format specifiers (%) and replaces them with the 
 * provided arguments, formatted according to the specifier.
 *
 * @param fd         File descriptor to write to
 * @param str        Format string containing text and format specifiers
 * @param ...        Variable arguments to be formatted according to specifiers
 *
 * @return           Number of characters written, or -1 on error
 */
int	ft_dprintf(int fd, const char *str, ...)
{
	va_list		args;
	size_t		char_count;
	t_buffer	buffer;

	if (str == NULL || buffer_init(&buffer) == 0)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			if (parse_conversion(&buffer, args, str) == 0)
				return (f_error(&buffer, args));
		}
		else if (buffer_append_char(&buffer, *str) == 0)
			return (f_error(&buffer, args));
		str++;
	}
	va_end(args);
	char_count = write(fd, buffer.str, buffer.size);
	free(buffer.str);
	return (char_count);
}
