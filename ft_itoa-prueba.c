/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:08:05 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/22 16:09:54 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_counter(long n)
{
	int	i;
	int	num;

	num = n;
	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*word;
	int		len;
	long	nbr;


	int		sig;
	int		count;
	int		i;

	count = 0;
	sig = 0;
	if (n < 0)
	{
		sig--;
		count++;
	}
	count = count + ft_counter(n);
	word = malloc(sizeof(char) * (count + 1));
	if (!word)
		return (NULL);
	word[count] = '\0';
	count--;
	while (count > 0)
	{
		i = (n % 10);
		if (i < 0)
			i = -i;
		word[count] = (i + '0');
		n = n / 10;
		count--;
	}
	if (sig < 0)
		word[0] = '-';
	return (word);
}


#include <stdio.h>
#include <stdlib.h>

char    *ft_itoa(int n); // Declaración de tu función

int main(void)
{
	int tests[] = {0, 1, -1, 42, -42, 123456, -2147483648, 2147483647};
	int size = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < size; i++)
	{
		char *result = ft_itoa(tests[i]);
		printf("ft_itoa(%d) = %s\n", tests[i], result);
		free(result); // Recuerda liberar si tu ft_itoa usa malloc
	}

	return 0;
}
