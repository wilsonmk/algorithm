// maze.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;

#define BLOCKNUM 4//迷宫地图大小

//主要问题，会左右上下死循环

//定义栈的结构
struct node
{
	int x;//行
	int y;//列  对应map[x][y]
	int direction;//1代表向右，2代表向下，3代表向左，4代表向上，存放探索方向
	node *next;
	node()
	{
		next=NULL;
	}
};

//进栈---插入到head之后
void Push(node * &head,int x,int y,int direction)
{
	
     node * temp=new node;
	 temp->x=x;temp->y=y;temp->direction=direction;
	 if(head==NULL)
		 head=temp;
	 else
	 {
		 temp->next=head;
		 head=temp;
	 }

}

//出栈--取head后
void Pop(node * &head)
{
	node * ok;
	if(head!=NULL)
	{
		
		ok=head;
		head=head->next;
		delete ok;
	}
	
	
}

//获取栈顶元素
node Getpop(node * head)
{
	node temp;
	temp.x=head->x;
	temp.y=head->y;
	temp.direction=head->direction;
	return temp;
}


//修改栈顶元素方向
void Change(node * & head,int drection)
{
	head->direction=drection;
}


int main()
{
	//0表示可以通行
	int map[BLOCKNUM][BLOCKNUM]={
		{0,0,1,0},
		{1,0,0,0},
		{0,0,1,1},
		{1,0,0,0}
	};
	node *head=NULL;//栈的头指针
	Push(head,0,0,1);//入口进栈
	
	int i=0;
	while(i<10)
	{
		i++;
		//对下一块进行探测
		bool sea=true;
		node  temp;
		int dre=-1;//记录前进的方向，防止左右上下死循环
		while(sea)
		{
			temp=Getpop(head);
			
			cout<<temp.direction<<endl;
			switch (temp.direction)
			{
			case 1:
				//cout<<temp.x<<"  huoqu "<<temp.y<<"  map[temp.x+1][temp.y]:"<<map[temp.x+1][temp.y]<<endl;
				if((temp.y+1)<BLOCKNUM&&map[temp.x][temp.y+1]==0)
				{
					Push(head,temp.x,temp.y+1,1);
					sea=false;
					
				}
				else
				{
					Change(head,temp.direction+1);		
				}
			
				break;
			case 2:
				if((temp.x+1)<BLOCKNUM&&map[temp.x+1][temp.y]==0)
				{
					Push(head,temp.x+1,temp.y,1);
					sea=false;
				}
				else
				{
					Change(head,temp.direction+1);
				}
				break;
			case 3:
				if((temp.y-1)>=0&&map[temp.x][temp.y-1]==0)
				{
					Push(head,temp.x,temp.y-1,1);
					sea=false;
				}
				else
				{
					Change(head,temp.direction+1);
				}
				break;
			case 4:
				if((temp.x-1)>=0&&map[temp.x-1][temp.y]==0)
				{
					Push(head,temp.x-1,temp.y,1);
					sea=false;
				}
				else
				{
					Pop(head);
				}
				break;
			default:
				break;
			}
		}
	}
	node *kk=head;
	while(kk!=NULL)
	{
		cout<<kk->x<<"  "<<kk->y<<"  "<<kk->direction<<endl;
		kk=kk->next;
	}

	
	return 0;
}

