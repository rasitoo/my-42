/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:52:35 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/13 23:04:05 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	n;
	char			*s_buff;

	n = ft_strlen(s);
	s_buff = (char *) s;
	while (s_buff[n] != c)
	{
		if (n == 0)
			return ('\0');
		n--;
	}
	while (n != 0)
	{
		s_buff++;
		n--;
	}
	return (s_buff);
}

// int	main(void)
// {
// 	const char	*str = "Hola mundo hola";
// 	char		*ft_res;
// 	char		*std_res;

// 	char tests[] = {'o', 'H', 'z', '\0'};
// 	int i = 0;

// 	while (i < 4)
// 	{
// 		ft_res = ft_strrchr(str, tests[i]);
// 		std_res = strrchr(str, tests[i]);

// 		if (tests[i] == '\0')
// 			printf("Buscando '\\0'\n");
// 		else
// 			printf("Buscando '%c'\n", tests[i]);

// 		printf("ft_strrchr : %p\n", (void *)ft_res);
// 		printf("strrchr    : %p\n", (void *)std_res);

// 		if (ft_res)
// 			printf("ft -> \"%s\"\n", ft_res);
// 		if (std_res)
// 			printf("std-> \"%s\"\n", std_res);

// 		if (ft_res == std_res)
// 			printf("OK\n\n");
// 		else
// 			printf("ERROR\n\n");

// 		i++;
// 	}
// 	return (0);
// }
