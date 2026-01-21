/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:47:00 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/21 00:35:55 by aitorres         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char    *str;
    size_t  s_len;
    size_t  i;

    s_len = ft_strlen(s);
    if (start >= s_len)
    {
        str = malloc(sizeof(char) * 1);
        if (!str)
            return (NULL);
        str[0] = '\0';
        return (str);  //return (str[0] = '\0', str);
    }
    if (len > s_len - start)
        len = s_len - start;
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (i < len)
        str[i++] = s[start++];
    str[i] = '\0';
    return (str);
}



int main(void)
{
    char *result;

    // Test 1: subcadena normal
    result = ft_substr("Hola mundo", 5, 5);
    printf("1) ft_substr(\"Hola mundo\", 5, 5) = \"%s\"\n", result);
    free(result);

    // Test 2: len mayor que lo que queda
    result = ft_substr("Hola", 1, 10);
    printf("2) ft_substr(\"Hola\", 1, 10) = \"%s\"\n", result);
    free(result);

    // Test 3: start fuera de rango
    result = ft_substr("Hola", 10, 5);
    printf("3) ft_substr(\"Hola\", 10, 5) = \"%s\" (vacía)\n", result);
    free(result);

    // Test 4: len = 0
    result = ft_substr("Hola", 0, 0);
    printf("4) ft_substr(\"Hola\", 0, 0) = \"%s\" (vacía)\n", result);
    free(result);

    // Test 5: desde el principio
    result = ft_substr("Hola", 0, 4);
    printf("5) ft_substr(\"Hola\", 0, 4) = \"%s\"\n", result);
    free(result);

    // Test 6: un solo carácter
    result = ft_substr("Hola", 2, 1);
    printf("6) ft_substr(\"Hola\", 2, 1) = \"%s\"\n", result);
    free(result);

    return (0);
}