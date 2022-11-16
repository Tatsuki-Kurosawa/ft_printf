/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:55:14 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/08 16:25:42 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*head;
	char const	*tail;
	char		*str;

	if (!s1)
		return (NULL);
	head = s1;
	tail = s1 + ft_strlen(s1) - 1;
	while (*head)
	{
		if (!ft_strchr(set, *head))
			break ;
		head++;
	}
	while (head < tail)
	{
		if (!ft_strchr(set, *tail))
			break ;
		tail--;
	}
	tail++;
	str = ft_substr(head, 0, tail - head);
	return (str);
}

// s1からsetにある文字を削ぎ落とす
// setとheadから取ってきた一文字ずつをft_strchrに入れ、setにあればポインタが返り、なければNULLが返る性質を利用
// これを前と後ろから行なっていく

// int	main(void)
// {
// 	char	s1[12] = "1234AAA1212";
// 	char	set[5] = "1234";
// 	char	*return_value;

// 	// return_value = ft_strtrim(s1, set);
// 	return_value = ft_strtrim("hello world", "abcdefghijklmnopqrstuvwxyz");
// 	printf("%s\n", return_value);
// }