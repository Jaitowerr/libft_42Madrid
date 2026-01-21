/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:11:15 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/21 12:11:48 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length] != '\0')
		length++;
	return (length);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (0 <= i)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char    *s2;
    size_t  fin;
    size_t  ini;
    int       i;

    fin = ft_strlen(s1) - 1;
    ini = 0;
    i = 0;

    while (s1[ini] && ft_strrchr(set, s1[ini]) != NULL)
        ini++;
    while (s1[fin] && ft_strrchr(set, s1[fin]) != NULL)
        fin--;
    if (fin - ini > 0)
        i = fin - ini + 1;
    s2 = malloc(sizeof(char) * (i + 1));
    if (!s2)
        return (NULL);
    s2[i] = '\0';
    while (--i >= 0)
        s2[i] = s1[fin--];
    return (s2);
}

int main(void)
{
    char *result;

    // Caso 1: ejemplo dado
    result = ft_strtrim("minHol dsdsnum", "mun");
    printf("1) ft_strtrim(\"minHol dsdsnum\", \"mun\") = \"%s\"\n", result);
    free(result);

    // Caso 2: eliminar caracteres al principio y al final
    result = ft_strtrim("mmmHola mundonnn", "mun");
    printf("2) ft_strtrim(\"mmmHola mundonnn\", \"mun\") = \"%s\"\n", result);
    free(result);

    // Caso 3: eliminar todo
    result = ft_strtrim("mmmnnn", "mun");
    printf("3) ft_strtrim(\"mmmnnn\", \"mun\") = \"%s\"\n", result);
    free(result);

    // Caso 4: sin eliminar nada
    result = ft_strtrim("Hola mundo", "xyz");
    printf("4) ft_strtrim(\"Hola mundo\", \"xyz\") = \"%s\"\n", result);
    free(result);

    // Caso 5: cadena vacía
    result = ft_strtrim("", "mun");
    printf("5) ft_strtrim(\"\", \"mun\") = \"%s\"\n", result);
    free(result);

    // Caso 6: set vacío
    result = ft_strtrim("Hola mundo", "");
    printf("6) ft_strtrim(\"Hola mundo\", \"\") = \"%s\"\n", result);
    free(result);

    return 0;
}

//gcc -Wall -Wextra -Werror ft_strtrim.c -o test_strtrim && ./test_strtrim








