/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:55:54 by mvicedo           #+#    #+#             */
/*   Updated: 2022/06/15 12:54:37 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if defined (APPLE)
#  define PTR_NULL "0x0"
# elif linux
#  define PTR_NULL "(nil)"
# endif

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

int				ft_printf(const char *str, ...);
int				ft_arg_format(va_list args, int i, const char *str);
int				ft_putchar(int c);
int				ft_putstr(char *s);
void			ft_putnbr(int n);
void			ft_unsigned_putnbr(unsigned int n);
int				ft_print_hex(unsigned int n, char *base);
int				ft_print_ptr(unsigned long n, char *base);
unsigned int	ft_printf_numbers_i(int nbr);
unsigned int	ft_printf_numbers_u(unsigned int nbr);
unsigned int	ft_nbrlen(long nbr);
#endif
