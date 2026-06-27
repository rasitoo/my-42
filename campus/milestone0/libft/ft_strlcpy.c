/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:31:29 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;

	idx = 0;
	if (size > 0)
	{
		while (src[idx] != '\0' && idx + 1 < size)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	while (src[idx] != '\0')
		idx++;
	return (idx);
}

#ifdef FT_MAIN
int	main(void)
{
	char	dst[4];

	printf("strlcpy: %zu\n", ft_strlcpy(dst, "abc", 4));
	return (0);
}
#endif
