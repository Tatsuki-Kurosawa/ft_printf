/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:09:53 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/14 20:13:39 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
}

// int main(void)
// {
//     char buf[] = "ABCDEFGHIJK";
//     ft_bzero(buf+3, 1);
//     for (int i = 0; i < 11; i++)
//     {
//         printf("buf文字列→%c\n",buf[i]);
//     }
//     return 0;
// }

// 本家ではヌルポインタが引数に渡された場合を定義していないため定義不要
// nが与えられたポインタのバイト数より大きい場合、最後まで0埋めしてabort
// 本家では警告となり、無理やり実行するとabort