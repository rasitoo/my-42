/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:28:23 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 16:28:34 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			idx;

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
