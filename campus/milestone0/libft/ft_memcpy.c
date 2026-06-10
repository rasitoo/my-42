/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:50:11 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/10 19:13:46 by rtapiado         ###   ########.fr       */
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

// int	main(void)
// {
// 	char	src[] = "Hola mundo";
// 	char	dest1[20];
// 	char	dest2[20];

// 	ft_memcpy(dest1, src, strlen(src) + 1);
// 	memcpy(dest2, src, strlen(src) + 1);

// 	printf("ft_memcpy: %s\n", dest1);
// 	printf("memcpy   : %s\n", dest2);

// 	if (memcmp(dest1, dest2, strlen(src) + 1) == 0)
// 		printf("OK\n");
// 	else
// 		printf("ERROR\n");

// 	return (0);
// }
