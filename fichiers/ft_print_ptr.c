/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:55:32 by mvicedo           #+#    #+#             */
/*   Updated: 2022/06/13 17:08:07 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen_long(unsigned long nbr)
{
	unsigned long	len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static int	ft_print_hex_p(unsigned long n, char *base)
{
	if (n < 16)
		write(1, &base[n], 1); //ecrit les char de 0 a F
	else
	{
		ft_print_hex_p(n / 16, base);
		ft_print_hex_p(n % 16, base);
	}
	return (ft_nbrlen_long(n));
}

int	ft_print_ptr(unsigned long n, char *base)
{
	if (!n)
	{
		write(1, PTR_NULL, 5);
		return (5);
	}
	write(1, "0x", 2);
	n = ft_print_hex_p(n, base);
	return (n + 2);
}
