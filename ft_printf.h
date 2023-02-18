/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:48:11 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/02/18 16:00:02 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fs, ...);
int		ft_putstr_fd(char *s, int fd, int numfon);
int		ft_putchar_fd(int c, int fd);
int		ft_putnbr_fd(int n, int fd, int numfon);
int		ft_putunbr_fd(unsigned int n, int fd, int numfon);
int		ft_putxnbr_fd(unsigned int n, int fd, char judge, int numfon);
int		ft_putaddress(char	*str, int fd, int numfon);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif