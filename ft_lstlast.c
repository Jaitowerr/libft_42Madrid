/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:28:58 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/28 11:02:35 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
 #ifdef TEST	//para saltar errores de compilación con la librería y compilar este main

int main(void)
{
	t_list *head = NULL;
	t_list *n1;
	t_list *n2;
	t_list *n3;
	t_list *it;
	t_list *last;

	last = ft_lstlast(head);
	if (last)
		printf("last (vacía) -> %s\n", (char *)last->content);
	else
		printf("last (vacía) -> (null)\n");


	n1 = ft_lstnew("Nodo 1");
	n2 = ft_lstnew("Nodo 2");
	n3 = ft_lstnew("Nodo 3");

	ft_lstadd_front(&head, n1);
	ft_lstadd_front(&head, n2);
	ft_lstadd_front(&head, n3);

	printf("Lista completa:\n");
	it = head;
	while (it != NULL)
	{
		printf("  %s\n", (char *)it->content);
		it = it->next;
	}


	last = ft_lstlast(head);
	if (last)
		printf("Último nodo -> %s\n", (char *)last->content);
	else
		printf("Último nodo -> (null)\n");

	while (head != NULL)
	{
		t_list *tmp = head->next;
		free(head);				// incluye n1, n2 y n3
		head = tmp;
	}
	return 0;
}
#endif
//cc -Wall -Wextra -Werror ft_lstlast.c ft_lstnew.c ft_lstadd_front.c -o test && ./test
*/