/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:28:19 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/14 21:25:04 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*str;

	str = s;
	if (len == 0)
		return (s);
	else
	{
		while (len)
		{
			*str = c;
			str++;
			len--;
		}
		return (s);
	}
}

// #include<string.h>
// int main(void)
// {
//     char buf[] = "ABCDEFGHIJK";
//     // memset(NULL, 1, 5);
//     ft_memset(NULL, 1, 5);
//     printf("buf文字列→%s\n",buf);
//     return 0;
// }

// 第一引数にNULLが入った場合はsegfaが起きる