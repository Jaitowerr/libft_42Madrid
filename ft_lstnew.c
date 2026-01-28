/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:33:12 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/26 20:21:52 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if(!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
#ifdef TEST	//para saltar errores de compilación con la librería
# include <stdio.h>

int main(void)
{
	t_list *nodo;
	char *texto = "Soy el primer nodo";

	nodo = ft_lstnew(texto);
	if (nodo)
	{
		printf("Contenido del nodo: %s\n", (char *)nodo->content);
		printf("Siguiente nodo: %p\n", nodo->next); // Debería ser 0x0 (NULL)
	}
	free(nodo);
	return (0);
}
#endif
//cc -Wall -Wextra -Werror ft_lstnew.c -DTEST -o test && ./test
*/