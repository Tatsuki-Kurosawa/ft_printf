/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 05:18:55 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/07 05:18:56 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*divide(int n, int sign, size_t count);
char	*convert(int n, int sign, size_t count, char *re_ptr);
char	*min_case(int n, int sign, size_t count);

char	*ft_itoa(int n)
{
	int		sign;
	size_t	count;

	count = 0;
	sign = 1;
	if (n == 0)
		count++;
	else if (n == INT_MIN)
		sign = -1;
	else if (n < 0 && n != INT_MIN)
	{
		sign = -1;
		n *= -1;
		count++;
	}
	return (divide(n, sign, count));
}

char	*divide(int n, int sign, size_t count)
{
	int		sho;
	char	*re_ptr;

	if (n == INT_MIN)
		return (min_case(n, sign, count));
	else if (n == 0)
	{
		re_ptr = malloc(count + 1);
		if (!re_ptr)
			return (NULL);
		*(re_ptr + 0) = '0';
		*(re_ptr + 1) = '\0';
		return (re_ptr);
	}
	sho = n;
	while (sho > 0)
	{
		sho /= 10;
		count++;
	}
	re_ptr = malloc(count + 1);
	if (!re_ptr)
		return (NULL);
	return (convert(n, sign, count, re_ptr));
}

char	*convert(int n, int sign, size_t count, char *re_ptr)
{
	if (n > 0)
	{
		*(re_ptr + count) = '\0';
		count--;
	}
	else if (n < 0)
		n *= -1;
	while (n > 0)
	{
		*(re_ptr + count) = n % 10 + '0';
		n /= 10;
		count--;
	}
	if (sign == -1)
		*(re_ptr + count) = '-';
	return (re_ptr);
}

char	*min_case(int n, int sign, size_t count)
{
	int		number;
	char	*re_ptr;

	number = n;
	count++;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	re_ptr = malloc(count + 1);
	if (!re_ptr)
		return (NULL);
	*(re_ptr + count) = '\0';
	count--;
	*(re_ptr + count) = (n % 10) * (-1) + '0';
	count--;
	return (convert(n / 10, sign, count, re_ptr));
}

// int	main(void)
// {
// 	int		number;
// 	char	*re_ptr;

// 	number = INT_MIN;
// 	re_ptr = ft_itoa(number);
// 	printf("%s\n", re_ptr);
// }
