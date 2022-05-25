/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <micheli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:45:27 by mmicheli          #+#    #+#             */
/*   Updated: 2021/10/24 14:47:01 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*buf;

	buf = lst;
	if (buf)
		while (buf->next)
			buf = buf->next;
	return (buf);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buf;
	t_list	*reslst;

	buf = NULL;
	if (lst)
	{
		while (lst)
		{
			reslst = ft_lstnew((*f)(lst->content));
			if (!reslst)
			{
				ft_lstclear(&buf, del);
				return (NULL);
			}
			ft_lstadd_back(&buf, reslst);
			lst = lst->next;
		}
		return (buf);
	}
	return (NULL);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem)
	{
		elem->content = content;
		elem->next = NULL;
	}
	return (elem);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*buf;
	int		i;

	i = 0;
	buf = lst;
	while (buf)
	{
		i++;
		buf = buf->next;
	}
	return (i);
}
