//贪吃蛇
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 20
#define APPLE '@'
#define SNAKE_HEAD '+'
#define SNAKE_TAIL '-'
typedef struct
{
	int row,col;
}pt;
typedef struct
{
	pt head,tail;
}snake;
enum {UP, DOWN, LEFT, RIGHT};
enum {NOOVERLAP, OVERLAP};
void init_snake(snake *p_snake)
{	//设置蛇的位置
	p_snake->head.row = rand() % (SIZE - 2) + 1;
	p_snake->head.col = rand() % (SIZE - 2) + 1;
	switch(rand() % 4)
	{
	case UP:
		p_snake->tail.row = p_snake->head.row - 1;
		p_snake->tail.col = p_snake->head.col;
		break;
	case DOWN:
		p_snake->tail.row = p_snake->head.row + 1;
		p_snake->tail.col = p_snake->head.col;
		break;
	case LEFT:
		p_snake->tail.row = p_snake->head.row;
		p_snake->tail.col = p_snake->head.col - 1;
		break;
	case RIGHT:
		p_snake->tail.row = p_snake->head.row;
		p_snake->tail.col = p_snake->head.col + 1;
		break;
	}
}

void init_apple(pt *p_apple)	//设置苹果的位置
{
	p_apple->row = rand() % SIZE;
	p_apple->col = rand() % SIZE;
}

void show_map(const pt* p_apple, const snake* p_snake)	//显示蛇和苹果的位置
{
	int row = 0, col = 0;
	for(row = 0; row < SIZE; row ++)
	{
		for(col = 0; col < SIZE; col++)
		{
			if(row==p_apple->row&&col==p_apple->col)
			{
				printf("%c",APPLE);
			}
			else if(row==p_snake->head.row&&col==p_snake->head.col)
			{
				printf("%c",SNAKE_HEAD);
			}
			else if(row==p_snake->tail.row&&col==p_snake->tail.col)
			{
				printf("%c",SNAKE_TAIL);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void move_snake(snake *p_snake)
{		//移动蛇的位置
	int direction = 0;
	printf("请选择一个方向，%d代表上，%d代表下，%d代表左，%d代表右\n",UP,DOWN,LEFT,RIGHT);
	scanf("%d",&direction);
	pt tmp = p_snake->head;
	switch(direction) 
	{
		case UP:
			tmp.row--;
			break;
		case DOWN:
			tmp.row++;
			break;
		case LEFT:
			tmp.col--;
			break;
		case RIGHT:
			tmp.col++;
			break;
	}
	if(tmp.row<0||tmp.row>SIZE-1||tmp.col<0||tmp.col>SIZE-1)
	{
		return;
	}
	if(tmp.row==p_snake->tail.row&&tmp.col==p_snake->tail.col)
	{
		return;
	}
	p_snake->tail=p_snake->head;
	p_snake->head=tmp;
}

int overlap(const pt *p_apple,const snake *p_snake)
{		//判断蛇和苹果的位置是否重叠
	if(p_snake->head.row==p_apple->row&&p_snake->head.col==p_apple->col)
	{
		return OVERLAP;
	}
	if(p_snake->tail.row==p_apple->row&&p_snake->tail.col==p_apple->col)
	{
		return OVERLAP;
	}
	return NOOVERLAP;
}

int main(){
	pt apple={0};
	snake snake1={0};
	srand(time(0));
	init_apple(&apple);
	init_snake(&snake1);
	while(1)
	{
		if(overlap(&apple,&snake1))
		{
			init_apple(&apple);
		}
		else
		{
			break;
		}
	}
	show_map(&apple,&snake1);
	while(1)
	{
		move_snake(&snake1);
		while(1)
		{
			if(overlap(&apple,&snake1))
			{
				init_apple(&apple);
			}
			else
			{
				break;
			}	
		}
		show_map(&apple,&snake1);
	}
	return 0;
}
