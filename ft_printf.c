/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:35:09 by abisiani          #+#    #+#             */
/*   Updated: 2025/06/10 23:43:16 by abisiani         ###   ########.fr       */
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

// - = left align the output (default sis to right-align)
// 0 = when width is specified, prepends 0s for numeric types (instead of spaces)
// . = a max length of the output, depending on the formatting type. 
// # = 
//   = prepends a space for positive values (ignored if + exists)
// + = prepends a plus sign for a positive value

// Find length of formatter
// strchr for each, setting local flags
// if + ~prepend plusses, else if ' ' prepend spaces

// How the fuck can i do this with max 5 local vars?
// Necessary format per format specifier:
// 		%[flags][width][.precision] type
// 


int	ft_printf(const char *format, ...)
{
	return (0);
}
