/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:49:25 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/28 15:56:50 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#ifdef TEST

#include <stdio.h>

static void print_content(void *content)
{
	if (content)
		printf("Content: %s\n", (char *)content);
}
int main(void)
{
	t_list *head = NULL;

	ft_lstadd_front(&head, ft_lstnew(ft_strdup("Nodo A")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Nodo B")));
	ft_lstadd_front(&head, ft_lstnew(ft_strdup("Nodo C")));

	printf("Recorriendo lista con ft_lstiter:\n");
	ft_lstiter(head, print_content);

	return (0);
}

#endif
//  cc -Wall -Wextra -Werror -DTEST ft_lstiter.c ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_strdup.c -o test && ./test
*/