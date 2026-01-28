/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:40:04 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/27 12:38:10 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>
#ifdef TEST	//para saltar errores de compilación con la librería

int main(void)
{
	t_list *head = NULL;
	t_list *n1;
	t_list *n2;
	t_list *it; 	// el iterador para recorrer la lista 

	n1 = ft_lstnew("Nodo 1");
	n2 = ft_lstnew("Nodo 2");

	ft_lstadd_front(&head, n1);		// Añades n1 al principio, head apunta a n1
	ft_lstadd_front(&head, n2);		// Añades n2 al principio, head apunta a n2, y n2->next apunta a n1

	// Imprimir contenidos usando while //
	it = head;
	while (it)
	{
		printf("%s\n", (char *)it->content);
		it = it->next; 		// avanzar al siguiente nodo
	}

	// Liberar nodos (en real usarías ft_lstdelone/ft_lstclear) 
	free(n1);
	free(n2);
	return (0);
}
#endif
//cc -Wall -Wextra -Werror -DTEST ft_lstadd_front.c -o test && ./test
//cc -Wall -Wextra -Werror -DTEST ft_lstadd_front.c ft_lstnew_local.c -o test && ./test
*/
