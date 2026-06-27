/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:49:32 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	/* Simple idea: apply a callback to each node content. */
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

#ifdef FT_MAIN
static void	print_node(void *content)
{
	printf("%s ", (char *)content);
}

int	main(void)
{
	t_list	*head;

	head = ft_lstnew(strdup("a"));
	head->next = ft_lstnew(strdup("b"));
	ft_lstiter(head, print_node);
	printf("\n");
	return (0);
}
#endif
