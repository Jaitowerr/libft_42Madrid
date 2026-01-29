/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:56:40 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/29 15:16:31 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstlast_local(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	last = ft_lstlast_local(last);
	last->next = new;
}
/*
#ifdef TEST
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*head = NULL;
	t_list	*it;
	t_list	*last_node;
	t_list	*tmp;
	int		size;

	ft_lstadd_back(&head, ft_lstnew("Nodo 1, el origen."));

	ft_lstadd_front(&head, ft_lstnew("Nodo 2, añadido por delante."));

	ft_lstadd_back(&head, ft_lstnew("Nodo 3, añadido por detrás."));

	ft_lstadd_front(&head, ft_lstnew("Nodo 4, el nuevo primero."));

	size = ft_lstsize(head);
	printf("Tamaño total de la lista: %d nodos\n\n", size);

	printf("Contenido de la lista:\n");

	it = head;
	
	while (it)
	{
		printf("- %s\n", (char *)it->content);
		it = it->next;
	}
	last_node = ft_lstlast(head);
	
	if (last_node)
		printf("\nEl último nodo real es: %s\n", (char *)last_node->content);

	printf("\nLiberando memoria...\n");
	while (head)
	{
		tmp = head->next;	//guardo el siguiente nodo
		free(head);			//libero el nodo actual
		head = tmp;			// con la temporal le decimos el siguiente
	}
	printf("¡Lista liberada!\n");

	return (0);
}
#endif

// cc -Wall -Wextra -Werror -DTEST ft_lstdelone.c ft_lstnew.c -o test && ./test
*/