/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:55:31 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/06 19:24:34 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	for (int i = 0; i < 255; i++)
// 		// printf("%c  %d\n", i, ft_isalpha(i));
// 		printf("%c  %d\n", i, isalpha(i));
// 	return (0);
// }