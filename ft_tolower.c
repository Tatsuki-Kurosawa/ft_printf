/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:46:29 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/10/12 19:46:36 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	chara;

	if (65 <= c && c <= 90)
		chara = c + 32;
	else
		chara = c;
	return (chara);
}

// int	main(void)
// {
// 	int	to;

// 	to = ft_tolower('A');
// 	printf("aを大文字に変換→%c\n", to);
// 	return (0);
// }
