/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:55:56 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/13 23:02:05 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		while (j < size)
		{
			dst[j] = src[j];
			j++;
		}
		i++;
	}
	dst[size - 1] = '\0';
	return (i);
}
// int	main(void)
// {
// 	char	dst[20];
// 	size_t	ret;

// 	memset(dst, 'X', sizeof(dst));

// 	ret = ft_strlcpy(dst, "Hola mundo", sizeof(dst));

// 	printf("dst: \"%s\"\n", dst);
// 	printf("ret: %zu\n", ret);

// 	ret = ft_strlcpy(dst, "Hola mundo", 5);

// 	printf("\nsize = 5\n");
// 	printf("dst: \"%s\"\n", dst);
// 	printf("ret: %zu\n", ret);

// 	ret = ft_strlcpy(dst, "Hola mundo", 1);

// 	printf("\nsize = 1\n");
// 	printf("dst: \"%s\"\n", dst);
// 	printf("ret: %zu\n", ret);

// 	ret = ft_strlcpy(dst, "Hola mundo", 0);

// 	printf("\nsize = 0\n");
// 	printf("dst: \"%s\"\n", dst);
// 	printf("ret: %zu\n", ret);

// 	return (0);
// }
