/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:21:42 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/06 20:21:43 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	number_of_byte;
	char	*return_value;
	size_t	i;

	if (!s || !f)
		return (NULL);
	number_of_byte = ft_strlen(s);
	return_value = (char *)malloc(number_of_byte + 1);
	if (!return_value)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(return_value + i) = f(i, *(s + i));
		i++;
	}
	*(return_value + i) = '\0';
	return (return_value);
}
