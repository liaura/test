//小登录程序
#include<stdio.h>
#include<string.h>

int main()
{
	char username[] = "admin\n";
	char password[] = "123456\n";
	char tmp_u[10] = {0}, tmp_p[10] = {0};
	int i = 0;
	while(i < 3)
	{
		printf("请输入用户名：");
		fgets(tmp_u, 10, stdin);
		if(strlen(tmp_u) == 9 && tmp_u[8] != '\n')
		{
			scanf("%*[^\n]");
			scanf("%*c");
		}
		printf("请输入密码：");
		fgets(tmp_p, 10, stdin);
		if(strlen(tmp_p) == 9 && tmp_p[8] != '\n')
		{
			scanf("%*[^\n]");
			scanf("%*c");
		}
		if(!strcmp(username, tmp_u) && !strcmp(password, tmp_p))
		{
			break;
		}
		else if(i < 2)
		{
			printf("输入账户名或密码错误！\n");
		}
		i++;
	}
	if(3 == i)
	{
		printf("输入三次错误，登录失败!\n");
	}
	else
	{
		printf("登录成功！\n");
	}
	return 0;
}

