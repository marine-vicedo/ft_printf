/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:04:42 by mvicedo           #+#    #+#             */
/*   Updated: 2022/06/15 15:19:02 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* faire le write a la fin */

/* besoin de ft_putchar (%c), ft_putnbr(%d et %i), ft_putstr(%s) */

/*FONCTION FT_PRINTF
Variadic functions are functions whose total number of elements is unknown at the beginning.
For ex, you could printf(“%s %d”, “hello”, 0), which is 2 things, or printf(“%s %d %c”, “hello”, 0, ‘w’), which is 3 things.
And so on and so forth. You don’t know how many things you’ll have to print before actually starting printing.
*/

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *s)
{
    int i;

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
	else if (str[i] == '%') //pas de va_args a appeler pour % car pas de type
		return(write(1, "%", 1)); // return de write vaut 1
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args; //notre liste d'arguments
	int		len_res; //lenght de notre resultat
	int		i; //compteur qui parcourt toute la str
	
	va_start (args, str); //notre start de liste
	len_res = 0;
	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0') //tant que string existe
	{
		if (str[i] == '%')
		{
			i++; //on passe au code format
			len_res += ft_arg_format(args, i, str);//notre len du res va s'incrementer en fonction du type d'arg. len_res += car il faut ajouter à ren_les le resultat de la conversion (sinon la variable perd la valeur iteree initalement)
		}
		else
			len_res += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (len_res); //lenght de la str sans le '\0' == nb total de caracteres imprimes
}

int	main(void)
{
	int nbr = 2;
	unsigned int nb2 = 6;
	str = "Hello World";
	
	printf("%d\n", ft_printf("C'est le nombre %d qui s'affiche\n", nbr));
	printf("%d\n", printf("C'est le nombre %d qui s'affiche\n", nbr));
	
	printf("%u\n", ft_printf("C'est le nombre %u qui s'affiche\n", nb2));
	printf("%u\n", printf("C'est le nombre %u qui s'affiche\n", nb2));
	
	printf("%d\n", ft_printf("Bonjour  : %s\n", str));
	printf("%d\n", printf("Bonjour : %s\n", str));
}
