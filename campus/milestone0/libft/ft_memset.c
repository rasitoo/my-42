/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:50:28 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			idx;

	/* Simple idea: fill a memory block with one byte. */
	ptr = (unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		ptr[idx] = (unsigned char)c;
		idx++;
	}
	return (s);
}

#ifdef FT_MAIN
int	main(void)
{
	char	str[] = "abc";

	ft_memset(str, 'x', 2);
	printf("memset: %c %c\n", str[0], str[1]);
	return (0);
}
#endif
