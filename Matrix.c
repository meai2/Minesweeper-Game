#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random(int m,int n)//this function generates random number and returns it.
{
int num = (rand() + 1) % (m*n + 1);
return num;
}
int main()
{
char grid[50][50];
int neighbour[50][50];
int m,n;
float p;
printf("Enter m and n: ");
scanf("%d %d",&m,&n);
do
{
printf("Enter p: ");
scanf("%f",&p);
}

while(p<0 || p>1);
int i,j;
for(i=0;i<m+1;i++)
for(j=0;j<n+1;j++)
grid[i][j] = '.';
  
int bombs = m*n*p;//bombs stores the number of cells should have bombs.

srand(time(0));
/*srand() sets the seed which is used by rand to generate random numbers. If you don’t call srand before your first call to rand else rand() generates the same sequence of numbers*/


for(i=0;i<bombs;i++)
{
int num,row,col;
//the following do while loop is used to take unique random number for each generation.
do
{
num = random(m,n);
row = num/(n);

if(num/(n)==0)
{
if(num%n==0)
col = 0;
else
col = num%n-1;
}
else
{
if(num%(n)==0)
{
row--;
col = n-1;
}
else{
col = num%(n)-1;
}
}
}while(grid[row][col] == '*');

grid[row][col] = '*';

}
printf("\n");//prints new line.


//the following for loop prints the *,. stored grid array
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
printf("%c ",grid[i][j]);
printf("\n");
}

///BEGIN NEXT MATRIX HERE
for(i=0;i<m;i++)
{

for(j=0;j<n;j++)
{
int count = 0;

//eight conditions to check eight neighbouring cells.
if(grid[i+1][j]=='*')
count++;
if(grid[i-1][j]=='*'&&i>=0)
count++;
if(grid[i][j+1]=='*')
count++;
if(grid[i][j-1]=='*'&&j>=0)
count++;
if(grid[i+1][j+1]=='*')
count++;
if(grid[i+1][j-1]=='*'&&j>=0)
count++;
if(grid[i-1][j+1]=='*'&&i>=0)
count++;
if(grid[i-1][j-1]=='*'&&i>=0&&j>=0)
count++;
if(grid[i][j]=='*')
count=0;

neighbour[i][j] = count;

}
}
printf("\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
grid[i][j] = neighbour[i][j] + '0';//generates grid array from neighbour array of integers.
printf("%c ",grid[i][j]);
}
printf("\n");
}

return 0;
}