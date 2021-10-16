#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    char grid[MAX][MAX];
    int i,j,row,col;

	printf("Row: ");
	scanf("%d",&row);

	printf("Col: ");
	scanf("%d",&col);


    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            grid[i][j] = 'o';
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}