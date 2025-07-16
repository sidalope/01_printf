/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frckles <frckles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:05:40 by frckles           #+#    #+#             */
/*   Updated: 2025/07/16 17:15:30 by frckles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_unsnbr_fd(unsigned int n, int fd)
{
	unsigned int	num;

	num = 0;
	if (n > 9)
		put_unsnbr_fd(n / 10, fd);
	num = n % 10 + '0';
	write(fd, &num, 1);
}
