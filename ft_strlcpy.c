/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:06:46 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/29 00:38:47 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char	*src, size_t	destsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (destsize == 0)
		return (len);
	i = 0;
	while (i < (destsize - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

/*
//destsize es el largo de dest, tiene que ir acorde sino da -->
 Buffer overflow. Segfault.


int main(void)
{
	char dst1[10];
	char dst2[5];
	size_t ret1, ret2;

	// Test 1: Copia completa
	ret1 = ft_strlcpy(dst1, "Hola", 10);
	printf("Test 1:\n");
	printf("dst: '%s'\n", dst1);   // Debe ser "Hola"
	printf("ret: %zu\n\n", ret1);  // Debe ser 4

	// Test 2: Truncamiento
	ret2 = ft_strlcpy(dst2, "Hola mundo", 5);
	printf("Test 2 (truncado):\n");
	printf("dst: '%s'\n", dst2);   // Debe ser "Hola"
	printf("ret: %zu\n\n", ret2);  // Debe ser 10

	// Test 3: dstsize = 0
	char dst3[5] = "xxxxx";
	size_t ret3 = ft_strlcpy(dst3, "Test", 0);
	printf("Test 3 (dstsize=0):\n");
	printf("dst: '%s'\n", dst3);   // Debe seguir siendo "xxxxx"
	printf("ret: %zu\n\n", ret3);  // Debe ser 4

	return (0);
}

// gcc -Wall -Wextra -Werror ft_strlcpy.c -o test_strlcpy && ./test_strlcpy
*/