/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:22:32 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/28 21:41:48 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	printf("ft_isprint('A'): %d (esperado: 1)\n", ft_isprint('A'));

	printf("ft_isprint(' '): %d (esperado: 1)\n", ft_isprint(' '));

	printf("ft_isprint('\\n'): %d (esperado: 0)\n", ft_isprint('\n'));

	printf("ft_isprint('~'): %d (esperado: 1)\n", ft_isprint('~'));

	printf("ft_isprint(127): %d (esperado: 0)\n", ft_isprint(127));

	return (0);
}
*/