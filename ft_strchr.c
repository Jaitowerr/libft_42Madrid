/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:33:38 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 15:33:38 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

#include <stdio.h>   // Para printf
#include <string.h>
//#include <stddef.h>  // Para size_t

int main(void)
{
	const char *str = "Hola mundo";
	char *resultado;

	// Test 1: Buscar 'm'
	resultado = ft_strchr(str, 'm');
	printf("Buscar 'm': %s\n", resultado);  // "mundo"

	// Test 2: Buscar 'o' (primera aparición)
	resultado = ft_strchr(str, 'o');
	printf("Buscar 'o': %s\n", resultado);  // "ola mundo"

	// Test 3: Buscar 'x' (no existe)
	resultado = ft_strchr(str, 'x');
	if (resultado == NULL)
		printf("Buscar 'x': NULL\n");

	// Test 4: Buscar '\0' (el terminador)
	resultado = ft_strchr(str, '\0');
	printf("Buscar '\\0': '%s' (cadena vacía)\n", resultado);  // ""

	// Test 5: Buscar 'H' (primera letra)
	resultado = ft_strchr(str, 'H');
	printf("Buscar 'H': %s\n", resultado);  // "Hola mundo"

	return (0);
}

//gcc -Wall -Wextra -Werror ft_strchr.c -o test_strchr && ./test_strchr