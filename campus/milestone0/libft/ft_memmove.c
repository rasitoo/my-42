/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:50:20 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/10 19:22:56 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ! TODO Comprobar si existe concurrencia comparando las direcciones de memoria y usando la longitud de src, si no existe usar memcpy si existe entonces comprobar la direccion de la concurrencia, darle un pienso.

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

// int	main(void)
// {
// 	char	a1[30] = "abcdefghijkl";
// 	char	a2[30] = "abcdefghijkl";

// 	char	b1[30] = "abcdefghijkl";
// 	char	b2[30] = "abcdefghijkl";

// 	/* Solapamiento hacia delante */
// 	ft_memmove(a1 + 3, a1, 8);
// 	memmove(a2 + 3, a2, 8);

// 	printf("Caso 1:\n");
// 	printf("ft : %s\n", a1);
// 	printf("std: %s\n\n", a2);

// 	/* Solapamiento hacia atrás */
// 	ft_memmove(b1, b1 + 3, 8);
// 	memmove(b2, b2 + 3, 8);

// 	printf("Caso 2:\n");
// 	printf("ft : %s\n", b1);
// 	printf("std: %s\n\n", b2);

// 	if (memcmp(a1, a2, sizeof(a1)) == 0
// 		&& memcmp(b1, b2, sizeof(b1)) == 0)
// 		printf("Todos los tests OK\n");
// 	else
// 		printf("ERROR\n");

// 	return (0);
// }
