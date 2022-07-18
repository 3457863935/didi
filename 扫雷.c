#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10
void InitBoard(char mine[ROWS][COLS],int rows,int cols,char set)
{
	int i=0,j=0;
	for (i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			mine[i][j]=set;
		}
	}
}
void DisPlay(char mine[ROWS][COLS],int row,int col)
{
	int i=0,j=0;
	for (i=0;i<=row;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for (i=1;i<=row;i++)
	{
		printf("%d ",i);
		for(j=1;j<=col;j++)
		{
			printf("%c ",mine[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char mine[ROWS][COLS],int row,int col)
{
	int x=0,y=0;
	int count=EASY_COUNT;
	while(count)
	{
		x=rand() % row+1;
		y=rand() % col+1;
		if(mine[x][y]=='0')
		{
			mine[x][y]='1';
			count--;
		}
	}
}
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x-1][y-1]+mine[x-1][y]+mine[x-1][y+1]+mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1]+mine[x][y-1]+mine[x][y+1]-8*'0';
}
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x=0,y=0,win=0;
	while(win<row*col-EASY_COUNT)
	{
		printf("输入排查雷的坐标:");
		scanf("%d %d",&x,&y);
		if(x>=1&&x<=row&&y>=1&&y<=col)
		{
			if(mine[x][y]=='1')
			{
				printf("踩雷了，游戏结束\n");
				DisPlay(mine,ROW,COL);
				break;
			}
			else
			{
				int count=get_mine_count(mine,x,y);
				show[x][y]=count+'0';
				DisPlay(show,ROW,COL);
				win++; 
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
	if(win==row*col-EASY_COUNT)
	{
		printf("恭喜你，扫雷成功\n");
		DisPlay(mine,ROWS,COLS);
	}
}
void menu()
{
	printf("---------------------------------------------\n");
	printf("----------------扫雷游戏-------------------\n");
	printf("-------1 .开始-------------0 .退出-----------\n");
}
void game()
{
	char mine[ROWS][COLS]={0};
	char show[ROWS][COLS]={0};
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
//	DisPlay(mine,ROW,COL);
	DisPlay(show,ROW,COL);
	SetMine(mine,ROW,COL);
//	DisPlay(mine,ROW,COL);
	FindMine(mine,show,ROW,COL);	
}
int main()
{
	int input; 
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game(); 
				break;
			case 0:
				break;
			default :
				printf("输入错误，请重新输入:");
				break;
		}
	}while(input);
	return 0;
}

