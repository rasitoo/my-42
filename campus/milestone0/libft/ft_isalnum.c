/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:48:21 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/10 18:59:19 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char	tests[] = {'a', 'Z', '5', '@', ' ', '\n', '\0'};
// 	int		i;

// 	i = 0;
// 	while (i < 7)
// 	{
// 		printf("Carácter: ");
// 		if (tests[i] == '\n')
// 			printf("'\\n'");
// 		else if (tests[i] == '\0')
// 			printf("'\\0'");
// 		else
// 			printf("'%c'", tests[i]);

// 		printf("\n");
// 		printf("ft_isalnum: %d\n", ft_isalnum(tests[i]) != 0);
// 		printf("isalnum   : %d\n", isalnum(tests[i]) != 0);

// 		if ((ft_isalnum(tests[i]) != 0)
// 			== (isalnum(tests[i]) != 0))
// 			printf("OK\n\n");
// 		else
// 			printf("ERROR\n\n");

// 		i++;
// 	}
// 	return (0);
// }
