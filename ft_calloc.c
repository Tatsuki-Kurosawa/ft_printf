/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:20:56 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/06 19:23:03 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (size == 0 || count == 0)
	{
		size = 1;
		count = 1;
	}
	if (SIZE_MAX / size < count)
		return (NULL);
	temp = malloc(size * count);
	if (temp == NULL)
		return (NULL);
	ft_bzero(temp, count * size);
	return (temp);
}

// int	main(void)
// {
// 	char *ch;
//     ch = (char*)calloc(42,42);
// 	// ch = (char*)ft_calloc(0,0);
// 	puts("文字列を入力してください。");
//     gets(ch);
//     printf("入力した文字は→%s\n",ch);
//     free(ch);
//     return 0;
// }