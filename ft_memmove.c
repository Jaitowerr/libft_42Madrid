/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:06:08 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 16:19:05 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>   // Para printf
#include <string.h>  // Para memmove original
#include <stddef.h>  // Para size_t

void	*ft_memmove(void	*dest, const void	*src, size_t	n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (d < s)
	{
		i = -1;
		while (i++ < n)
			d[i] = s[i];
	}
	else if (d > s)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}

// protección por si ambos son NULL
//comprobamos que d sea mas pequeño que s, realmente que vaya antes ya que 'd' está recortado de s, su dirección de memoria será mas pequeña, entocnes is es menor o igual, entras
//La función memmove() copia "n" bytes del área de memoria 'src' al área de memoria 'dest'. Las áreas de memoria pueden solaparse: la copia se realiza como si los bytes de 'src' se copiaran primero a una matriz temporal que no se solapa con 'src' ni 'dest', y luego se copiaran de la matriz temporal a 'dest'.

int main(void)
{
	// TEST 1: Solapamiento hacia la derecha (d > s)
	char str1[] = "123456789";
	char str2[] = "123456789";
	
	memmove(str1 + 2, str1, 7);
	ft_memmove(str2 + 2, str2, 7);
	
	printf("TEST 1 (d > s):\n");
	printf("Original: %s\n", str1);
	printf("Tuya:     %s\n\n", str2);

	// TEST 2: Solapamiento hacia la izquierda (d < s)
	char str3[] = "abcdefg";
	char str4[] = "abcdefg";
	
	memmove(str3, str3 + 2, 3);
	ft_memmove(str4, str4 + 2, 3);
	
	printf("TEST 2 (d < s):\n");
	printf("Original: %s\n", str3);
	printf("Tuya:     %s\n\n", str4);

	// TEST 3: Caso NULL
	printf("TEST 3 (NULL):\n");
	void *res = ft_memmove(NULL, NULL, 5);
	if (res == NULL)
		printf("Resultado: NULL (Correcto)\n");
	else
		printf("Resultado: No es NULL (Revisar)\n");

	return (0);
}