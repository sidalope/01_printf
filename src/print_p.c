/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frckles <frckles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:16:33 by frckles           #+#    #+#             */
/*   Updated: 2025/07/16 18:26:38 by frckles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(void *p)
{
	int		i;
	int		len;
	int		strt;

	i = sizeof(size_t) * 2 - 1;
	len = 2;
	strt = 0;
	if ((size_t)p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	while (i >= 0)
	{
		if (strt || "0123456789abcdef"[((size_t)p >> (i * 4)) & 0xF] != '0')
		{
			write(1, &"0123456789abcdef"[((size_t)p >> (i * 4)) & 0xF], 1);
			len++;
			strt = 1;
		}
		i--;
	}
	return (len);
}
