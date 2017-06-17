//根据一定规则校验身份证号是否正确

#include<stdio.h>
int main()
{
	int i = 0, arr[17] = {0}, sum = 0, cizhi1[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}, cizhi2[11] = {1, 0, -1, 9, 8, 7, 6, 5, 4, 3, 2};
	long long num = 0;
	printf("请输入身份证前17位数字：");
	scanf("%lld", &num);
	for(i = 16; i >= 0; i--)
	{
		arr[i] = num % 10;
		num /= 10;
	}
	for(i = 0; i < 17; i++)
	{
		//printf("%d ", arr[i]);
		sum += arr[i] * cizhi1[i];
	}
	int jieguo = 0;
	jieguo = cizhi2[sum%11];
	if( -1 == jieguo)
	{
		printf("x\n");
	}
	else
	{
		printf("最后一位是：%d\n", jieguo);
	}
	return 0;
}
