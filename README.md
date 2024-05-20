# ft_printf

ft_printf is a project that involves implementing a custom version of the standard C library function printf. The project also introduces the concept of variadic functions, which enable functions to accept a variable number of arguments

The following conversions are implemented :

%c : Displays a single character.

%s : Displays a string of characters (as defined by the C convention).

%p : The void * pointer argument is displayed in hexadecimal.

%d : Displays a decimal number (base 10).

%i : Displays an integer in base 10.

%u: Displays an unsigned decimal number (base 10).

%x : Displays a number in hexadecimal (base 16) with lowercase letters.

%X : Displays a number in hexadecimal (base 16) with uppercase letters.

%% : Displays a percentage sign


## Getting Started

Compile with : ```make``` to create the library

Compile our lib with a main.c file : ```gcc main.c libftprintf.a```

and execute : ```./a.out```
