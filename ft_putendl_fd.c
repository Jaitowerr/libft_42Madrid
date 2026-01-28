/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:50:42 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/26 14:01:08 by aitorres         ###   ########.fr       */
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

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

	i = ft_strlen_local(s);
	write(fd, s, i);
	write(fd, "\n", 1);
}
/*
int	main(void)
{
    char *mensaje = "Hola, esto es una prueba de ft_putstr_fd";
    char *error = "¡Ups! Algo ha salido mal (pero en el canal 2)";

    ft_putendl_fd(mensaje, 1);	// salida estándar
    ft_putendl_fd(error, 2);	//salida de errores

    return (0);
}

// cc -Wall -Wextra -Werror ft_putendl_fd.c -o test_ft_putendl_fd && ./test_ft_putendl_fd
*/