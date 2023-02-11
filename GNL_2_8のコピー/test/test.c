# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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

int	main(void)
{
	int		fd;
	int		id;
	char	*str;
	int		hensu;
	char	*newline;

	hensu = 5;
	fd = open("./testtest.txt", O_RDONLY);
	str = (char *)malloc(hensu + 1);
	if (!str)
		return (0);
	id = read(fd, str, hensu);
	str[hensu] = '\0';
	printf("str: %s", str);
	newline = ft_strchr(str, 10);
	printf("newline: %s\n", newline);
	printf("newline+1: %s\n", newline + 1);		// 改行文字以降にヌル文字を入れているが、エラーが起きることはない
	printf("newline+2: %s\n", newline + 2);		// 要確認！！！！！！！！！！
	return (0);
}
