/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:52:40 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/12 12:57:42 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int letter)
{
	if ((letter >= 97 && letter <= 122) || (letter >= 65 && letter <= 90))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%i", ft_isalpha('+'));
	return (0);
}
*/
