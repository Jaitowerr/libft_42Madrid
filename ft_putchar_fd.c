/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:59:26 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/23 18:29:34 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	main(void)
{
    // Escribimos una 'A'
    ft_putchar_fd('A', 1);
    ft_putchar_fd('\n', 1);
    // Escribimos una 'E' en la salida de errores
    ft_putchar_fd('E', 2);
    ft_putchar_fd('\n', 2);

    return (0);
}

// cc -Wall -Wextra -Werror ft_putchar_fd.c -o test_ft_putchar_fd && ./test_ft_putchar_fd