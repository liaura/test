/*
*** 扫雷
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i = 0, j = 0, k = 0, a[10][10] = {0};
	int b[][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
	srand(time(0));
	/*for(i = 0; i < 10; i++)
	{
		j = rand()%10;
		k = rand()%10;
		if(-1 == a[j][k])
		{
			i--;
			break;
		}
		else
		{
			a[j][k] = -1;
		}
	}*/
	i = 0;	//在10*10的地图中生成10个地雷，用-1代表；
	do
	{
		j = rand() % 10;	//生成地雷的行范围
		k = rand() % 10;	//生成地雷的列范围
		while( !a[j][k] )
		{
			a[j][k] = -1;
			i++;
		}
	}while(i < 10);	//生成地雷的数目

	for(i = 0; i < 10; i++)		//在十个地雷周围的空格里填数
	{
		for(j = 0; j < 10; j++)
		{
			if(a[i][j] != -1)
			{
				continue;
			}
			for(k = 0; k < 8; k++)
			{
				int m = i + b[k][0];
				int n = j + b[k][1];
				if(m < 0 || m >= 10)
				{
					continue;
				}
				if(n < 0 || n >= 10)
				{
					continue;
				}
				if(-1 == a[m][n])
				{
					continue;
				}
				a[m][n]++;
			}
		}
	}

	for(i = 0; i < 10; i++)	//打印出图形，0代表空，-1代表地雷，其他数代表周围地雷数目；
	{
		for(j = 0; j < 10; j++)
		{
			if(a[i][j] < 0)
			{
				printf("X ");
			}
			else if(0 == a[i][j])
			{
				printf("O ");
			}
			else 
			{
				printf("%d ", a[i][j]);
			}
			// 	printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
