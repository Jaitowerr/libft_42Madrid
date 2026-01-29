/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:58:42 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/29 02:02:49 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstclear_local(t_list **lst, void (*del)(void*))
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

static t_list	*ft_lstnew_local(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

static t_list	*ft_lstlast_local(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static void	ft_lstadd_back_local(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	last = ft_lstlast_local(*lst);
	last->next = new;
	new->next = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;
	void	*temp_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		temp_content = f(lst->content);
		node = ft_lstnew_local(temp_content);
		if (!node)
		{
			if (del && temp_content)
				del(temp_content);
			ft_lstclear_local(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back_local(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}
/*
#ifdef TEST

#include <stdio.h>


void *duplicate_string(void *content)
{
	if (!content)
		return (NULL);
	return (ft_strdup((char *)content));  // strdup usa malloc internamente
}

void del_content(void *content)
{
	free(content);
}

int main(void)
{
	t_list *original = NULL;
	t_list *mapped = NULL;
	t_list	*i;
	t_list	*j;
	
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("nodo1")));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("nodo2")));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("nodo3")));

	printf("Lista original ===\n");
	i = original;
	while (i)
	{
		printf("'%s'\n", (char *)i->content);
		i = i->next;
	}

	mapped = ft_lstmap(original, duplicate_string, del_content);
	if (!mapped)
	{
		printf("Error: ft_lstmap devolvió NULL\n");
		ft_lstclear(&original, del_content);
		return (1);
	}
	
	printf("\n===Lista mapeada\n");
	j = mapped;
	while (j)
	{
		printf("'%s'\n", (char *)j->content);
		j = j->next;
	}
	
	ft_lstclear(&original, del_content);
	ft_lstclear(&mapped, del_content);

	printf("\nListas liberadas.\n");
	return (0);
}
#endif

// cc -Wall -Wextra -Werror -DTEST ft_lstmap.c ft_lstnew.c
 ft_lstadd_back.c ft_lstclear.c ft_strdup.c -o test && ./test
*/