/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:23:22 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/26 14:00:37 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bzero_local(void	*ptr, size_t	len)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)ptr;
	while (i < len)
	{
		p[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero_local(ptr, nmemb * size);
	return (ptr);
}
/*
int main(void)
{
    // Vamos a reservar 3 enteros
    int *std_array = (int *)calloc(3, sizeof(int));
    int *my_array  = (int *)ft_calloc(3, sizeof(int));

    // Comprobamos que empiezan en 0
    printf("Estándar: %d %d %d\n", std_array[0], std_array[1], std_array[2]);
    printf("Mía:       %d %d %d\n", my_array[0], my_array[1], my_array[2]);

    // Escribimos valores distintos
    std_array[0] = 10;
    std_array[1] = 20;
    std_array[2] = 30;

    my_array[0] = 10;
    my_array[1] = 20;
    my_array[2] = 30;

    // Volvemos a imprimir para comprobar que se pueden modificar
    printf("Después de escribir valores:\n");
    printf("Estándar: %d %d %d\n", std_array[0], std_array[1], std_array[2]);
    printf("Mía:       %d %d %d\n", my_array[0], my_array[1], my_array[2]);

    // Liberar memoria
    free(std_array);
    free(my_array);

    return 0;
}


//  gcc -Wall -Wextra -Werror ft_calloc.c -o test_calloc && ./test_calloc
*/