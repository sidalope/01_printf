/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frckles <frckles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:35:09 by abisiani          #+#    #+#             */
/*   Updated: 2025/07/16 18:32:58 by frckles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format_specifier(const char *format, va_list args)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len = print_c(va_arg(args, int));
	else if (*format == 's')
		len = print_s(va_arg(args, char *));
	else if (*format == 'p')
		len = print_p(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		len = print_di(va_arg(args, int));
	else if (*format == 'u')
		len = print_u(va_arg(args, int));
	else if (*format == 'x')
		len = print_x(va_arg(args, unsigned int));
	else if (*format == 'X')
		len = print_x_cap(va_arg(args, unsigned int));
	else if (*format == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
			count += parse_format_specifier(++format, args);
		format++;
	}
	va_end(args);
	return (count);
}
