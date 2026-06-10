/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:48:36 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/10 19:01:51 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char	tests[] = {'0', '5', '9', 'a', 'Z', '@', ' ', '\n'};
// 	int		i;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		printf("Carácter: ");
// 		if (tests[i] == '\n')
// 			printf("'\\n'");
// 		else
// 			printf("'%c'", tests[i]);

// 		printf("\n");
// 		printf("ft_isdigit: %d\n", ft_isdigit(tests[i]) != 0);
// 		printf("isdigit   : %d\n", isdigit(tests[i]) != 0);

// 		if ((ft_isdigit(tests[i]) != 0)
// 			== (isdigit(tests[i]) != 0))
// 			printf("OK\n\n");
// 		else
// 			printf("ERROR\n\n");

// 		i++;
// 	}
// 	return (0);
// }