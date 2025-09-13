/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:05:51 by csavreux          #+#    #+#             */
/*   Updated: 2025/01/14 19:21:52 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H
# define FT_LISTS_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstadd_front(t_list **lst, t_list *new);

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstlast(t_list *lst);

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

t_list				*ft_lstnew(void *content);

int					ft_lstsize(t_list *lst);

#endif