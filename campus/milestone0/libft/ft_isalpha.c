/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:48:25 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	/* Simple idea: accept uppercase and lowercase letters. */
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

#ifdef FT_MAIN
int	main(void)
{
	printf("isalpha: %d\n", ft_isalpha('A'));
	return (0);
}
#endif
