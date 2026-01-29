/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:58:30 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/29 00:51:42 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*s2;

	i = 0;
	while (s[i])
		i++;
	s2 = malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*
char	contra_seña(unsigned int i, char b)
{
	if ( (b + i ) > 126)
		b = b - i;
	else
		b = b + i;
	return (b);
}

int main()
{
	char *s = "aaaaaaaaaaaaaaaaaaaaa";
	char *s1;
	
	s1 = ft_strmapi(s, contra_seña);
	printf("resultado -> %s\n", s1 ? s1 : "NULL");
	free(s1);
}
*/
// cc -Wall -Wextra -Werror ft_strmapi.c -o test_strmapi && ./test_strmapi