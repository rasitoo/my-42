/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:49:44 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	/* Simple idea: create a new list with transformed contents. */
	new_list = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

#ifdef FT_MAIN
static void	*dup_content(void *content)
{
	return (strdup((char *)content));
}

int	main(void)
{
	t_list	*head;
	t_list	*mapped;

	head = ft_lstnew(strdup("a"));
	ft_lstadd_back(&head, ft_lstnew(strdup("b")));
	mapped = ft_lstmap(head, dup_content, free);
	printf("lstmap: %s\n", (char *)mapped->content);
	ft_lstclear(&head, free);
	ft_lstclear(&mapped, free);
	return (0);
}
#endif
