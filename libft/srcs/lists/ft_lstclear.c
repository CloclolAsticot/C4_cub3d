/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 02:41:03 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:28:37 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"
#include <stdlib.h>

// Deletes and frees the given node and every successor of that node, using
// the function ’del’ and free().
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while (*lst != NULL)
	{
		del((*lst)->content);
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}
