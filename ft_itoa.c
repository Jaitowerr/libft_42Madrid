/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:08:05 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/21 20:08:05 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <limits.h>

char *ft_itoa(int n)
{
    char    *word;
    long    numb;
    int     size;
    int     sig;
    int     i;

    sig = 0;
    numb = n;
    size = 0;
    if( numb < 0)
    {
        sig = -1;
        numb = -numb;
        size++;
    }
    
    while (numb > 9)   //si se puede dividir entra.
    {
        numb = numb / 10;
        size++;
    }
    if (numb >= 0 && numb <= 9)
        size++;


    numb = n;
    if( numb < 0)
        numb = -numb;
    word = malloc(sizeof(char) * (size + 1));   //tamaño de word
    if (!word)
        return (NULL);
    word[size] = '\0';  //ultima posicion nulo
    i = 0;
    if (sig < 0)
        word[i++] = '-';  //primera si es negativo el signo

    while (numb > 9)
    {
        // size;
        word[--size] = (numb % 10) + '0';
        numb = numb / 10;
    }
    if (numb >=0 && numb <=9)
        word[--size] = numb + '0';
    return (word);

}





int main(void)
{
    char *result;

    // Casos normales
    result = ft_itoa(123);
    printf("123 -> %s\n", result ? result : "(null)");
    free(result);

    result = ft_itoa(-123);
    printf("-123 -> %s\n", result ? result : "(null)");
    free(result);

    result = ft_itoa(0);
    printf("0 -> %s\n", result ? result : "(null)");
    free(result);

    // Casos límite
    result = ft_itoa(INT_MAX); // 2147483647
    printf("INT_MAX -> %s\n", result ? result : "(null)");
    free(result);

    result = ft_itoa(INT_MIN); // -2147483648
    printf("INT_MIN -> %s\n", result ? result : "(null)");
    free(result);

    // Otros casos
    result = ft_itoa(1000000);
    printf("1000000 -> %s\n", result ? result : "(null)");
    free(result);

    result = ft_itoa(-1);
    printf("-1 -> %s\n", result ? result : "(null)");
    free(result);

    return (0);
}

// cc -Wall -Wextra -Werror ft_itoa.c -o test_itoa && ./test_itoa
