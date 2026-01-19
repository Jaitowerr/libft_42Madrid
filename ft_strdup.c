/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:12:55 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/19 17:43:34 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Para strdup

size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int main(void)
{
    const char *original = "Hola Mundo";

    // Usando la función estándar
    //char *std_copy = strdup(original);

    // Usando tu función
    char *my_copy = ft_strdup(original);

    // Imprimimos resultados
    printf("Original: %s\n", original);
    //printf("strdup estándar: %s\n", std_copy);
    printf("ft_strdup mía:   %s\n", my_copy);

    // Modificamos las copias para demostrar que son independientes
    //std_copy[0] = 'h';
    my_copy[1]  = '8';

    printf("Después de modificar las copias:\n");
    //printf("strdup estándar: %s\n", std_copy);
    printf("ft_strdup mía:   %s\n", my_copy);
    printf("Original:        %s\n", original);

    // Liberamos memoria
    //free(std_copy);
    free(my_copy);

    return 0;
}

//  gcc -Wall -Wextra -Werror ft_strdup.c -o test_strdup && ./test_strdup