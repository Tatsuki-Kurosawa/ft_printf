/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:02 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/12 16:45:16 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, sizeof(c)));
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
			i++;
		}
	}
	return (numfon);
}

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

// int	ft_putnbr_fd(int n, int fd, int numfon)
// {
// 	char	chara;

// 	if (n >= 0)
// 		n *= -1;
// 	else
// 		ft_putchar_fd('-', fd);
// 	if (-10 < n && n < 1)
// 	{
// 		chara = (n % 10) * (-1) + '0';
// 		ft_putchar_fd(chara, fd);
// 		return ;
// 	}
// 	chara = (n % 10) * (-1) + '0';
// 	ft_putnbr_fd(n / 10 * (-1), fd);
// 	ft_putchar_fd(chara, fd);
// 	return ;
// }

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

// if (n < 0)
// {
// 	n = 4294967295 - (-1 - n);
// 	numfon = ft_putunbr_fd(n, fd, numfon);
// }