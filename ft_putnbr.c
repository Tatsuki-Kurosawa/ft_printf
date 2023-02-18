/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:09:59 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/02/18 16:10:08 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd, int numfon)
{
	char	chara;

	if (n < 0)
	{
		if (n == INT_MIN)
		{
			numfon += write(fd, "-2147483648", ft_strlen("-2147483648"));
			return (numfon);
		}
		numfon += ft_putchar_fd('-', fd);
		n *= -1;
		numfon = ft_putnbr_fd(n, fd, numfon);
	}
	else if (n >= 0)
	{
		if (n < 10)
			numfon += ft_putchar_fd(n + 48, fd);
		else
		{
			chara = n % 10 + 48;
			numfon = ft_putnbr_fd(n / 10, fd, numfon);
			numfon += ft_putchar_fd(chara, fd);
		}
	}
	return (numfon);
}

int	ft_putunbr_fd(unsigned int n, int fd, int numfon)
{
	char	chara;

	if (n < 10)
		numfon += ft_putchar_fd(n + 48, fd);
	else
	{
		chara = n % 10 + 48;
		numfon = ft_putunbr_fd(n / 10, fd, numfon);
		numfon += ft_putchar_fd(chara, fd);
	}
	return (numfon);
}

int	ft_putxnbr_fd(unsigned int n, int fd, char judge, int numfon)
{
	char	chara;

	if (n < 10)
		numfon += ft_putchar_fd(n + '0', fd);
	else if (10 <= n && n <= 15 && judge == 'x')
		numfon += ft_putchar_fd(n - 10 + 'a', fd);
	else if (10 <= n && n <= 15 && judge == 'X')
		numfon += ft_putchar_fd(n - 10 + 'A', fd);
	else
	{
		if (10 <= (n % 16) && (n % 16) <= 15 && judge == 'x')
			chara = n % 16 - 10 + 'a';
		else if (10 <= (n % 16) && (n % 16) <= 15 && judge == 'X')
			chara = n % 16 - 10 + 'A';
		else
			chara = n % 16 + '0';
		numfon = ft_putxnbr_fd(n / 16, fd, judge, numfon);
		numfon += ft_putchar_fd(chara, fd);
	}
	return (numfon);
}
