/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:51:22 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/12 16:01:49 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int ascii)
{
	if ((ascii >= '0' && ascii <= '9') || (ascii >= 'A' && ascii <= 'Z') || (ascii >= 'a' && ascii <= 'z'))
		return (1);
	else
		return (0);
}

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

