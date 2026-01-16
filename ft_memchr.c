/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:27:15 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 16:46:16 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	size_t			i;

	i = 0;
	ss = (unsigned char *)s;
	while (ss[i] != '\0' && i < n)
	{
		if (ss[i] == c)
			return ((char *)&ss[i]);
		else
			i++;
	}
	return (NULL);
}

#include <stdio.h>   // Para printf

int main(void)
{
	const char *str = "Hola mundo";
	char *resultado;

	// Test 1: Buscar 'm'
	resultado = ft_memchr(str, 'm', 10);
	printf("Buscar 'm': %s\n", resultado);  // "mundo"

	// Test 2: Buscar 'o' (primera aparición)
	resultado = ft_memchr(str, 'o', 10);
	printf("Buscar 'o': %s\n", resultado);  // "ola mundo"

	// Test 3: Buscar 'x' (no existe)
	resultado = ft_memchr(str, 'x', 10);
	if (resultado == NULL)
		printf("Buscar 'x': NULL\n");

	// Test 4: Buscar '\0' (el terminador)
	resultado = ft_memchr(str, '\0', 10);
	printf("Buscar '\\0': '%s' (cadena vacía)\n", resultado);  // ""

	// Test 5: Buscar 'H' (primera letra)
	resultado = ft_memchr(str, 'H', 10);
	printf("Buscar 'H': %s\n", resultado);  // "Hola mundo"

	return (0);
}

//gcc -Wall -Wextra -Werror ft_memchr.c -o test_memchr && ./test_memchr