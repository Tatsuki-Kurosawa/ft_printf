/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:46:09 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/14 21:10:51 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!len || d == s)
		return (d);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}

// int main(void)
// {
//     char buf[] = "ABCDDEFG";
//     ft_memmove(buf+3,buf,3); //(dest, src, n)
//     printf("コピー後のbuf文字列→%s\n",buf);
//     return 0;
// }

// どちらかがNULLの場合、segfaが起きる