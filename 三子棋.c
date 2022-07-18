#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL],int row,int col)
{
	int i=0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			board[i][j]=' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL],int row,int col)
{
	int i=0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %c ",board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		if(i<row-1)
		{
			for(j=0;j<col;j++)
			{
				printf("---");
				if(j<col-1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void PlayMove(char board[ROW][COL],int row,int col)
{
	int x=0,y=0;
	printf("玩家下:\n");
	while(1)
	{
		printf("请输入落子的坐标:");
		scanf("%d %d",&x,&y);
		if(x>=1&&x<=row&&y>=1&&y<=col)
		{
			if(board[x-1][y-1]==' ')
			{
				board[x-1][y-1]='*';
				break;
			}
			else
			{
				printf("输入坐标已满，请重新输入:\n");
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入:\n");
		}
	}	
}
void ComputerMove(char board[ROW][COL],int row,int col)
{
	int x=0,y=0;
	printf("电脑下:\n");
	while(1)
	{
		x=rand()%row;
		y=rand()%col; 
		if(board[x][y]==' ')
		{
			board[x][y]='#';
			break;
		}		
	}	
}
int IsFull(char board[ROW][COL],int row,int col)
{
	int i=0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(board[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL],int row,int col)
{
	int i=0;
	for(i=0;i<row;i++)
	{
		if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]&&board[i][0]!=' ')
			{
				return board[i][0];
			}
	}
	for(i=0;i<col;i++)
	{
		if(board[0][i]==board[1][i]&&board[0][i]==board[2][i]&&board[0][i]!=' ')
			{
				return board[0][i];
			}	
	}
	if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]!=' ')
		{
			return board[0][0];
		}
	if(board[0][2]==board[1][1]&&board[0][2]==board[2][0]&&board[0][2]!=' ')
		{
			return board[0][2];
		}
	if(1==IsFull(board,ROW,COL))
		{
			return 'A';
		}
	return 'B';
}
void menu()
{
	printf("---------------------------------------------\n");
	printf("----------------三子棋游戏-------------------\n");
	printf("-------1 .开始-------------0 .退出-----------\n");
}
void game()
{
	char ret;
	char board[ROW][COL]={0};
	InitBoard(board,ROW,COL);
	DisplayBoard(board,ROW,COL);
	while(1)
	{
		PlayMove(board,ROW,COL);
		system("cls");
		DisplayBoard(board,ROW,COL);
		ret=IsWin(board,ROW,COL);
		if(ret!='B')
		{
			break;
		}
		ComputerMove(board,ROW,COL);
		system("cls");
		DisplayBoard(board,ROW,COL);
		ret=IsWin(board,ROW,COL);
		if(ret!='B')
		{
			break;
		}
	}   
	if(ret=='*')
	{
		printf("玩家赢！\n");
		Sleep(1000);
		system("cls");
	}
	else if(ret=='#')
	{
		printf("电脑赢！\n");
		Sleep(1000);
		system("cls");	
	}
	else
	{
		printf("平局！\n");
		Sleep(1000);
		system("cls");
	} 
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

