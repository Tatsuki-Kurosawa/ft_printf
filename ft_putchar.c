/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:02 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/03/03 22:28:05 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(int c, int fd)
{
	char	cc;

	cc = (char)c;
	return (write(fd, &cc, sizeof(cc)));
}

int	ft_putstr_fd(char *s, int fd, int numfon)
{
	size_t	i;

	i = 0;
	if (!s)
		numfon += write(1, "(null)", ft_strlen("(null)"));
	else
	{
		while (*(s + i))
		{
			numfon += write(fd, (s + i), 1);
			if (i > INT_MAX)
			{
				numfon = -1;
				break ;
			}
			i++;
		}
	}
	return (numfon);
}
