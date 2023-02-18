/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:08 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/02/18 16:04:48 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_addressx(unsigned long a, int b, int c);

int	ft_putaddress(char	*str, int fd, int numfon)
{
	unsigned long	number;

	number = (unsigned long)str;
	numfon = write(fd, "0x", ft_strlen("0x")) + ft_addressx(number, fd, numfon);
	return (numfon);
}

static int	ft_addressx(unsigned long number, int fd, int numfon)
{
	char	chara;

	if (number < 10)
		numfon += ft_putchar_fd(number + '0', fd);
	else if (10 <= number && number <= 15)
		numfon += ft_putchar_fd(number - 10 + 'a', fd);
	else
	{
		if (number % 16 < 10)
			chara = number % 16 + '0';
		else
			chara = number % 16 - 10 + 'a';
		numfon = ft_addressx(number / 16, fd, numfon);
		numfon += ft_putchar_fd(chara, fd);
	}
	return (numfon);
}
