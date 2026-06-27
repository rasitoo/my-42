/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:36:01 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 16:44:12 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	jdx;

	if (*little == '\0')
		return ((char *)big);
	idx = 0;
	while (big[idx] != '\0' && idx < len)
	{
		jdx = 0;
		while (little[jdx] != '\0' && big[idx + jdx] == little[jdx]
			&& idx + jdx < len)
			jdx++;
		if (little[jdx] == '\0')
			return ((char *)&big[idx]);
		idx++;
	}
	return (NULL);
}
