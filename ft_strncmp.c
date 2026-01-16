/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:33:54 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 15:33:54 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>   // Para printf
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (a[i] != '\0' && b[i] != '\0' && i < n)
	{
		if (a[i] == b[i])
			i++;
		else
			break ;
	}
	if (i == n)
		return (0);
	if (a[i] != b[i])
		return (a[i] - b[i]);
	return (0);
}

int main(void)
{
	int r1;
	int r2;

	// 1) iguales
	r1 = ft_strncmp("Hola", "Hola", 10);
	r2 = strncmp("Hola", "Hola", 10);
	printf("1) \"Hola\" vs \"Hola\" n=10 -> ft=%d | orig=%d\n", r1, r2);

	r1 = ft_strncmp("Hola", "Hola", 4);
	r2 = strncmp("Hola", "Hola", 4);
	printf("2) \"Hola\" vs \"Hola\" n=4  -> ft=%d | orig=%d\n", r1, r2);

	// 2) diferencia antes de n
	r1 = ft_strncmp("Hola", "Hole", 10);
	r2 = strncmp("Hola", "Hole", 10);
	printf("3) \"Hola\" vs \"Hole\" n=10 -> ft=%d | orig=%d\n", r1, r2);

	r1 = ft_strncmp("Hola", "Hole", 4);
	r2 = strncmp("Hola", "Hole", 4);
	printf("4) \"Hola\" vs \"Hole\" n=4  -> ft=%d | orig=%d\n", r1, r2);

	// 3) caso clave: solo importan los primeros n
	r1 = ft_strncmp("Holax", "Holay", 4);
	r2 = strncmp("Holax", "Holay", 4);
	printf("5) \"Holax\" vs \"Holay\" n=4 -> ft=%d | orig=%d (debe ser 0)\n", r1, r2);

	r1 = ft_strncmp("Holax", "Holay", 5);
	r2 = strncmp("Holax", "Holay", 5);
	printf("6) \"Holax\" vs \"Holay\" n=5 -> ft=%d | orig=%d\n", r1, r2);

	// 4) una termina antes
	r1 = ft_strncmp("Hola", "Hola mundo", 10);
	r2 = strncmp("Hola", "Hola mundo", 10);
	printf("7) \"Hola\" vs \"Hola mundo\" n=10 -> ft=%d | orig=%d\n", r1, r2);

	r1 = ft_strncmp("Hola mundo", "Hola", 10);
	r2 = strncmp("Hola mundo", "Hola", 10);
	printf("8) \"Hola mundo\" vs \"Hola\" n=10 -> ft=%d | orig=%d\n", r1, r2);

	// 5) n = 0 (siempre 0)
	r1 = ft_strncmp("AAAA", "BBBB", 0);
	r2 = strncmp("AAAA", "BBBB", 0);
	printf("9) \"AAAA\" vs \"BBBB\" n=0 -> ft=%d | orig=%d (debe ser 0)\n", r1, r2);

	// 6) strings vacías / comparación con '\0' implícita
	r1 = ft_strncmp("", "a", 1);
	r2 = strncmp("", "a", 1);
	printf("10) \"\" vs \"a\" n=1 -> ft=%d | orig=%d\n", r1, r2);

	r1 = ft_strncmp("a", "", 1);
	r2 = strncmp("a", "", 1);
	printf("11) \"a\" vs \"\" n=1 -> ft=%d | orig=%d\n", r1, r2);

	return (0);
}


//  gcc -Wall -Wextra -Werror ft_strncmp.c -o test_strncmp && ./test_strncmp