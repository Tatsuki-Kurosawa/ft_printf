/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:30:08 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/08 00:30:09 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*con_s1;
	unsigned char	*con_s2;

	con_s1 = (unsigned char *)s1;
	con_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*con_s1 != *con_s2)
			return (*con_s1 - *con_s2);
		con_s1++;
		con_s2++;
	}
	return (0);
}

// int main(void)
// {
//     char buf[] = "ABCD5EFGH";
//     char buf2[] = "ABC123456";

//     if(ft_memcmp(buf,buf2,4)==0){
//         puts("先頭から3バイトは一致しています。");
// 		printf("%d\n", ft_memcmp(buf,buf2,4));
//     }else{
//         puts("一致していません。");
//     }
//     return 0;
// }