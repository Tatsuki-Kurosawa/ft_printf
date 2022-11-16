/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:51:42 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/08 18:12:51 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
		i++;
	}
	return (NULL);
}

	// if ((unsigned char)c == '\0' && n != 0)
	// 	return (ptr);
// int main(void)
// {
//     char buf[] = "ABCD5EFGH";
//     char *ch;
// 	// printf("%lu\n", sizeof(buf));
//     ch = (char*)ft_memchr(buf,0,0);
//     if(ch!=NULL){
//         printf("検索文字から表示→%s\n",ch);
//     }else{
//         puts("検索文字が見つかりませんでした。");
//     }
//     return 0;
// }