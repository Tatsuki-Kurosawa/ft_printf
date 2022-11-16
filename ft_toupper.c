/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:37:45 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/10/12 19:43:03 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	chara;

	if (97 <= c && c <= 122)
		chara = c - 32;
	else
		chara = c;
	return (chara);
}

// int	main(void)
// {
// 	int	to;

// 	to = ft_toupper('a');
// 	printf("aを大文字に変換→%c\n", to);
// 	return (0);
// }
