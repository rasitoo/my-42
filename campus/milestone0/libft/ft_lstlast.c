/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:49:40 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	/* Simple idea: return the last node of the list. */
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

#ifdef FT_MAIN
int	main(void)
{
	t_list	*head;

	head = ft_lstnew("a");
	head->next = ft_lstnew("b");
	printf("lstlast: %s\n", (char *)ft_lstlast(head)->content);
	return (0);
}
#endif
