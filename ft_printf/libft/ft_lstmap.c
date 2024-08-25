/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:27:10 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/10/10 21:27:12 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst1;
	t_list	*newnode;

	if (!lst || !f)
		return (NULL);
	lst1 = NULL;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			del(&lst1);
			return (NULL);
		}
		ft_lstadd_back(&lst1, newnode);
		lst = lst->next;
	}
	return (lst1);
}
