/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frckles <frckles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:35:09 by abisiani          #+#    #+#             */
/*   Updated: 2025/07/16 18:03:29 by frckles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// malloc, free, write, va_start, va_arg, va_copy, va_end

// %[parameter][flags][width][.precision][length] type
// %[flags][width][.precision] type
// cspdiuxX%

// c: Used to print a single character. For example, printf("%c", 'A'); will print A.
// s: Used to print a string. For example, printf("%s", "Hello"); will print Hello.
// p: Used to print the address of a variable in hexadecimal format. For example, pbrintf("%p", &var); will print the memory address of var.
// d: Used to print a signed integer. For example, printf("%d", 10); will print 10.
// i: Used to print a signed integer, similar to %d. For example, printf("%i", 10); will print 10.
// u: Used to print an unsigned integer. For example, printf("%u", 10); will print 10.
// x: Used to print an unsigned integer in hexadecimal format (lowercase). For example, printf("%x", 255); will print ff.
// X: Used to print an unsigned integer in hexadecimal format (uppercase). For example, printf("%X", 255); will print FF.
// %: Used to print a literal % character. For example, printf("%%"); will print %.

// Variadic funcs
// va_start, va_arg, va_copy, va_end

#include "ft_printf.h"

int	parse_format_specifier(const char *format, va_list args)
{
	int len;

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
		len = print_X(va_arg(args, unsigned int));
	else if (*format == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t count;
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
