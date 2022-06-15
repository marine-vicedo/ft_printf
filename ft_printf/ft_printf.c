/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:04:42 by mvicedo           #+#    #+#             */
/*   Updated: 2022/06/15 12:56:09 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_arg_format(va_list args, int i, const char *str)
{	
	if (str[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_printf_numbers_i(va_arg(args, int)));
	else if (str[i] == 'u')
		return (ft_printf_numbers_u(va_arg(args, unsigned int)));
	else if (str[i] == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (str[i] == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (str[i] == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long), "0123456789abcdef"));
	else if (str[i] == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len_res;
	int		i;

	va_start (args, str);
	len_res = 0;
	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len_res += ft_arg_format(args, i, str);
		}
		else
			len_res += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (len_res);
}
