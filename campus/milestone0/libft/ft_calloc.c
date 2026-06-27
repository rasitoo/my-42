/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:48:18 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	/* Simple idea: allocate and zero a block of memory. */
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && nmemb > ((size_t)-1) / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

#ifdef FT_MAIN
int	main(void)
{
	char	*ptr;

	ptr = (char *)ft_calloc(3, 2);
	printf("calloc: %d\n", (int)ptr[0]);
	free(ptr);
	return (0);
}
#endif
