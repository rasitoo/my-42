/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:50:04 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			idx;

	/* Simple idea: compare the first n bytes byte by byte. */
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	idx = 0;
	while (idx < n)
	{
		if (ptr1[idx] != ptr2[idx])
			return (ptr1[idx] - ptr2[idx]);
		idx++;
	}
	return (0);
}

#ifdef FT_MAIN
int	main(void)
{
	printf("memcmp: %d\n", ft_memcmp("ab", "ac", 2));
	return (0);
}
#endif
