/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:48:26 by rtapiado          #+#    #+#             */
/*   Updated: 2026/09/28 01:57:56 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_eval_format(char const*format, va_list args)
{
	char	c;

	if (*format == 'd')
	{
		return (ft_putnbr(va_arg(args, int)));
	}
	else if (*format == 's')
	{
		return (ft_putstr(va_arg(args, char *)));
	}
	else if (*format == 'c')
	{
		c = (char)va_arg(args, int);
		return (write(1, &c, 1));
	}
	return (0);
}

int	ft_printf(char	const *format, ...)
{
	int		n;
	va_list	args;

	n = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			n += ft_eval_format(format, args);
		}
		else
		{
			write(1, format, 1);
			n++;
		}
		format++;
	}
	va_end(args);
	return (n);
}
