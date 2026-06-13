/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:51:17 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/13 22:53:15 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dlen;
	unsigned int	slen;
	unsigned int	tofill;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	tofill = size - dlen - 1;
	if (dlen >= size)
		return (size + slen);
	while (src[i] != '\0' && tofill--)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

// int	main(void)
// {
// 	char	buffer[20];
// 	size_t	ret;

// 	strcpy(buffer, "Hola");
// 	ret = ft_strlcat(buffer, " Mundo", sizeof(buffer));
// 	printf("Caso 1\n");
// 	printf("buffer = \"%s\"\n", buffer);
// 	printf("ret    = %zu\n\n", ret);

// 	strcpy(buffer, "Hola");
// 	ret = ft_strlcat(buffer, " Mundo", 8);
// 	printf("Caso 2\n");
// 	printf("buffer = \"%s\"\n", buffer);
// 	printf("ret    = %zu\n\n", ret);

// 	strcpy(buffer, "Hola");
// 	ret = ft_strlcat(buffer, " Mundo", 5);
// 	printf("Caso 3\n");
// 	printf("buffer = \"%s\"\n", buffer);
// 	printf("ret    = %zu\n\n", ret);

// 	strcpy(buffer, "Hola");
// 	ret = ft_strlcat(buffer, " Mundo", 0);
// 	printf("Caso 4\n");
// 	printf("buffer = \"%s\"\n", buffer);
// 	printf("ret    = %zu\n\n", ret);

// 	return (0);
// }
