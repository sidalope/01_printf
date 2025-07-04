/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frckles <frckles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:35:09 by abisiani          #+#    #+#             */
/*   Updated: 2025/07/04 14:22:27 by frckles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// malloc, free, write, va_start, va_arg, va_copy, va_end

// %[parameter][flags][width][.precision][length] type
// %[flags][width][.precision] type
// cspdiuxX%

// c: Used to print a single character. For example, printf("%c", 'A'); will print A.
// s: Used to print a string. For example, printf("%s", "Hello"); will print Hello.
// p: Used to print the address of a variable in hexadecimal format. For example, printf("%p", &var); will print the memory address of var.
// d: Used to print a signed integer. For example, printf("%d", 10); will print 10.
// i: Used to print a signed integer, similar to %d. For example, printf("%i", 10); will print 10.
// u: Used to print an unsigned integer. For example, printf("%u", 10); will print 10.
// x: Used to print an unsigned integer in hexadecimal format (lowercase). For example, printf("%x", 255); will print ff.
// X: Used to print an unsigned integer in hexadecimal format (uppercase). For example, printf("%X", 255); will print FF.
// %: Used to print a literal % character. For example, printf("%%"); will print %.

// Variadic funcs
// va_start, va_arg, va_copy, va_end

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	(void)format;
	va_list	args;
	va_start(args, format);

	// For every character in the string, if it's a %, check what comes after and parse, else write it
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

int	main(int argc, char* argv[])
{
	if (argc == 3)
	{
		printf(argv[1], argv[2]);
		ft_printf(argv[1], argv[2]);
	}
	return (0);
}
