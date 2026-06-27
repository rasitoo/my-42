/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:49:02 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	/* Simple idea: delete every node and its content. */
	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

#ifdef FT_MAIN
int	main(void)
{
	t_list	*head;

	head = ft_lstnew(strdup("x"));
	ft_lstclear(&head, free);
	printf("lstclear: %d\n", head == NULL);
	return (0);
}
#endif
