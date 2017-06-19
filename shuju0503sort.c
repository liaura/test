//编程实现各种排序算法

#include<stdio.h>

//1.实现冒泡排序算法
void bubble(int arr[], int len)
{
	int i = 0, j = 0;
	//使用外层循环控制比较的轮数
	for(i = 1; i < len; i++)
	{
		int flag = 1;	//扫描改动标志，如果不变说明已经排好序，省略余下轮数
		//使用内层循环控制针对当前轮比较的元素下标
		for(j = 0; j < len - i; j++)
		{
			//如果第一个元素大于第二个元素，则变换元素位置
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 0;	//表明有数据元素发生交换
			}
		}

		//如果上一轮的扫描中没有发生交换，省略剩余的轮数
		if(1 == flag)
		{
			break;
		}
	}
}


//2.实现插入排序算法
void insort(int arr[], int len)
{
	int i = 0, j = 0;
	//从第二个元素起，依次取出每个元素
	for(i = 1; i < len; i++)
	{
		//使用临时变量记录取出的当前元素
		int temp = arr[i];
		//使用取出的元素与左边的有序数列依次比较，如果左边的元素大，则左边的元素右移
		for(j = i; arr[j-1] > temp && j >= 1; j--)
		{
			arr[j] = arr[j-1];
		}
		//直到左边的元素不再大于取出元素时，插入取出元素
		if( j != i)
		{
			arr[j] = temp;
		}
	}
}


//3.实现选择排序算法
void choose(int arr[], int len)
{
	int i = 0, j = 0;
	//从第一个元素起依次取出，使用min记录下标
	for(i = 0; i < len - 1; i++)
	{
		//使用取出的元素与后续元素依次比较，如果找到比min记录元素还小的元素，则重新记录下标
		int min = i;
		for(j = i + 1; j < len; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		//直到min记录的元素与后续所有元素比较完毕，交换min记录的元素和最开始取出的元素值
		if( min != i)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}


//4.实现快速排序算法
void quick(int arr[], int left, int right)
{
	int i=0,j=0;	
	//1.寻找中间元素作为基准值，单独保存
	int p=(left+right)/2;
	int pivot=arr[p];
	//2.分别使用左边元素和右边元素与基准值进行比较，将小于基准值的元素放在左边，将大于等于基准值的元素放在右边；
	for(i=left,j=right;i<j;)
	{
		//如果左边元素存在并且小于基准值时
		while(arr[i]<pivot&&i<p)
		{
			i++;
		}
		//如果左边元素存在，但是大于等于基准值
		if(i<p)
		{
			arr[p]=arr[i];
			p=i;
		}

		//接下来处理右边的元素
		while(pivot<=arr[j]&&p<j)
		{
			j--;
		}
		//
		if(p<j)
		{
			arr[p]=arr[j];
			p=j;
		}
	}
	//3.将基准值放在重合的位置上
	arr[p]=pivot;
	//4.分别对左边分组和右边分组重复以上过程，使用递归处理
	if(p-left>1){
		quick(arr,left,p-1);
	}
	if(right-p>1){
		quick(arr,p+1,right);
	}
}

int main()
{
	int arr[9] = {20, 5, 30, 10, 15, 6, 25, 12, 28};
	//使用排序算法进行排序
	//bubble(arr, 9);
	insort(arr, 9);
	//choose(arr, 9);
	//quick(arr, 0, 8);
	printf("排序后的结果是：");
	int i = 0;
	for(i = 0; i < 9; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}

	
