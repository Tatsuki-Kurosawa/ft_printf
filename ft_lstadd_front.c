/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:41:19 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/02 16:41:20 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	t_list	*next_data;

	next_data = *list;
	*list = new;
	new->next = next_data;
}

// 今listが差しているデータのポインタを別の変数に移して取っておく
// listがさすデータを変更する
// 新しいデータのnextに、listが差していたデータのポインタを代入する