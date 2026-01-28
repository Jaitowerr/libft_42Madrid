/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:30:18 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 15:30:18 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
#include <stddef.h>     //para size_t
#include <stdio.h>      //para print_f
#include <string.h> // para memcpy original

int main(void)
{
	char src[] = "Hola 42!";
	char dst1[20];
	char dst2[20];
	
	memcpy(dst1, src, 5);
	ft_memcpy(dst2, src, 5);
	
	printf("memcpy:    '%s'\n", dst1);
	printf("ft_memcpy: '%s'\n", dst2);
	
	return (0);
}
	*/