/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:50:20 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srcp;
	size_t			idx;

	/* Correction: memmove must safely handle overlap, copying backward when needed. */
	if (dest == NULL && src == NULL)
		return (NULL);
	dst = (unsigned char *)dest;
	srcp = (unsigned char *)src;
	if (dst > srcp)
	{
		idx = n;
		while (idx > 0)
		{
			idx--;
			dst[idx] = srcp[idx];
		}
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

#ifdef FT_MAIN
int	main(void)
{
	char	str[] = "abc";

	ft_memmove(str, str + 1, 2);
	printf("memmove: %s\n", str);
	return (0);
}
#endif
