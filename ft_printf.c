/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:35:09 by abisiani          #+#    #+#             */
/*   Updated: 2025/06/11 18:31:04 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Variadic functions
// %[parameter][flags][width][.precision][length] type
// %[flags][width][.precision] type
// Does it have to fully implement width?
// What's the longest format string that can be passed per %?
// Can the flags be in any order?
// Check for the presence of each flag. Sets the values of local variables.
// Then uses those variables to call another function to handle the flags correctly. Why?
// Because the flags can be disordered. Should the output be left justified? It needs to be 
// 	parsed before anything is output.

// - = left align the output (default is to right-align)
// 0 = when width is specified, prepends 0s for numeric types (instead of spaces)
// . = a max length of the output, depending on the formatting type
// # = for x and X types, the text 0x or 0X respectively, is prepended to non-zero numbers
//   = prepends a space for positive values (ignored if + exists)
// + = prepends a plus sign for a positive value

// Find length of formatter
// strchr for each, setting local flags
// if '+' prepend plusses, else if ' ' prepend spaces

// If typeof() available to us?

// How the fuck can i do this with max 5 local vars?
// Necessary format per format specifier:
// 		%[flags][width][.][precision] type
// Find % and find the type
// Look back to find the . and set 'precision' var
// Look back to find a number and set 'width' var
// Look back and gather up all chars before % as a string and set 'flags' var
// write_chars(char type, long(?) precision, width, flags)
// What's the max size precision?

// Test behaviour of original printf

// Update libft

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	(void)format;
	return (0);
}

int	main(int argc, char* argv[])
{
	if (argc == 3)
	{
		printf(argv[1], argv[2]);
		ft_printf(argv[1], argv[2]);
	}
	else
	{
		// type
		// .precision
		// width
		// flags

		// One +, -, ., # or 0, not multiple
		// + and 0 order does not matter
		// + and - order does not matter
		// negative values with 0 print as -003
		// No 0 and - flags together
		// No ' ' and + flags together
		// No ' ' and %X specifier together
		// Some flags and types are incompatible
		// Precision can be empty
		// Precision is only for strings but should not fail for numbers
		// No flags that are not expected - cspdiuxX%
		
		printf("|%##5.2X|\n",321);
		printf("|%10d|\n", 1234567890);
	}
	return (0);
}