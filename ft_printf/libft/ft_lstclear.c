/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:26:50 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/10/10 21:26:54 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lsttmp;

	if (del || lst || (*lst))
	{
		while (lst && *lst)
		{
			lsttmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lsttmp;
		}
	}
}
