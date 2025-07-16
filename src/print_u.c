/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frckles <frckles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:16:44 by frckles           #+#    #+#             */
/*   Updated: 2025/07/16 16:35:58 by frckles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	num;

	num = 0;
	if (n > 9)
		ft_putunbr_fd(n / 10, fd);
	num = n % 10 + '0';
	write(fd, &num, 1);
}

int print_u(unsigned int n)
{
	int len;
	
	len = uintlen(n);
	ft_putunbr_fd(n, 1);
	return (len);
}
