/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:53:25 by yfrilley          #+#    #+#             */
/*   Updated: 2025/06/03 15:19:00 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"
#include "ft_dprintf.h"

/**
 * @brief Converts a string argument from va_list and appends it to buffer
 * 
 * Extracts a string from the variable arguments list. If the string is NULL,
 * it appends "(null)" to the buffer. Otherwise, it appends the actual string.
 * This function is used for %s conversion in printf-like implementations.
 *
 * @param buffer Pointer to the buffer where the string will be appended
 * @param args Variable argument list containing the string to extract
 * 
 * @return Number of characters written to the buffer
 */
int	convert_string(t_buffer *buffer, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (buffer_append_str(buffer, "(null)"));
	else
		return (buffer_append_str(buffer, str));
}

/**
 * @brief Converts a character argument to a string and appends it to a buffer
 *
 * Retrieves a character from the variable argument list and appends it to the
 * provided buffer using buffer_append_char.
 *
 * @param buffer Pointer to the buffer structure to append to
 * @param args Variable argument list containing the character to convert
 * @return Result of buffer_append_char operation (typically success status)
 */
int	convert_char(t_buffer *buffer, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (buffer_append_char(buffer, c));
}

/**
 * int_base_len - Calculate the length of an integer in a specific base
 * @integer: Integer to measure
 * @base: Base for representation (e.g., 10 for decimal)
 *
 * For negative numbers, includes the negative sign in the count.
 * Returns 1 for integer value of 0.
 *
 * @return: Number of digits/characters required
 */
size_t	int_base_len(long integer, size_t base)
{
	size_t	i;

	i = 0;
	if (integer < 0)
	{
		i++;
		integer = -integer;
	}
	if (integer == 0)
		return (1);
	while (integer > 0)
	{
		i++;
		integer /= base;
	}
	return (i);
}

/**
 * @brief Convert an integer to string representation in specified base and
 *        append it to the buffer
 * 
 * This function extracts an integer argument from va_list, converts it to a
 * string representation in the specified base, and appends the result to
 * the buffer.
 * 
 * @param buffer      Pointer to the buffer where result will be stored
 * @param args        va_list containing the argument to convert
 * @param base_list   String containing all digits of the target base
 * @param is_unsigned Flag indicating if the number should be treated as unsigned
 * 
 * @return            The number of characters added to the buffer
 *                    (-1 if an error occurred)
 */
int	convert_base(t_buffer *buffer, va_list args, char *base_list,
		int is_unsigned)
{
	long	decimal;
	char	result[12];
	size_t	i;
	size_t	base;

	base = ft_strlen(base_list);
	if (is_unsigned == 1)
		decimal = (long)va_arg(args, unsigned int);
	else
		decimal = (long)va_arg(args, int);
	if (decimal == 0)
		return (buffer_append_char(buffer, '0'));
	i = int_base_len(decimal, base);
	if (decimal < 0)
	{
		result[0] = '-';
		decimal = -decimal;
	}
	result[i] = '\0';
	while (decimal > 0)
	{
		result[--i] = base_list[decimal % base];
		decimal /= base;
	}
	return (buffer_append_str(buffer, result));
}

/**
* Converts a pointer to its hexadecimal string representation and appends it
* to the buffer. Uses '0x' prefix followed by the address in lowercase hex.
* If the pointer is NULL, writes "(nil)" instead.
*
* @param buffer      Buffer to append the result to
* @param args        Variable argument list containing the pointer to convert
* @param hexa_list   String containing hex digits to use for conversion
*
* @return            Result from buffer_append_str (chars written or error)
*/
int	convert_pointer(t_buffer *buffer, va_list args, char *hexa_list)
{
	size_t	decimal_address;
	size_t	decimal_address_buff;
	char	hexa_address[22];
	size_t	i;

	hexa_address[0] = '0';
	hexa_address[1] = 'x';
	i = 2;
	decimal_address = (size_t)va_arg(args, void *);
	if (!decimal_address)
		return (buffer_append_str(buffer, "(nil)"));
	decimal_address_buff = decimal_address;
	while (decimal_address_buff > 0)
	{
		decimal_address_buff /= 16;
		i++;
	}
	hexa_address[i] = '\0';
	while (decimal_address > 0)
	{
		hexa_address[--i] = hexa_list[decimal_address % 16];
		decimal_address /= 16;
	}
	return (buffer_append_str(buffer, hexa_address));
}
