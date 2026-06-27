/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:28:55 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 16:30:32 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srcp;
	size_t			idx;

	if (dest == NULL && src == NULL)
		return (NULL);
	dst = (unsigned char *)dest;
	srcp = (unsigned char *)src;
	if (dst > srcp)
	{
		idx = n;
		while (idx-- > 0)
			dst[idx] = srcp[idx];
	}
	else
	{
		idx = 0;
		while (idx < n)
		{
			dst[idx] = srcp[idx];
			idx++;
		}
	}
	return (dest);
}
