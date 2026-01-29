/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:32:27 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 15:32:27 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (0 <= i)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
int main(void)
{
	const char *str = "Hola mundo";
	char *resultado;

	// Test 1: Buscar 'm'
	resultado = ft_strrchr(str, 'm');
	printf("Buscar 'm': %s\n", resultado);  // "mundo"

	// Test 2: Buscar 'o' (primera aparición)
	resultado = ft_strrchr(str, 'o');
	printf("Buscar 'o': %s\n", resultado);  // "ola mundo"

	// Test 3: Buscar 'x' (no existe)
	resultado = ft_strrchr(str, 'x');
	if (resultado == NULL)
		printf("Buscar 'x': NULL\n");

	// Test 4: Buscar '\0' (el terminador)
	resultado = ft_strrchr(str, '\0');
	printf("Buscar '\\0': '%s' (cadena vacía)\n", resultado);  // ""

	// Test 5: Buscar 'H' (primera letra)
	resultado = ft_strrchr(str, 'H');
	printf("Buscar 'H': %s\n", resultado);  // "Hola mundo"

	return (0);
}

//  gcc -Wall -Wextra -Werror ft_strrchr.c -o test_strrchr && ./test_strrchr
*/