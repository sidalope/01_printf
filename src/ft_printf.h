/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frckles <frckles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:37:02 by abisiani          #+#    #+#             */
/*   Updated: 2025/07/16 18:30:52 by frckles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		intlen(int n);
int		uintlen(unsigned int n);
void	put_unsnbr_fd(unsigned int n, int fd);
int		print_c(int c);
int		print_s(char *s);
int		print_p(void *ptr);
int		print_di(int n);
int		print_u(unsigned int n);
int		print_x(unsigned int n);
int		print_x_cap(unsigned int n);
int		print_perc(void);