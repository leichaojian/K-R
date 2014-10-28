/**************************
make one line into some small line
***************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024
#define IN				1		//单词内
#define OUT			0		//单词外
#define MAXLEN	20		//假设最多MAXLEN个单词，每个单词的最大长度为MAXLEN

//将字符串转换为字符数组（包含单词和空白字符串）
int makeLineToWordArr(char *line, char strArr[MAXLEN][MAXLEN], int lenArr[MAXLEN]);
//显示字符
void delLine(char strArr[MAXLEN][MAXLEN], int lenArr[MAXLEN], int len, int colNum);

int main(void)
{
	char		line[MAXLINE];				//所输入的一行数据
	char		strArr[MAXLEN][MAXLEN];	//存储一行数据分割后，所存储的单词和空白字符串
	int			lenArr[MAXLEN];			//存储分割后的每个单词或空白字符串的长度
	int			len = 0;							//总共分割成多少个单词/空白字符串

	memset(line, 0, MAXLINE);
	memset(strArr, 0, MAXLEN * MAXLEN);
	memset(lenArr, 0, MAXLEN);

	while (fgets(line, MAXLINE, stdin) != NULL){
		len = makeLineToWordArr(line, strArr, lenArr);
		delLine(strArr, lenArr, len, 10);
	}

	return 0;
}


int makeLineToWordArr(char *line, char strArr[MAXLEN][MAXLEN], int lenArr[MAXLEN])
{
	int		status;
	int		i = 0;
	int		j = 0;
	int		indexLen = 0;

	//判断开头是空白符还是字符
	if (' ' == *line || '\t' == *line){
		status = OUT;
	}
	else{
		status = IN;
	}
	while (*line != '\n'){
		if (' ' == *line || '\t' == *line){
			if (status == IN){
				status = OUT;
				strArr[i][j] = '\0';
				lenArr[indexLen++] = j;
				i++;
				j = 0;
			}
			if (status == OUT){
				strArr[i][j] = *line;
				j++;
			}
		}
		else{
			if (status == OUT){
				status = IN;
				strArr[i][j] = '\0';
				lenArr[indexLen++] = j;
				i++;
				j = 0;
			}
			if (status == IN){
				strArr[i][j] = *line;
				j++;
			}	
		}
		line++;
	}

	lenArr[indexLen++] = j;

	return indexLen;
}

void delLine(char strArr[MAXLEN][MAXLEN], int lenArr[MAXLEN], int len, int colNum)
{
	int		indexCount = 0;
	int		sum = 0;
	int		i = 0;
	int		j = 0;
	for (i = 0, indexCount = i; i < len; i++){
		sum += lenArr[i];
		if (sum > colNum){
			for (j = indexCount; j < i; j++){
				printf("%s", strArr[j]);
			}
			printf("\n");
			sum = 0;
			indexCount = i;
			i--;
		}
	}
	if (sum < colNum){
		for (j = indexCount; j < i; j++){
			printf("%s", strArr[j]);
		}
		printf("\n");
	}
}