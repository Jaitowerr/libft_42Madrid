/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:41:32 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/29 14:55:10 by aitorres         ###   ########.fr       */
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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;
	size_t	n;

	len_little = ft_strlen_local(little);
	i = 0;
	if (!little || len_little == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i + len_little <= len)
	{
		n = 0;
		while (big[i + n] == little[n] && (i + n) < len)
		{
			if (little[n + 1] == '\0')
				return ((char *) &big[i]);
			n++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

void	test(const char *big, const char *little, size_t len)
{
//	char *orig;
	char *mine;

	//orig = strnstr(big, little, len);
	mine = ft_strnstr(big, little, len);

	printf("BIG: \"%s\"\n", big);
	printf("LITTLE: \"%s\"\n", little);
	printf("LEN: %zu\n", len);

//	printf("strnstr     : %s\n", orig ? orig : "NULL");
	printf("ft_strnstr  : %s\n", mine ? mine : "NULL");
	printf("-----------------------------\n");
}

int	main(void)
{
	test("Foo Bar Baz", "Bar", 4);
	test("Foo Bar Baz", "Bar", 7);
	test("Foo Bar Baz", "Baz", 11);
	test("Foo Bar Baz", "", 5);
	test("Foo Bar Baz", "Bar", 20);
	test("Foo Bar Baz", "Qux", 20);
	test("Foo Bar Baz", "o", 20);
	test("Foo Bar Baz", " ", 20);

	return (0);
}


//  gcc -Wall -Wextra -Werror ft_strnstr.c -o test_strnstr && ./test_strnstr
*/