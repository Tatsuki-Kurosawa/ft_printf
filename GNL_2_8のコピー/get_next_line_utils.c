#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t		dst_len;
	size_t		src_len;

	src_len = ft_strlen(src);
	if (!dst && src && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen((const char *)dst);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	src_len = ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*return_ptr;
	size_t		str_size;
	size_t		check;

	if (!s1 || !s2)
		return (NULL);
	str_size = ft_strlen(s1) + ft_strlen(s2);
	return_ptr = (char *)malloc(sizeof(char) * (str_size + 1));
	if (!return_ptr)
		return (NULL);
	check = ft_strlcpy(return_ptr, s1, ft_strlen(s1) + 1);
	if (check != ft_strlen(return_ptr))
	{
		free(return_ptr);
		return (NULL);
	}
	check = ft_strlcat(return_ptr, s2, str_size + 1);
	if (check != str_size)
	{
		free(return_ptr);
		return (NULL);
	}
	return (return_ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
