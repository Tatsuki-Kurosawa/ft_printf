/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:38:34 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/14 21:22:54 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char	*str_dest;
	char	*str_src;

	if (!dest && !src)
		return (NULL);
	str_dest = (char *)dest;
	str_src = (char *)src;
	while (n != 0)
	{
		*str_dest = *str_src;
		str_dest++;
		str_src++;
		n--;
	}
	return ((void *)dest);
}

// int	main(void)
// {
// 	// char	src[] = "test basic du memcpy !";
// 	char	*src = NULL;
// 	char	dst[22] = "abcdjefk";

// 	memcpy(dst, src, 22);
// 	printf("コピー後のbuf文字列→%s\n",dst);
// 	// ft_memcpy(dst, src, 22);
// 	// printf("コピー後のbuf文字列→%s\n",dst);
// }

// srcとdstの容量は同じでなくてはならないのか
// どちらかがNULLの時はsegfaが起きる