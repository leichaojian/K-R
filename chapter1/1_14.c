/**************************************
显示输入单词的垂直直方图
***************************************/
#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLINE 20	//假设最大的单词有20个
#define MAXLEN 20	//单词最大长度为20
main()
{
	char	arr[MAXLINE][MAXLEN];
	int		c, state, nw, i, j, maxLen, tempMaxLen;

	nw = i = j = maxLen = tempMaxLen = 0;
	state = OUT;

	for (i = 0; i < MAXLINE; i++)
		for (j = 0; j < MAXLEN; j++)
			arr[i][j] = 0;

	i = j = 0;
	while ((c = getchar()) != EOF){
		if (c == ' ' | c == '\t' || c == '\n'){
			if (state == IN){
				arr[i++][j++] = '\0';
				if (j > maxLen)
					maxLen = j;
				j = 0;
				nw++;
			}
			state = OUT;
		}
		else if (state == OUT){
			arr[i][j++] = c;
			state = IN;
		}
		else if (state == IN)
			arr[i][j++] = c;
	}


	for (i = maxLen; i >= 0; i--){
		for ( j = 0; j < nw; j++ ){
			tempMaxLen = maxLen;
			if (arr[j][i] != '\0'){
				putchar('*');
				while (--tempMaxLen)
					putchar(' ');
			}
			while (tempMaxLen--)
				putchar(' ');
		}
		putchar('\n');
	}

	for (i = 0; i < nw; i++){
		for (j = 0; arr[i][j] != '\0'; j++){
			putchar(arr[i][j]);
		}
		while (j++ < maxLen)
			putchar(' ');
	}
}