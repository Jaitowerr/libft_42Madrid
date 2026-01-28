/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:31:27 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 15:31:27 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char *src, size_t destsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = 0;
	s_len = 0;
	while (dest[d_len] != '\0' && d_len < destsize)
		d_len++;
	while (src[s_len] != '\0')
		s_len++;
	if (d_len == destsize)
		return (destsize + s_len);
	i = 0;
	while (src[i] != '\0' && (d_len + i + 1) < destsize)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}
/*
//medimos lago de dest hasta el nulo, o mientras no lleguemos al 
tamñao de destsize
//medimos src el largo
//comprobamos si d_len es igual que destsize entonces devolvemos 
el destsize + el s_len, lo debería haber sido. 
Es responsabilidad del rpogramaod el destsize

#include <stdio.h>
#include <stddef.h>
#include <string.h>

int main(void)
{
	char dst1[20] = "Hola";
	char dst2[10] = "Hola";
	char dst3[5] = "Hola";
	char src4[7] = " mundo";
	size_t ret;

	// Test 1: Cabe todo
	ret = ft_strlcat(dst1, src4, 20);
	printf("Test 1 (cabe todo):\n");
	printf("dst: '%s'\n", dst1);      // "Hola mundo"
	printf("ret: %zu\n\n", ret);      // 10

	// Test 2: Trunca
	ret = ft_strlcat(dst2, src4, 10);
	printf("Test 2 (trunca):\n");
	printf("dst: '%s'\n", dst2);      // "Hola mund"
	printf("ret: %zu\n\n", ret);      // 10

	// Test 3: destsize <= strlen(dest)
	ret = ft_strlcat(dst3, src4, 3);
	printf("Test 3 (destsize pequeño):\n");
	printf("dst: '%s'\n", dst3);      // "Hola" (sin cambios)
	printf("ret: %zu\n\n", ret);      // 9 (3 + 6)

	return (0);
}


//gcc -Wall -Wextra -Werror ft_strlcat.c -o test_strlcat && ./test_strlcat
*/