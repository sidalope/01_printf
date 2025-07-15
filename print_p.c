/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frckles <frckles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:16:33 by frckles           #+#    #+#             */
/*   Updated: 2025/07/15 19:59:21 by frckles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	print_p(void *p)
// {
// 	int		n;
// 	char	*hex_chars;
// 	char	address_str[2 + 16 + 1];
// 	size_t	address_bin;

// 	n = sizeof(size_t) * 2;
// 	hex_chars = "0123456789abcdef";
// 	// address_str = ft_calloc(19, 1);
// 	address_bin = (size_t)p;
// 	address_str[0] = '0';
// 	address_str[1] = 'x';
// 	address_str[2 + n - 1] = '\0';
// 	while (n--)
// 	{
// 		address_str[n + 2] = hex_chars[address_bin & 0b1111];
// 		address_bin >>= 4;
// 	}
// 	printf("\nMy address inside function: |%s|\n", address_str);
// 	ft_putstr_fd(address_str, 1);
// 	return (ft_strlen(address_str));
// }

int	print_p(void *p)
{
    int		i;
	int		len;
	int		started;
	size_t	address_bin;

	i = sizeof(size_t) * 2 - 1;
	len = 2;
	started = 0;
	address_bin = (size_t)p;
    if (address_bin == 0) {
		write(1, "(nil)", 5);
        return (5);
    }
	write(1, "0x", 2);
	while (i >= 0)
	{
		if(started || "0123456789abcdef"[(address_bin >> (i * 4)) & 0xF] != '0')
		{
			write(1, &"0123456789abcdef"[(address_bin >> (i * 4)) & 0xF], 1);
			len++;
			started = 1;
		}
		i--;
	}
    return (len);
}
