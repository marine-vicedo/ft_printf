/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_utoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:04:49 by mvicedo           #+#    #+#             */
/*   Updated: 2022/06/10 17:37:40 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_nbrlen(long nbr)
{
	long	len;

	len = 0;
	if (nbr == 0)
		len++;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	len;
	long	nbr;

	nbr = n;
	len = ft_nbrlen(nbr);
	res = malloc(sizeof(char) * len + 1);
	if (res == 0)
		return (NULL);
	res[len] = '\0';
	if (nbr == 0)
		res[0] = '0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		res[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (res);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*res;
	long	len;
	unsigned long	nbr;

	nbr = n;
	len = ft_nbrlen(nbr);
	res = malloc(sizeof(char) * len + 1);
	if (res == 0)
		return (NULL);
	res[len] = '\0';
	if (nbr == 0)
		res[0] = '0';
	while (nbr > 0)
	{
		res[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (res);
}

