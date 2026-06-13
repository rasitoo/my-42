/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:52:10 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/13 20:03:53 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// int	main(void)
// {
// 	const char	*tests[] = {
// 		"",
// 		"a",
// 		"Hola",
// 		"Hola mundo",
// 		"1234567890",
// 		"42 Madrid"
// 	};
// 	int	i;

// 	i = 0;
// 	while (i < 6)
// 	{
// 		printf("Cadena: \"%s\"\n", tests[i]);
// 		printf("ft_strlen: %zu\n", ft_strlen(tests[i]));
// 		printf("strlen   : %zu\n", strlen(tests[i]));

// 		if (ft_strlen(tests[i]) == strlen(tests[i]))
// 			printf("OK\n\n");
// 		else
// 			printf("ERROR\n\n");

// 		i++;
// 	}
// 	return (0);
// }
