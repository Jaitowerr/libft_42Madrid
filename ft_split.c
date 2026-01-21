/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:18:30 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/21 20:07:30 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t count_string(const char *s, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t return_i(const char *s, char c, size_t i)
{
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char **reservar_memoria_arrays(char **ptr2, const char *s, char c, size_t i_array)
{
	size_t j;
	size_t i;
	size_t inicio;

	j = 0;
	i = 0;
	while (j < i_array)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		inicio = i;
		i = return_i(s, c, i);
		ptr2[j] = malloc(sizeof(char) * (i - inicio + 1));
		if (!ptr2[j])
		{
			while (j > 0)
				free(ptr2[--j]);
			free(ptr2);
			return (NULL);
		}
		j++;
	}
	return (ptr2);
}
static void asignar_datos_arrays(char **ptr2, const char *s, char c, size_t i_array)
{
	size_t j;
	size_t i;
	size_t i2;

	i = 0;
	j = 0;

	while (s[i] && j < i_array)
	{
		i2 = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (i < return_i(s, c, i))
		{
			ptr2[j][i2] = s[i];
			i2++;
			i++;
		}
		ptr2[j][i2] = '\0';
		j++;
	}
	ptr2[i_array] = NULL;
}

char **ft_split(char const *s, char c)
{
	char **ptr2;
	size_t i_array;

	if (!s)
		return (NULL);
	i_array = count_string(s, c);
	ptr2 = malloc(sizeof(char *) * (i_array + 1));
	if (!ptr2)
		return (NULL);

	if (!reservar_memoria_arrays(ptr2, s, c, i_array))
		return (NULL);

	asignar_datos_arrays(ptr2, s, c, i_array);

	return (ptr2);
}


int main(void)
{
	char **result;
	int i;

	result = ft_split("  Hola, ,mundo        feliz4 4 ", ' ');
	i = 0;
	while (result[i])
	{
		printf("Palabra %d: \"%s\"\n", i, result[i]);
		free(result[i]); // Liberar cada palabra
		i++;
	}
	free(result); // Liberar el array
	return (0);
}

// gcc -Wall -Wextra -Werror ft_split.c -o test_split && ./test_split

// int    count_string(const char *s, char c)
// {
//     int     count;
//     int     i;

//     count = 0;
//     i = 0;
//     while (s[i])
//     {
//         if (s[i] != c && (i == 0 || s[i - 1] == c))
//             count++;
//         i++;
//     }
//     return (count);
// }

// size_t  return_i(const char *s, char c, size_t i)
// {
//     while (s[i] != '\0' && s[i] != c)
//         i++;
//     return (i);
// }

// char **ft_split(char const *s, char c)
// {
//     char    **ptr2;
//     size_t  i_array;
//     size_t  i;
//     size_t  i2; //recorrer guardar datos de cada array
//     int     j;  //posiciones de cada array
//     size_t  inicio; //para luego restar la diferencia para el malloc

//     i_array = count_string(s, c);

//     ptr2 = malloc(sizeof(char *) * (i_array + 1));
//     if (!ptr2)
//         return (NULL);

//     i = 0;
//     j = 0;

//     while (j < i_array)     // cuando 0 es menor que los arrays creados, menor porque el ultimo es nulo
//     {       // un bucle para malloc a los arrays
//         //tenemos que recorrer hasta donde es la palabra
//         while (s[i] == c && s[i] != '\0')   //con esto si al empezar existe el separador varias veces avanzamos posiciones
//             i++;
//         inicio = i;
//         i = return_i(s, c, i);
//         //malloc para el tamaño de i +1
//         ptr2[j] = malloc(sizeof(char) * (i - inicio + 1));
//         if (!ptr2[j])
//             return (NULL);
//         j++;
//     }

//     i = 0;
//     j = 0;
//     // otro bucle para ahora ir asignando a cada array sus datos
//     while (s[i] && j < (int)i_array)    //casteamos apra evitar errores
//     {
//         i2 = 0;
//         while (s[i] == c && s[i] != '\0')   //con esto si al empezar existe el separador varias veces avanzamos posiciones
//             i++;
//         while (i < return_i(s, c, i))
//         {
//             ptr2[j][i2] = s[i];
//             i2++;
//             i++;
//         }
//         ptr2[j][i2] = '\0';
//         j++;
//     }

//     // para terminar cremos malloc del nulo y agregamos nulo
//     ptr2[i_array] = NULL;
//     //NO hace falta darle tamñao, NULL es NULL
//     // ptr2[i_array] = malloc(sizeof(char) * 1);
//     // ptr2[i_array][0] = '\0';       //el ultimo es nulo, una posicion solo, la 0, para el nulo y asi sabemos el finde los arrays
// }
