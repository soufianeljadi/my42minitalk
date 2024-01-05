/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:18:46 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/04 23:40:02 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	int	kteb_chi_format(char c, va_list arg_p)
{
	unsigned int	count;

	count = 0;
	if (c == '%')
		count += ft_putchar(c);
	else if (c == 'c')
		count += ft_putchar(va_arg(arg_p, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg_p, char *));
	else if (c == 'd' || c == 'i')
		count += ft_put_d(va_arg(arg_p, int), B10);
	else if (c == 'u')
		count += ft_put_u(va_arg(arg_p, unsigned int), B10);
	else if (c == 'X')
		count += ft_put_u(va_arg(arg_p, unsigned int), B16U);
	else if (c == 'x')
		count += ft_put_u(va_arg(arg_p, unsigned int), B16L);
	else if (c == 'p')
		count += (ft_putstr("0x") + ft_put_u(va_arg(arg_p, unsigned ), B16L));
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	count;
	va_list			arg_p;

	va_start(arg_p, str);
	count = 0;
	if (write(1, "", 0) < 0)
		return (-1);
	while (*str != '\0')
	{
		if (*str == '%' && *(str + 1))
		{
			count += kteb_chi_format(*(++str), arg_p);
		}
		else
			count += write(1, str, 1);
		++str;
	}
	va_end(arg_p);
	return (count);
}
