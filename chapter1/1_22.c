/*********************
make one line to some small line
***********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

void del(char *arr, int colNum);
int main(int argc, char **argv)
{
	char	arr[MAXLINE];	
	while (fgets(arr, MAXLINE, stdin) != NULL){
		del(arr, 10);
	}

	return 0;
}
void del(char *arr, int colNum)
{
	char	strArr[MAXLINE][MAXLINE];
	int		i = 0;
	int		col = 0;
	int		row = 0;
	int		isSpace = 1;
	for (i = 0; arr[i] != '\n'; i++){
		if (' ' == arr[i] || '\t' == arr[i] ){
			if (isSpace == 0){
				strArr[row++][col++] = '\0';
				col = 0;
			}
			isSpace = 1;
			strArr[row][col++] = arr[i];
			isSpace = 0;
		}
		else{
			isSpace = 1;
			col = 0;
			str
		}
	}
}
