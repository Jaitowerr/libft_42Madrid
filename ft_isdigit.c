/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:18:41 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/26 13:37:17 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
    printf("%d\n", ft_isdigit('5'));
    printf("%d\n", ft_isdigit(5));
    printf("%d\n", ft_isdigit('a'));
	return (0);
}*/
