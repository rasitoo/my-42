/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:31:29 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains(char c, char const *set)
{
	size_t	idx;

	idx = 0;
	while (set[idx] != '\0')
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_contains(s1[start], set))
		start++;
	while (end > start && ft_contains(s1[end - 1], set))
		end--;
	len = end - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1 + start, len);
	res[len] = '\0';
	return (res);
}

#ifdef FT_MAIN
int	main(void)
{
	char	*res;

	res = ft_strtrim("  abc  ", " ");
	printf("strtrim: %s\n", res);
	free(res);
	return (0);
}
#endif
