/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:18:41 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/12 15:50:52 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
