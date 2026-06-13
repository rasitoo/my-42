/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:51:01 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/13 23:01:34 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_buff;

	s_buff = (char *) s;
	while (*s_buff != c)
	{
		if (*s_buff == '\0')
			return ('\0');
		s_buff++;
	}
	return (s_buff);
}

// int	main(void)
// {
// 	const char	*str = "Hola mundo";
// 	char		*ft_result;
// 	char		*og_result;

// 	// Buscar una letra existente
// 	ft_result = ft_strchr(str, 'm');
// 	og_result = strchr(str, 'm');

// 	printf("Buscando 'm'\n");
// 	printf("ft_strchr: %s\n", ft_result);
// 	printf("strchr   : %s\n\n", og_result);

// 	// Buscar el primer carácter
// 	ft_result = ft_strchr(str, 'H');
// 	og_result = strchr(str, 'H');

// 	printf("Buscando 'H'\n");
// 	printf("ft_strchr: %s\n", ft_result);
// 	printf("strchr   : %s\n\n", og_result);

// 	// Buscar el carácter nulo '\0'
// 	ft_result = ft_strchr(str, '\0');
// 	og_result = strchr(str, '\0');

// 	printf("Buscando '\\0'\n");
// 	printf("ft_strchr apunta a: \"%s\"\n", ft_result);
// 	printf("strchr apunta a   : \"%s\"\n\n", og_result);

// 	// Buscar un carácter inexistente
// 	ft_result = ft_strchr(str, 'z');
// 	og_result = strchr(str, 'z');

// 	printf("Buscando 'z'\n");
// 	printf("ft_strchr: %p\n", (void *)ft_result);
// 	printf("strchr   : %p\n", (void *)og_result);

// 	return (0);
// }
