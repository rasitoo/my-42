/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:49:07 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	/* Simple idea: delete one node and its content. */
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

#ifdef FT_MAIN
int	main(void)
{
	t_list	*node;

	node = ft_lstnew(strdup("x"));
	ft_lstdelone(node, free);
	printf("lstdelone: ok\n");
	return (0);
}
#endif
