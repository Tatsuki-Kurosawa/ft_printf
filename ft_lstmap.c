/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:27:17 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/06 19:27:18 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_lst;

	if (lst && f && del)
	{
		new_lst = NULL;
		while (lst)
		{
			tmp = ft_lstnew((*f)(lst->content));
			if (!tmp)
				ft_lstclear(&new_lst, del);
			ft_lstadd_back(&new_lst, tmp);
			lst = lst->next;
		}
		return (new_lst);
	}
	return (NULL);
}
