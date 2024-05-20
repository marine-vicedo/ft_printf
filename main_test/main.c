#include "ft_printf.h"

int	main(void)
{
	char c = 'a';
	int nbr = 2;
	unsigned int nb2 = 6;
	unsigned int hex = 158;
	char *str = "Hello World";
	
	printf("%d\n", ft_printf("C'est la lettre %c qui s'affiche\n", c));
	printf("%d\n", printf("C'est la lettre %d qui s'affiche\n", c));
	
	printf("%d\n", ft_printf("C'est le nombre %d qui s'affiche\n", nbr));
	printf("%d\n", printf("C'est le nombre %d qui s'affiche\n", nbr));
	
	printf("%d\n", ft_printf("C'est le nombre %u qui s'affiche\n", nb2));
	printf("%d\n", printf("C'est le nombre %u qui s'affiche\n", nb2));

	printf("%d\n", ft_printf("C'est la valeur %x qui s'affiche\n", hex));
	printf("%d\n", printf("C'est la valeur %x qui s'affiche\n", hex));
	
	printf("%d\n", ft_printf("Bonjour : %s\n", str));
	printf("%d\n", printf("Bonjour : %s\n", str));
}