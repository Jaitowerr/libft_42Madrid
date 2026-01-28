/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:47:01 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/28 15:52:18 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst)
        return;
    del(lst->content);
    free(lst);
}
/*
#ifdef TEST

#include <stdio.h>

static void clear(void *p)
{
    free(p);
}

int main(void)
{
    t_list *p;

    p = ft_lstnew(ft_strdup("5"));
    
    if (!p)
    {
        printf("Error: ft_lstnew devolvió NULL\n");
        return (1);
    }

    printf("Antes: content = %s\n", (char *)p->content);

    ft_lstdelone(p, clear);

    p = NULL;
    if (!p)
        printf("limpio\n");

    return (0);
}
#endif

// cc -Wall -Wextra -Werror -DTEST ft_lstdelone.c ft_lstnew.c ft_strdup.c -o test && ./test
*/