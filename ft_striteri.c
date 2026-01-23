/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:21:55 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/23 17:58:57 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
void	mi_funcion_magica(unsigned int i, char *c)
{
	if (i % 2 == 0 && (*c >= 'a' && *c <= 'z'))
	{
		*c = *c - 32;
	}
	printf("Procesando índice %u: ahora el carácter es '%c'\n", i, *c);
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	char	cadena[] = "hola mundo, probando ft_striteri y 4444";

	printf("Cadena original: %s\n\n", cadena);

	ft_striteri(cadena, mi_funcion_magica);

	printf("\nResultado final: %s\n", cadena);

	return (0);
}

// cc -Wall -Wextra -Werror ft_striteri.c -o test_striteri && ./test_striteri