/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:47:20 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	/* Simple idea: insert a node at the beginning of the list. */
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

#ifdef FT_MAIN
int	main(void)
{
	t_list	*head;

	head = NULL;
	ft_lstadd_front(&head, ft_lstnew("a"));
	printf("lstadd_front: %s\n", (char *)head->content);
	return (0);
}
#endif
