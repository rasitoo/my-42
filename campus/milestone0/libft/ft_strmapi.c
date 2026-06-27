/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:31:29 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	len;
	size_t	idx;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		res[idx] = f(idx, s[idx]);
		idx++;
	}
	res[idx] = '\0';
	return (res);
}

#ifdef FT_MAIN
static char	bump_char(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

int	main(void)
{
	char	*res;

	res = ft_strmapi("ab", bump_char);
	printf("strmapi: %s\n", res);
	free(res);
	return (0);
}
#endif
