/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:29:18 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/16 15:29:18 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length] != '\0')
		length++;
	return (length);
}

#include <stdio.h>

int main() {
	char *texto = "Hola4";
	
	printf("La longitud es: %zu\n", ft_strlen(texto));
	// Salida: La longitud es: 4
	
	return 0;
}