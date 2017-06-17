//彩票练习
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int arr[7] = {0}, i = 0, j = 0;
	srand(time(0));
	for(i = 0; i < 7; i++)
	{
		arr[i] = rand()%36 + 1;
		for(j = 0; j < i; j++)
		{
			if(arr[i] == arr[j])
				break;
		}
		if(i != j)
		{
			i--;
		}
	}
	printf("生成的彩票号码为：");
	for(i = 0; i < 7; i++)
	{
		printf("%d ",arr[i]);
		fflush(stdout);//强制及时输出（不使用输出缓冲区）
		sleep(1);		//延时下一步，以秒为单位
	}
	printf("\n");
	return 0;
}
