/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:48:13 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/10 18:52:46 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*x;

	x = (unsigned char *)s;
	while (n > 0)
	{
		*x = '\0';
		x++;
		n--;
	}
}

// int	main(void)
// {
// 	char	str1[] = "Hola mundo";
// 	char	str2[] = "Hola mundo";
// 	size_t	n = 5;
// 	size_t	i;

// 	ft_bzero(str1, n);
// 	bzero(str2, n);

// 	printf("Comparación byte a byte:\n");
// 	for (i = 0; i < sizeof(str1); i++)
// 	{
// 		printf("str1[%zu] = %d\tstr2[%zu] = %d\n",
// 			i, (unsigned char)str1[i],
// 			i, (unsigned char)str2[i]);
// 	}

// 	printf("\nMemcmp: %d\n",
// 		memcmp(str1, str2, sizeof(str1)));

// 	return (0);
// }
