/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:20:05 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/11 18:26:01 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*check(char const *s, char c, size_t count, size_t num);
char		*allocate(char *s, char c);
void		*free_memory(char **return_value, int i);
size_t		counter(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**return_value;
	size_t	count;
	size_t	num;

	if (!s)
		return (NULL);
	return_value = malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!return_value)
		return (NULL);
	count = 0;
	num = counter(s, c);
	while (*s == c)
		s++;
	while (count < num)
	{
		return_value[count] = allocate((char *)s, c);
		if (!return_value[count])
			return (free_memory(return_value, count));
		s = check(s, c, count, num);
		count++;
	}
	return_value[count] = NULL;
	return (return_value);
}

char	*allocate(char *s, char c)
{
	char	*str;
	char	*front;
	char	*back;
	size_t	size;
	size_t	i;

	size = 0;
	front = s;
	while (*front != c && *front != '\0')
		front++;
	back = front;
	front = s;
	size = ft_strlen(front) - ft_strlen(back);
	str = malloc(size + 1);
	i = 0;
	while (i < size)
	{
		*(str + i) = *(front + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

const char	*check(char const *s, char c, size_t count, size_t num)
{
	if (count + 1 < num)
	{
		while (*s != c)
			s++;
		while (*s == c)
			s++;
		return (s);
	}
	return (s);
}

size_t	counter(char const *s, char c)
{
	size_t	word_count;
	int		position_s;
	int		flag;

	flag = 0;
	position_s = 0;
	word_count = 0;
	while (*(s + position_s))
	{
		if (*(s + position_s) == c)
			flag = 0;
		else if (*(s + position_s) != c && flag == 0)
		{
			word_count++;
			flag = 1;
		}
		position_s++;
	}
	return (word_count);
}

void	*free_memory(char **return_value, int i)
{
	while (i > 0)
		free(return_value[i--]);
	free(return_value);
	return (NULL);
}

// split関数では返り値のダブルポインタを用意し（容量はcounterで確保）、allocate関数からの返り値を代入する
// allocate関数は返すべき単語を一つずつ返す
// check関数はsplit関数の繰り返しを制御. 単語数を基準としているため、ヌル文字判定は不要
// counter関数は単語数をカウント. 単語の先頭で単語をカウント
// free_memory関数はallocate関数の返り値がNULLだった時に動き、確保したメモリを解放

// int	main(void)
// {
// 	char	*ptr = "aaabbcccbbd";
// 	char	**str;
// 	size_t	i;
// 	size_t	j;

// 	str = ft_split(ptr, 'b');
// 	i = counter(ptr, 'b');
// 	j = 0;
// 	while (j < i)
// 	{
// 		printf("%s\n", str[j]);
// 		j++;
// 	}
// }