/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:10:58 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 15:10:58 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*ptr, size_t	len)
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
/*
#include <stddef.h>     //para size_t
#include <stdio.h>      //para print_f

#include <strings.h> // para bzero original

int main(void)
{
	char str1[20] = "Hola 42!";
	char str2[20] = "Hola 42!";
	
	printf("Antes:\n");
	printf("str1: '%s'\n", str1);
	printf("str2: '%s'\n\n", str2);
	
	bzero(str1, 5);
	ft_bzero(str2, 5);
	
	printf("Después:\n");
	printf("bzero:    '%s'\n", str1);
	printf("ft_bzero: '%s'\n", str2);
	
	return (0);
}
//p = (unsigned char *)ptr;	//Casteo

*/