/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:20:52 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/02/18 16:49:06 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_specifier(const char *fs, int count, va_list args)
{
	int	nf;

	nf = 0;
	if (*fs == '%' && *(fs + 1) == 'c')
		return (count + ft_putchar_fd(va_arg(args, int), 1));
	else if (*fs == '%' && *(fs + 1) == 's')
		return (count + ft_putstr_fd(va_arg(args, char *), 1, nf));
	else if (*fs == '%' && *(fs + 1) == 'p')
		return (count + ft_putaddress(va_arg(args, char *), 1, nf));
	else if (*fs == '%' && *(fs + 1) == 'd')
		return (count + ft_putnbr_fd(va_arg(args, int), 1, nf));
	else if (*fs == '%' && *(fs + 1) == 'i')
		return (count + ft_putnbr_fd(va_arg(args, int), 1, nf));
	else if (*fs == '%' && *(fs + 1) == 'u')
		return (count + ft_putunbr_fd(va_arg(args, unsigned int), 1, nf));
	else if (*fs == '%' && *(fs + 1) == 'x')
		return (count + ft_putxnbr_fd(va_arg(args, unsigned int), 1, 'x', nf));
	else if (*fs == '%' && *(fs + 1) == 'X')
		return (count + ft_putxnbr_fd(va_arg(args, unsigned int), 1, 'X', nf));
	else if (*fs == '%' && *(fs + 1) == '%')
		return (count + ft_putchar_fd('%', 1));
	else
		return (-1);
}

static int	get_char_num(const char *fs, int count, va_list args, char *specify)
{
	while (*fs)
	{
		if (*fs == '%' && ft_strchr(specify, *(fs + 1)))
		{
			count = format_specifier(fs, count, args);
			fs += 2;
		}
		else if (*fs == '%' && !ft_strchr(specify, *(fs + 1)))
			return (-1);
		else if (*fs != '%')
		{
			while (*fs != '%')
			{
				if (!*fs)
					break ;
				count += ft_putchar_fd(*fs, 1);
				fs++;
			}
			if (!*fs)
				return (count);
		}
	}
	return (count);
}

int	ft_printf(const char *fs, ...)
{
	va_list	args;
	int		count;
	char	*specify;

	va_start(args, fs);
	count = 0;
	specify = "cspdiuxX%";
	if (*fs != '%')
	{
		while (*fs != '%')
		{
			if (!*fs)
				break ;
			count += ft_putchar_fd(*fs, 1);
			fs++;
		}
		if (!*fs)
			return (count);
	}
	count = get_char_num(fs, count, args, specify);
	va_end(args);
	return (count);
}
