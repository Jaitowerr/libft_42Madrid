/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp-REVISAR.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:11:42 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 19:08:46 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ss1[i] != ss2[i])
		{
			if ((ss1[i] - ss2[i]) < 0)
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}
//	return (ss1[i] - ss2[i]);
#include <stdio.h>   // Para printf

int main(void)
{
	int r1;
	int r2;

	// 1) iguales
	r1 = ft_memcmp("Hola", "Hola", 10);
	r2 = memcmp("Hola", "Hola", 10);
	printf("1) \"Hola\" vs \"Hola\" n=10 -> ft=%d | orig=%d\n\n", r1, r2);

	r1 = ft_memcmp("Hola", "Hola", 4);
	r2 = memcmp("Hola", "Hola", 4);
	printf("2) \"Hola\" vs \"Hola\" n=4  -> ft=%d | orig=%d\n\n", r1, r2);

	// 2) diferencia antes de n
	r1 = ft_memcmp("Hola", "Hole", 10);
	r2 = memcmp("Hola", "Hole", 10);
	printf("3) \"Hola\" vs \"Hole\" n=10 -> ft=%d | orig=%d\n\n", r1, r2);

	r1 = ft_memcmp("Hola", "Hole", 4);
	r2 = memcmp("Hola", "Hole", 4);
	printf("4) \"Hola\" vs \"Hole\" n=4  -> ft=%d | orig=%d\n\n", r1, r2);

	// 3) caso clave: solo importan los primeros n
	r1 = ft_memcmp("Holax", "Holay", 4);
	r2 = memcmp("Holax", "Holay", 4);
	printf("5) \"Holax\" vs \"Holay\" n=4 -> ft=%d | orig=%d (debe ser 0)\n\n", r1, r2);

	r1 = ft_memcmp("Holax", "Holay", 5);
	r2 = memcmp("Holax", "Holay", 5);
	printf("6) \"Holax\" vs \"Holay\" n=5 -> ft=%d | orig=%d\n\n", r1, r2);

	// 4) una termina antes
	r1 = ft_memcmp("Hola", "Hola mundo", 10);
	r2 = memcmp("Hola", "Hola mundo", 10);
	printf("7) \"Hola\" vs \"Hola mundo\" n=10 -> ft=%d | orig=%d\n\n", r1, r2);

	r1 = ft_memcmp("Hola mundo", "Hola", 10);
	r2 = memcmp("Hola mundo", "Hola", 10);
	printf("8) \"Hola mundo\" vs \"Hola\" n=10 -> ft=%d | orig=%d\n\n", r1, r2);

	// 5) n = 0 (siempre 0)
	r1 = ft_memcmp("AAAA", "BBBB", 0);
	r2 = memcmp("AAAA", "BBBB", 0);
	printf("9) \"AAAA\" vs \"BBBB\" n=0 -> ft=%d | orig=%d (debe ser 0)\n\n", r1, r2);

	// 6) strings vacías / comparación con '\0' implícita
	r1 = ft_memcmp("", "a", 1);
	r2 = memcmp("", "a", 1);
	printf("10) \"\" vs \"a\" n=1 -> ft=%d | orig=%d\n\n", r1, r2);

	r1 = ft_memcmp("a", "", 1);
	r2 = memcmp("a", "", 1);
	printf("11) \"a\" vs \"\" n=1 -> ft=%d | orig=%d\n\n", r1, r2);

	return (0);
}


//  gcc -Wall -Wextra -Werror ft_memcmp-REVISAR.c -o test_memcmp && ./test_memcmp