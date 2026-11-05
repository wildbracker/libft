/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalaini <amalaini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 16:45:23 by amalaini          #+#    #+#             */
/*   Updated: 2026/11/02 21:56:14 by amalaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	t_list	*node0;

	head = NULL;
	node0 = lst;
	if (lst)
		head = ft_calloc(sizeof(t_list), 1);
	node = head;
	while (node0 && node)
	{
		node->content = f(node0->content);
		if (node0->next)
			node->next = ft_calloc(sizeof(t_list), 1);
		if (node0->next && !node->next)
		{
			ft_lstclear(&head, del);
			break ;
		}
		node = node->next;
		node0 = node0->next;
	}
	return (head);
}
