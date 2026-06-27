/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:31:29 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	idx;

	if (s == NULL || f == NULL)
		return ;
	idx = 0;
	while (s[idx] != '\0')
	{
		f(idx, &s[idx]);
		idx++;
	}
}

#ifdef FT_MAIN
static void	bump(unsigned int i, char *c)
{
	(void)i;
	*c = *c + 1;
}

int	main(void)
{
	char	str[] = "abc";

	ft_striteri(str, bump);
	printf("striteri: %s\n", str);
	return (0);
}
#endif
