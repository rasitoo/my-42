/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:35:13 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 16:35:16 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	jdx;
	size_t	len;

	len = ft_strlen(dst);
	idx = len;
	jdx = 0;
	if (size <= len)
		return (ft_strlen(src) + size);
	while (src[jdx] != '\0' && idx + 1 < size)
	{
		dst[idx] = src[jdx];
		idx++;
		jdx++;
	}
	dst[idx] = '\0';
	return (len + ft_strlen(src));
}
