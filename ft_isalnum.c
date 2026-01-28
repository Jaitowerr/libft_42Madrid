/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:51:22 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/26 13:38:17 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int ascii)
{
	if ((ascii >= '0' && ascii <= '9'))
		return (1);
	else if ((ascii >= 'A' && ascii <= 'Z') || (ascii >= 'a' && ascii <= 'z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%i", ft_isalnum('5'));
	printf("%i", ft_isalnum('g'));
	printf("%i", ft_isalnum('H'));
	printf("%i", ft_isalnum(5));
	printf("%i", ft_isalnum('+'));
	return (0);
}
*/