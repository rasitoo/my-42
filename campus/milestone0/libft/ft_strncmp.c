/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:52:24 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/18 19:22:23 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && n != 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
	}
	return (s1[i] - s2[i]);
}

// int	main(void)
// {
// 	const char	*s1;
// 	const char	*s2;
// 	size_t		n;

// 	s1 = "Hola";
// 	s2 = "Hola";
// 	n = 4;
// 	printf("Caso 1: \"%s\" vs \"%s\" (n=%zu)\n", s1, s2, n);
// 	printf("ft_strncmp = %d\n", ft_strncmp(s1, s2, n));
// 	printf("strncmp    = %d\n\n", strncmp(s1, s2, n));

// 	s1 = "Hola";
// 	s2 = "Holo";
// 	n = 4;
// 	printf("Caso 2: \"%s\" vs \"%s\" (n=%zu)\n", s1, s2, n);
// 	printf("ft_strncmp = %d\n", ft_strncmp(s1, s2, n));
// 	printf("strncmp    = %d\n\n", strncmp(s1, s2, n));

// 	s1 = "Hola";
// 	s2 = "Mola";
// 	n = 4;
// 	printf("Caso 3: \"%s\" vs \"%s\" (n=%zu)\n", s1, s2, n);
// 	printf("ft_strncmp = %d\n", ft_strncmp(s1, s2, n));
// 	printf("strncmp    = %d\n\n", strncmp(s1, s2, n));

// 	s1 = "Hola";
// 	s2 = "Hola mundo";
// 	n = 20;
// 	printf("Caso 4: \"%s\" vs \"%s\" (n=%zu)\n", s1, s2, n);
// 	printf("ft_strncmp = %d\n", ft_strncmp(s1, s2, n));
// 	printf("strncmp    = %d\n\n", strncmp(s1, s2, n));

// 	s1 = "Hola";
// 	s2 = "Adios";
// 	n = 0;
// 	printf("Caso 5: \"%s\" vs \"%s\" (n=%zu)\n", s1, s2, n);
// 	printf("ft_strncmp = %d\n", ft_strncmp(s1, s2, n));
// 	printf("strncmp    = %d\n\n", strncmp(s1, s2, n));

// 	return (0);
// }