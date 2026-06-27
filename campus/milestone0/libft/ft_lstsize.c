/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:49:55 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	/* Simple idea: count how many nodes are in the list. */
	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

#ifdef FT_MAIN
int	main(void)
{
	t_list	*head;

	head = ft_lstnew("a");
	head->next = ft_lstnew("b");
	printf("lstsize: %d\n", ft_lstsize(head));
	return (0);
}
#endif
