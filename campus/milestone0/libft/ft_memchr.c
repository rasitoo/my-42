/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:49:59 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			idx;

	/* Simple idea: scan the first n bytes for the given byte. */
	ptr = (unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		if (ptr[idx] == (unsigned char)c)
			return ((void *)&ptr[idx]);
		idx++;
	}
	return (NULL);
}

#ifdef FT_MAIN
int	main(void)
{
	char	*ptr;

	ptr = (char *)ft_memchr("abc", 'b', 3);
	printf("memchr: %c\n", *ptr);
	return (0);
}
#endif
