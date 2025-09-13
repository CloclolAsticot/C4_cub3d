/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:52:44 by yfrilley          #+#    #+#             */
/*   Updated: 2025/05/10 15:58:12 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_counters.h"
#include "ft_dprintf.h"
#include <stdlib.h>

/**
 * @brief Resizes a buffer by doubling its capacity
 *
 * This function doubles the capacity of the given buffer by allocating a new
 * string with twice the original capacity, copy the contents from the original
 * buffer, and updating the buffer structure accordingly.
 * The original buffer's string is freed.
 *
 * @param buffer Pointer to the t_buffer structure to resize
 * @return 1 on success, 0 on failure (NULL buffer or memory allocation failure)
 */
static int	buffer_resize(t_buffer *buffer)
{
	size_t	new_capacity;
	char	*new_str;

	if (buffer == NULL)
		return (0);
	new_capacity = 2 * buffer->capacity;
	new_str = malloc(new_capacity * sizeof(char));
	if (new_str == NULL)
		return (0);
	ft_strlcpy(new_str, buffer->str, buffer->size + 1);
	free(buffer->str);
	buffer->str = new_str;
	buffer->capacity = new_capacity;
	return (1);
}

/**
 * @brief Append a string to the buffer.
 *
 * This function appends the given string to the end of the buffer. If needed,
 * it will resize the buffer to accommodate the new string.
 *
 * @param buffer Pointer to the buffer structure
 * @param str String to append to the buffer
 *
 * @return 1 on success, 0 on failure (if buffer /str NULL, or resize fails)
 */
int	buffer_append_str(t_buffer *buffer, const char *str)
{
	size_t	len;

	if (buffer == NULL || str == NULL)
		return (0);
	len = ft_strlen(str);
	while (buffer->size + len + 1 > buffer->capacity)
	{
		if (buffer_resize(buffer) == 0)
			return (0);
	}
	ft_strlcpy(buffer->str + buffer->size, str, len + 1);
	buffer->size += len;
	return (1);
}

// Check if buffer needs to resize (current size + 2 > capacity)
//    +2 accounts for new char + null terminator
int	buffer_append_char(t_buffer *buffer, char c)
{
	if (buffer == NULL)
		return (0);
	if (buffer->size + 2 > buffer->capacity)
	{
		if (buffer_resize(buffer) == 0)
			return (0);
	}
	buffer->str[buffer->size] = c;
	buffer->str[buffer->size + 1] = '\0';
	buffer->size += 1;
	return (1);
}

/**
 * @brief Initialize a buffer structure
 *
 * This function initializes a t_buffer structure by allocating memory
 * for its string field with the size defined by INITIAL_BUFFER_SIZE.
 * It sets all fields to their initial values and adds a null terminator
 * to the string.
 *
 * @param buffer Pointer to the t_buffer structure to initialize
 * @return 1 on success, 0 if memory allocation fails
 */
int	buffer_init(t_buffer *buffer)
{
	*buffer = (t_buffer){NULL, 0, 0};
	buffer->str = malloc(INITIAL_BUFFER_SIZE * sizeof(char));
	if (!buffer->str)
		return (0);
	buffer->capacity = INITIAL_BUFFER_SIZE;
	buffer->str[0] = '\0';
	return (1);
}
