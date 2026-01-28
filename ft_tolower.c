/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:32:12 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 15:32:12 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>

int ft_tolower(int c);

int main(void)
{
	printf("'A' -> '%c'\n", ft_tolower('A'));  // Debe salir 'a'
	printf("'Z' -> '%c'\n", ft_tolower('Z'));  // Debe salir 'z'
	printf("'90' -> '%d'\n", ft_tolower(90));  // Debe salir 'z'
	printf("'a' -> '%c'\n", ft_tolower('a'));  // Debe salir 'a' (sin cambios)
	printf("'5' -> '%c'\n", ft_tolower('5'));  // Debe salir '5' (sin cambios)
	printf("'.' -> '%c'\n", ft_tolower('5'));  // Debe salir '5' (sin cambios)
	
	return (0);
}

//  gcc -Wall -Wextra -Werror ft_tolower.c -o test_tolower && ./test_tolower
*/