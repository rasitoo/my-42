/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:31:29 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	words;
	int	idx;

	words = 0;
	idx = 0;
	while (s[idx] != '\0')
	{
		if ((idx == 0 || s[idx - 1] == c) && s[idx] != c)
			words++;
		idx++;
	}
	return (words);
}

static char	*ft_strndup(char const *s, size_t n)
{
	char	*dup;
	size_t	idx;

	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	idx = 0;
	while (idx < n)
	{
		dup[idx] = s[idx];
		idx++;
	}
	dup[idx] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		idx;
	int		jdx;
	int		start;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	idx = 0;
	jdx = 0;
	while (s[idx] != '\0')
	{
		while (s[idx] == c)
			idx++;
		if (s[idx] == '\0')
			break ;
		start = idx;
		while (s[idx] != '\0' && s[idx] != c)
			idx++;
		res[jdx++] = ft_strndup(&s[start], idx - start);
	}
	res[jdx] = NULL;
	return (res);
}

#ifdef FT_MAIN
int	main(void)
{
	char	**parts;

	parts = ft_split("one-two-three", '-');
	printf("split: %s %s\n", parts[0], parts[2]);
	free(parts[0]);
	free(parts[1]);
	free(parts[2]);
	free(parts);
	return (0);
}
#endif
