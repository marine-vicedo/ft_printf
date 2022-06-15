/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:04:45 by mvicedo           #+#    #+#             */
/*   Updated: 2022/06/15 12:35:29 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static int	ft_nbrlen_hex(unsigned int nbr)
{
	unsigned int	len;

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

int	ft_print_hex(unsigned int n, char *base)
{
	if (n < 16)
		write(1, &base[n], 1); //ecrit les char de 0 a F
	else
	{
		ft_print_hex(n / 16, base);
		ft_print_hex(n % 16, base);
	}
	return (ft_nbrlen_hex(n));
}

/*int	main (void)
{
	printf("%d\n", ft_print_hex(1, "0123456789ABCDEF"));

}*/