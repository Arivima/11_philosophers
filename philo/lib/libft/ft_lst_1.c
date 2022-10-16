/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:57:35 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/09 15:57:37 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*create_element(int n, int index)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->prev = NULL;
	elem->next = NULL;
	elem->n = n;
	elem->index = index;
	return (elem);
}

t_list	*go_to_end(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

t_list	*go_to_top(t_list *list)
{
	while (list->prev)
		list = list->prev;
	return (list);
}

int	append_element(t_list **head, int n, int index)
{
	t_list	*list_tmp;

	list_tmp = *head;
	if (!*head)
	{
		*head = create_element(n, index);
		if (!(*head))
			return (-1);
		else
			return (0);
	}
	list_tmp = go_to_end(list_tmp);
	list_tmp->next = create_element(n, index);
	list_tmp->next->prev = list_tmp;
	if (!list_tmp->next)
		return (-1);
	else
		return (0);
}

void	remove_element(t_list *elem)
{
	if (elem->prev)
		elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	free(elem);
}
