/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:48:25 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/10 18:59:28 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char	tests[] = {'a', 'Z', 'm', '5', '@', ' ', '\n', '\0'};
// 	int		i;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		printf("Carácter: ");
// 		if (tests[i] == '\n')
// 			printf("'\\n'");
// 		else if (tests[i] == '\0')
// 			printf("'\\0'");
// 		else
// 			printf("'%c'", tests[i]);

// 		printf("\n");
// 		printf("ft_isalpha: %d\n", ft_isalpha(tests[i]) != 0);
// 		printf("isalpha   : %d\n", isalpha(tests[i]) != 0);

// 		if ((ft_isalpha(tests[i]) != 0)
// 			== (isalpha(tests[i]) != 0))
// 			printf("OK\n\n");
// 		else
// 			printf("ERROR\n\n");

// 		i++;
// 	}
// 	return (0);
// }
