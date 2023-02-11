#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char	*setstr(int fd, char *str);
char	*join(char *str, char *newstr);
char	*getbeforenewline(char *str);
char	*getafternewline(char *returnvalue);

// buf = newstr, static save = str, line = newlineari かと

char	*get_next_line(int fd)
{
	static char	*str;
	char		*returnvalue;

	if (fd < 0)
		return (NULL);
	// printf("\n18.from get_next_line: %s\n", str);
	returnvalue = setstr(fd, str);			// 改行文字が一つ含まれた文字列
	if (!returnvalue)
		return (NULL);
	str = getafternewline(returnvalue);		// 改行文字以降の文字列を出力する
	returnvalue = getbeforenewline(returnvalue);	// 改行までの文字列を出す
	if (!returnvalue)
		return (NULL);
	return (returnvalue);
}

char	*setstr(int fd, char *str)
{
	char	*newstr;
	int		bytenum;

	newstr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!newstr)
		return (NULL);
	bytenum = 1;
	while (bytenum)
	{
		bytenum = read(fd, newstr, BUFFER_SIZE);
		// printf("%d\n", bytenum);
		// printf("44.newstr: %s\n", newstr);
		if (bytenum < 0)
		{
			free(newstr);
			return (NULL);
		}
		else if (bytenum == 0)		// EOFの時は何も格納されないのか？
			break ;		// 何も格納されないのならヌル文字を入れる必要はない
		else
			str = join(str, newstr);
	}
	// printf("setstr内：%s\n", str);
	// printf("%s\n", "ここまで");			// 改行があったらが必要
	return (str);
}

// 改行が含まれているかどうかチェック *ft_strchr(const char *s, int c).  出力用の文字列を返す
char	*getbeforenewline(char *str)
{
	char	*sentence;
	char	*restr;
	int		i;
	int		length;

	restr = ft_strchr(str, 10);
	length = restr - str;
	sentence = (char *)malloc(sizeof(char) * (length + 1));
	if (!sentence)
		return (NULL);
	i = 0;
	while (i < length)
	{
		sentence[i] = str[i];
		i++;
	}
	sentence[i] = '\0';
	return (sentence);
}

// 関数にしなくてもいいかも
char	*getafternewline(char *returnvalue)
{
	char	*restr;

	restr = ft_strchr(returnvalue, 10);		// 行の最後の文字が改行文字だったら、この時restr+1はどうなる？セグフォ？
	return (restr + 1);		//最後の文字にはヌル文字を入れているからそれが出力されるのか？
}

// buf = newstr（読み込み格納）, static save = str（端文字列）, line = newlineari（出力文字列）かと
// 文字列更新の働きをする. どれをstaticにすべき？, 前回の改行文字以降の文字を受け取る
// newlineariにどんどん文字列を結合していき、最終的にそれを返す
// get_next_lineの方で文字列を2つ用意しておく. 1つは端文字列用でもう1つは出力文字列用
// setstrでは、strに端文字列を格納しつつ、出力文字列を更新していく.
// buf = newstr（読み込み格納）, static save = str（端文字列）, line = newlineari（出力文字列）かと
// free関数はアドレスを解放するのか
// はじめに結合し、その後で改行文字以降を取り出す

// ！！！出力文字列を返す関数と、端文字列を返す関数が必要！！！
// 今のchecknewline関数は、"出力文字列を返す"と"端文字列を返す"操作の2つを同時にやってしまっている.
// strはグローバル変数じゃないから必ずreturnで返さないといけない
// setstr関数は、改行が含まれるまでの文字列を返す働きをしなくてはならない
// 他の改行までを出すことや、改行文字以降の文字列を出力することはsetstr関数外で処理する必要がある.

// グローバル変数と勘違いしてるかも
// staticはプログラムの最初から最後まで値を初期化せずに保持するだけ

char	*join(char *str, char *newstr)
{
	char	*returnvalue;

	if (str)
		returnvalue = ft_strjoin(str, newstr);		// strの後ろにnewstrがつく
	else
		returnvalue = newstr;
	return (returnvalue);
}


// 今はひたすら1行ずつ読み込んでいる
int	main(void)
{
	int		fd;
	char	*line;
	size_t	i;

	i = 0;
	fd = open("./test.txt", O_RDONLY);
	// line = get_next_line(fd);
	// printf("|%s|\n", line);
	while (i < 5)
	{
		line = get_next_line(fd);
		printf("130|%s|\n", line);
		i ++;
	}
	return (0);
}
