/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 20:11:22 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/14 20:11:22 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	test_header(const char *title)
{
	printf("\n========================================\n");
	printf("  %s\n", title);
	printf("========================================\n");
}

int	main(void)
{
	int		res1;
	int		res2;
	void	*ptr;

	ptr = &res1;
	// 1. CARACTERES Y CADENAS (%c, %s, %%)
	test_header("1. PRUEBAS: %c, %s, %%");
	res1 = ft_printf("ft_printf : %c | %s | %%\n", 'A', "Hola 42");
	res2 = printf("   printf : %c | %s | %%\n", 'A', "Hola 42");
	printf("--> Retornos -> ft_printf: %d | printf: %d\n\n", res1, res2);
	char	*null_str;

	null_str = NULL;
	res1 = ft_printf("ft_printf NULL str : %s\n", null_str);
	res2 = printf("   printf NULL str : %s\n", null_str);
	printf("--> Retornos -> ft_printf: %d | printf: %d\n", res1, res2);
	// 2. ENTEROS CON SIGNO (%d, %i)
	test_header("2. PRUEBAS: %d, %i");
	res1 = ft_printf("ft_printf : %d | %i | %d | %i\n", 0, -42, 1337, INT_MAX);
	res2 = printf("   printf : %d | %i | %d | %i\n", 0, -42, 1337, INT_MAX);
	printf("--> Retornos -> ft_printf: %d | printf: %d\n\n", res1, res2);
	res1 = ft_printf("ft_printf INT_MIN : %d\n", INT_MIN);
	res2 = printf("   printf INT_MIN : %d\n", INT_MIN);
	printf("--> Retornos -> ft_printf: %d | printf: %d\n", res1, res2);
	// 3. ENTEROS SIN SIGNO (%u)
	test_header("3. PRUEBAS: %u");
	res1 = ft_printf("ft_printf : %u | %u\n", 0, UINT_MAX);
	res2 = printf("   printf : %u | %u\n", 0, UINT_MAX);
	printf("--> Retornos -> ft_printf: %d | printf: %d\n", res1, res2);
	// 4. HEXADECIMALES (%x, %X)
	test_header("4. PRUEBAS: %x, %X");
	res1 = ft_printf("ft_printf : %x | %X | %x\n", 0, 255, 3735928559U);
	res2 = printf("   printf : %x | %X | %x\n", 0, 255, 3735928559U);
	printf("--> Retornos -> ft_printf: %d | printf: %d\n", res1, res2);
	// 5. PUNTEROS (%p)
	test_header("5. PRUEBAS: %p");
	res1 = ft_printf("ft_printf ptr : %p\n", ptr);
	res2 = printf("   printf ptr : %p\n", ptr);
	printf("--> Retornos -> ft_printf: %d | printf: %d\n\n", res1, res2);
	res1 = ft_printf("ft_printf NULL ptr : %p\n", NULL);
	res2 = printf("   printf NULL ptr : %p\n", NULL);
	printf("--> Retornos -> ft_printf: %d | printf: %d\n", res1, res2);
	return (0);
}
