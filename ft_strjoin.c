/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:30:43 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/22 16:10:13 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length] != '\0')
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i1;
	size_t	i2;
	size_t	i3;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	s3 = malloc(sizeof(char) *(i1 + i2 + 1));
	if (!s3)
		return (NULL);
	i1 = 0;
	i2 = 0;
	i3 = 0;
	while (s1[i1])
		s3[i3++] = s1[i1++];
	while (s2[i2])
		s3[i3++] = s2[i2++];
	s3[i3] = '\0';
	return (s3);
}

int main(void)
{
	char *result;

	result = ft_strjoin("Hola ", "mundo");
	printf("1) ft_strjoin(\"Hola \", \"mundo\") = \"%s\"\n", result);
	free(result);

	result = ft_strjoin("", "Hola");
	printf("2) ft_strjoin(\"\", \"Hola\") = \"%s\"\n", result);
	free(result);

	result = ft_strjoin("Hola", "");
	printf("3) ft_strjoin(\"Hola\", \"\") = \"%s\"\n", result);
	free(result);

	result = ft_strjoin("", "");
	printf("4) ft_strjoin(\"\", \"\") = \"%s\"\n", result);
	free(result);

	return (0);
}

// gcc -Wall -Wextra -Werror ft_strjoin.c -o test_strjoin && ./test_strjoin




