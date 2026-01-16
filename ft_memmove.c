/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:06:08 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/14 18:06:06 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;
	unsigned char	*p;
	size_t		i;

	i = 0;
	temp = (unsigned char *)src;
	p = (unsigned char *)dest;

	while(i < n)
	{
		p[i] = temp[i];
		i++;
	}
	return(0);
}

La función memmove() copia "n" bytes del área de memoria 'src' al área de memoria 'dest'. Las áreas de memoria pueden solaparse: la copia se realiza como si los bytes de 'src' se copiaran primero a una matriz temporal que no se solapa con 'src' ni 'dest', y luego se copiaran de la matriz temporal a 'dest'.


#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "Hello, world!";
    char str2[20];

    ft_memmove(str2, str1, strlen(str1) + 1);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}

#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    int i;
    unsigned char *d;
    unsigned char *s;

    i = 0;
    d = (unsigned char *)dest;
    s = (unsigned char *) src;
    
    if (d > s)
    {       
        while (n--> 0)
            {
                d[n] = s[n];

            }
    }
    else
    {
      while(i < n)
      {
        d[i] = s[i];
        i++;
        
      }
    }
    return(dest);
}


int main()
{
    char str1[] = "Hello, world!";
    char str2[] = "H!!";

    ft_memmove(str2, str1, 5);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}
