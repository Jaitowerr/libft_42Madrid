/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:59:41 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/23 19:26:20 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	numb;

	numb = n;
	if (numb < 0)
	{
		ft_putchar_fd('-', fd);
		numb = -numb;
	}
	if (numb > 9)
		ft_putnbr_fd((numb / 10), fd);
	ft_putchar_fd((numb % 10) + '0', fd);
}

#include <unistd.h>
#include <limits.h>

int main(void)
{
	// Prueba 1: Un número de un solo dígito
	write(1, "Prueba 7: ", 10);
	ft_putnbr_fd(7, 1);
	write(1, "\n\n", 2);

	// Prueba 2: Un número de dos dígitos
	write(1, "Prueba 42: ", 11);
	ft_putnbr_fd(42, 1);
	write(1, "\n\n", 2);

	// Prueba 3: Un número negativo
	write(1, "Prueba -15: ", 12);
	ft_putnbr_fd(-15, 1);
	write(1, "\n\n", 2);

	// Prueba 4: Un número grande (aquí verás si tu lógica escala)
	write(1, "Prueba 1234: ", 13);
	ft_putnbr_fd(1234, 1);
	write(1, "\n\n", 2);

	// Prueba 5: El número más pequeño posible
	write(1, "Prueba INT_MIN: ", 16);
	ft_putnbr_fd(INT_MIN, 1);
	write(1, "\n\n", 2);

	// Prueba 6: El número más grande posible
	write(1, "Prueba INT_MAX: ", 16);
	ft_putnbr_fd(INT_MAX, 1);
	write(1, "\n", 1);
	
	return (0);
}

// cc -Wall -Wextra -Werror ft_putnbr_fd.c -o test_ft_putnbr_fd && ./test_ft_putnbr_fd