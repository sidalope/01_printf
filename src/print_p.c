/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frckles <frckles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:16:33 by frckles           #+#    #+#             */
/*   Updated: 2025/07/16 16:35:53 by frckles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
