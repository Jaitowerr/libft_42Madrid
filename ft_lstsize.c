/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:16:44 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/27 13:40:15 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int     i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
#include <stdio.h>
#ifdef TEST	//para saltar errores de compilación con la librería
int main(void)
{
	t_list *head = NULL;
	t_list *it;
	t_list *n1;
	t_list *n2;
	t_list *n3;

	printf("size (vacía) = %d\n", ft_lstsize(head)); 

	n1 = ft_lstnew("Nodo 1");
	n2 = ft_lstnew("Nodo 2");
	n3 = ft_lstnew("Nodo 3");


	ft_lstadd_front(&head, n1);
	printf("size (1 nodo) = %d\n", ft_lstsize(head)); 

	ft_lstadd_front(&head, n2);
	printf("size (2 nodos) = %d\n", ft_lstsize(head)); 

	ft_lstadd_front(&head, n3);
	printf("size (3 nodos) = %d\n", ft_lstsize(head));

	it = head;
	while (it != NULL)
	{
		printf("  contenido: %s\n", (char *)it->content);
		it = it->next;
	}

	free(n1);
	free(n2);
	free(n3);
	return 0;
}
#endif
// cc -Wall -Wextra -Werror -DTEST ft_lstsize.c ft_lstnew.o ft_lstadd_front.c -o test && ./test
*/