/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:17:52 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/07 21:12:48 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	*ptr;

	s_len = ft_strlen(s);
	ptr = (char *)s;
	if (c == '\0')
		return (ptr + s_len);
	while (s_len--)
	{
		if (*(ptr + s_len) == (char)c)
			return (ptr + s_len);
	}
	return (NULL);
}

// int main(void)
// {
//     char test[20] = "yuyguy";
// 	// char test[20];
//     char *p;
//     p = ft_strrchr(test,'0');
//     printf("検索文字が見つかった場所から表示→%s\n",p);
//     return 0;
// }
