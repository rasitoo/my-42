/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:50:20 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/09 17:50:21 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
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
