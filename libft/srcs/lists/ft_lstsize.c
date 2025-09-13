/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:10:26 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:31:29 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"
#include <stddef.h>

// Counts the number of nodes in a list.
int	ft_lstsize(t_list *lst)
{
	size_t	list_size;

	list_size = 0;
	while (lst != NULL)
	{
		list_size++;
		lst = lst->next;
	}
	return (list_size);
}
