/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfxput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:08 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/22 13:37:22 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putxnbr_fd(unsigned int n, int fd, char judge, int numfon)
{
	char	chara;

	if (n < 10)
		numfon += ft_putchar_fd(n + 48, fd);
	else if (10 <= n && n <= 15 && judge == 'x')
		numfon += ft_putchar_fd(n + 87, fd);
	else if (10 <= n && n <= 15 && judge == 'X')
		numfon += ft_putchar_fd(n + 55, fd);
	else
	{
		if (10 <= (n % 16) && (n % 16) <= 15 && judge == 'x')
			chara = n % 16 + 87;
		else if (10 <= (n % 16) && (n % 16) <= 15 && judge == 'X')
			chara = n % 16 + 55;
		else
			chara = n % 16 + 48;
		numfon = ft_putxnbr_fd(n / 16, fd, judge, numfon);
		numfon += ft_putchar_fd(chara, fd);
	}
	return (numfon);
}

int	ft_putaddressx(unsigned long number, int fd, int numfon)
{
	char	chara;

	if (number < 10)
		numfon += ft_putchar_fd(number + 48, fd);
	else if (10 <= number && number <= 15)
		numfon += ft_putchar_fd(number + 87, fd);
	else
	{
		if (number % 16 < 10)
			chara = number % 16 + 48;
		else
			chara = number % 16 + 87;
		numfon = ft_putaddressx(number / 16, fd, numfon);
		numfon += ft_putchar_fd(chara, fd);
	}
	return (numfon);
}

int	ft_putaddress(char	*str, int fd, int numfon)
{
	uintptr_t	number;

	number = (uintptr_t)str;
	numfon = write(fd, "0x", strlen("0x")) + ft_putaddressx(number, fd, numfon);
	return (numfon);
}
