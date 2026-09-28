/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:48:26 by rtapiado          #+#    #+#             */
/*   Updated: 2026/09/28 20:06:21 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_eval_format(char const *format, va_list args)
{
	if (*format == 'd' || *format == 'i')
		return (ft_putnbr((long)va_arg(args, int)));
	else if (*format == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (*format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (*format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (*format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(char	const *format, ...)
{
	int		n;
	va_list	args;

	if (!format)
		return (-1);
	n = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
			{
				va_end(args);
				return (-1);
			}
			n += ft_eval_format(format, args);
		}
		else
			n += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (n);
}
