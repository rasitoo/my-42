/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:50:26 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/09 17:50:27 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*x;

	x = (unsigned char *)s;
	while (n > 0)
	{
		*x = (unsigned char)c;
		x++;
		n--;
	}
	return (s);
}
// int main(void)
// {
//     char buffer1[20];
//     char buffer2[20];
//     ft_memset(buffer1, 0, 20);
//     memset(buffer2, 0, 20);
//     printf("ft_memset: %s | memset: %s\n", buffer1, buffer2);
//     ft_memset(buffer1, 'A', 10);
//     memset(buffer2, 'A', 10);
//     printf("ft_memset: %s | memset: %s\n", buffer1, buffer2);
//     ft_memset(buffer1 + 5, 'Z' + 256, 5);
//     memset(buffer2 + 5, 'Z' + 256, 5);
//     printf("ft_memset: %s | memset: %s\n", buffer1, buffer2);
//     return (0);
// }
