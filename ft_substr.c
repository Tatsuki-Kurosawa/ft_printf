/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:30:33 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/16 20:03:50 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_null(char *a, size_t b);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*return_ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t)start)
		return_ptr = (char *)malloc(strlen(s) - (size_t)start + 1);
	else
		return_ptr = (char *)malloc(len + 1);
	if (!return_ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (!*(s + start + i))
			return (set_null(return_ptr, i));
		*(return_ptr + i) = *(s + start + i);
		i++;
	}
	return (set_null(return_ptr, i));
}

static char	*set_null(char *return_ptr, size_t i)
{
	*(return_ptr + i) = '\0';
	return (return_ptr);
}
