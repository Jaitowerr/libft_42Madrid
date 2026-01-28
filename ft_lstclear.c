/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:48:38 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/28 20:02:07 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp_next;
	t_list	*temp_lst;

	if (!lst)
		return ;
	temp_lst = *lst;
	while (temp_lst)
	{
		temp_next = temp_lst->next;
		if (del)
			del(temp_lst->content);
		free(temp_lst);
		temp_lst = temp_next;
	}
	*lst = NULL;
}
/*
#ifdef TEST

#include <stdio.h>

static void del_print_and_free(void *content)
{
	if (!content)
		return;
	printf("El content '%s' eliminado\n", (char *)content);
	free(content);
}


int main(void)
{
	t_list *head = NULL;
	t_list *it;

	ft_lstadd_front(&head, ft_lstnew(ft_strdup("Nodo A")));  
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Nodo B")));
	ft_lstadd_front(&head, ft_lstnew(ft_strdup("Nodo C")));

	printf("Lista antes de ft_lstclear:\n");
	it = head;
	while (it)
	{
		printf("  %s\n", (char *)it->content);
		it = it->next;
	}

	ft_lstclear(&head, del_print_and_free);

	printf("Total de nodos: %d\n", ft_lstsize(head));

	return (0);
}

#endif

// cc -Wall -Wextra -Werror -DTEST ft_lstclear.c ft_lstnew.c 
ft_lstadd_front.c ft_lstadd_back.c ft_strdup.c ft_lstsize.c -o test && ./test
*/