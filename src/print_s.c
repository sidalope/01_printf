/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:52:38 by abisiani          #+#    #+#             */
/*   Updated: 2025/09/15 11:38:27 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(void *s)
{
	int		len;
	char	*str;

	len = 0;
	if ((size_t)s == 0)
		return (write(2, "Error: %s encountered (nil)", 27), 0);
	str = (char *) s;
		while (*str)
	{
		write(1, str, 1);
		len++;
		str++;
	}
	return (len);
}
