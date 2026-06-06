/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:32:20 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/06 19:07:21 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*src_buff;
	unsigned char	*dest_buff;

	src_buff = (unsigned char *)src;
	dest_buff = (unsigned char *)dest;
	while (n > 0)
	{
		*dest_buff = *src_buff;
		src_buff++;
		dest_buff++;
		n--;
	}
	return (dest);
}
