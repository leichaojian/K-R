#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 5	//默认最大长度为5个字符

int		getline(char *line, int max);
void copy(char *to, char *from);
int main(void)
{
	char		*longest;	//保存最长的一行
	char		*line;			//保存每次输入的一行
	int			len;			//每行的长度
	int			max;			//最长行的长度

	max = 0;
	line = malloc(sizeof(char) * MAXLINE);	
	longest = malloc(sizeof(char) * MAXLINE);	
	while ((len = getline(line, max == 0 ? MAXLINE : max)) > 0){
		if (len > max){
			max = len;
			longest = realloc(longest, max);
			copy(longest, line);
		}
	}

	if (max > 0){
		printf("%s\n", longest);
	}

	return 0;
}

int		getline(char *line, int max)
{
	int		nch = 0;
	char	ch;
	char	*oldLine = line;
	while ((ch = getchar()) != EOF && ch != '\n'){
		*oldLine++ = ch;
		nch++;
		if (nch >= max){
			//这里最好用malloc，因为指针会漂移
			line = realloc(line, max * 2);
			max *= 2;
		}
	}
	*oldLine = '\0';

	return nch;
}

void copy(char *to, char *from)
{
	while (*to++ = *from++){
		;
	}
}