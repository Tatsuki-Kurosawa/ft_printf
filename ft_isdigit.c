/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:55:56 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/05 15:55:57 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (47 < c && c < 58)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	for (int i = 0; i < 255; i++)
// 		printf("%c  %d\n", i, ft_isdigit(i));
// 	return (0);
// }