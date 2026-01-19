/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:29:47 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 15:29:47 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, int x, size_t len)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)ptr;
	while (i < len)
	{
		p[i] = (unsigned char)x;
		i++;
	}
	return (ptr);
}


//Hacemos esa conversión (llamada casting) por una razón fundamental: void * no se puede usar para trabajar, así forzamos la conversión de este puntero a este tipo específico, no sirve solo con especificarlo en p, hay que hacerlo en ambos.
#include <stdio.h>

int main()
{

	char str[20];
	ft_memset(str, 'A', 10);
	str[10] = '\0';
	printf("Ejemplo 1 - String con 'A': %s\n", str);
	

	int numeros[5];
	ft_memset(numeros, 0, sizeof(numeros));
	printf("Ejemplo 2 - Array de enteros a cero:\n");
	for (int i = 0; i < 5; i++)
		printf("  numeros[%d] = %d\n", i, numeros[i]);
	

	char buffer[15] = "Hola Mundo";
	printf("Ejemplo 3 - Antes: '%s'\n", buffer);
	ft_memset(buffer, 'X', 4);
	printf("Ejemplo 3 - Después: '%s'\n", buffer);
	

	char datos[30] = "Información secreta";
	printf("Ejemplo 4 - Antes: '%s'\n", datos);
	ft_memset(datos, '\0', sizeof(datos));
	printf("Ejemplo 4 - Después: '%s' (vacío)\n", datos);
	

	unsigned char bytes[10];
	ft_memset(bytes, 255, sizeof(bytes));
	printf("Ejemplo 5 - Bytes con valor 255:\n");
	for (int i = 0; i < 10; i++)
		printf("  bytes[%d] = %u\n", i, bytes[i]);
	
	return (0);
}

//  gcc -Wall -Wextra -Werror ft_memset.c -o test_memset && ./test_memset