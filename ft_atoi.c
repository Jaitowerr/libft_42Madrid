/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:04:24 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/26 13:37:42 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned char	*atoi;
	int				i;
	int				numb;
	int				sig;

	sig = 1;
	i = 0;
	numb = 0;
	atoi = (unsigned char *) nptr;
	while (atoi[i] == 32 || (atoi[i] >= 9 && atoi[i] <= 13))
		i++;
	if (atoi[i] == ('-') || atoi[i] == ('+'))
	{
		if (atoi[i] == ('-'))
			sig = sig * -1;
		i++;
	}
	while (atoi[i] >= '0' && atoi[i] <= '9')
	{
		numb = (numb * 10) + (atoi[i] - '0');
		i++;
	}
	return (sig * numb);
}
/*
#include <stdio.h>
#include <stdlib.h> 

void test(const char *str)
{
	int orig = atoi(str);    /#include <stdio.h>
#include <stdlib.h>

char    *ft_itoa(int n); // Declaración de tu función

int main(void)
{
    int tests[] = {0, 1, -1, 42, -42, 123456, -2147483648, 2147483647};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        char *result = ft_itoa(tests[i]);
        printf("ft_itoa(%d) = %s\n", tests[i], result);
        free(result); // Recuerda liberar si tu ft_itoa usa malloc
    }

    return 0;
}

	int mine = ft_atoi(str); // Usando tu implementación ft_atoi

	printf("Probando: \"%s\"\n", str);
	printf("atoi:    %d\n", orig);
	printf("ft_atoi: %d\n", mine);
	printf("----------------------\n");
}

int main(void)
{
	// Casos de prueba variados
	test("  1234");        // Espacios al principio
	test("-1234");         // Número negativo
	test("+1234");         // Número positivo
	test("  + 1234");      // Espacios después del signo
	test("  -  1234");     // Espacios después del signo
	test("  -  45ab67");   // Cadena con caracteres no numéricos
	test("  42abc");       // Cadena con caracteres no numéricos
	test("   ");           // Cadena vacía
	test("   -42");        // Número negativo con espacios al principio
	test("+-42");          // Varios signos consecutivos
	test("   0001234");    // Ceros a la izquierda
	test("-+42");          // Varios signos consecutivos

	return 0;
}

//  gcc -Wall -Wextra -Werror ft_atoi.c -o test_atoi && ./test_atoi

*/