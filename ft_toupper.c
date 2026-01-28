/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:31:54 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 15:31:54 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>

int ft_toupper(int c);

int main(void)
{
	printf("'a' -> '%c'\n", ft_toupper('a'));  // 'A'
	printf("'z' -> '%c'\n", ft_toupper('z'));  // 'Z'
	printf("'A' -> '%c'\n", ft_toupper('A'));  // 'A' (sin cambios)
	printf("'5' -> '%c'\n", ft_toupper('5'));  // '5' (sin cambios)
	printf("'.' -> '%c'\n", ft_toupper('.'));  // '.' (sin cambios)
	
	return (0);
}

//gcc -Wall -Wextra -Werror ft_toupper.c -o test_toupper && ./test_toupper
*/