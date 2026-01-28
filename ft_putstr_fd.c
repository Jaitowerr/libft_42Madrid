/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:25:59 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/26 13:57:30 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_local(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length] != '\0')
		length++;
	return (length);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = ft_strlen_local(s);
	write(fd, s, i);
}
/*
int	main(void)
{
    char *mensaje = "Hola, esto es una prueba de ft_putstr_fd\n";
    char *error = "¡Ups! Algo ha salido mal (pero en el canal 2)\n";

    ft_putstr_fd(mensaje, 1);	// salida estándar
    ft_putstr_fd(error, 2);	//salida de errores

    return (0);
}

// gcc -Wall -Wextra -Werror ft_putstr_fd.c -o test_ft_putstr_fd && ./test_ft_putstr_fd
*/