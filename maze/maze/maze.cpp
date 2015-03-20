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
	int direction;//1代表向右，2代表向下，3代表向左，4代表向上，存放探索方向,下一次探索的方向
	node *next;
	int above;//上一块是哪个方向探索下来的，防止左右上下死循环
	node()
	{
		next=NULL;
	}
};

//进栈---插入到head之后
void Push(node * &head,int x,int y,int direction,int above)
{
	
     node * temp=new node;
	 temp->x=x;temp->y=y;temp->direction=direction;
	 temp->above=above;

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
	temp.above=head->above;
	return temp;
}


//修改栈顶元素方向
void Change(node * & head,int drection)
{
	head->direction=drection;
}


int main()
{
	//0表示可以通行，入口为（0，0），出口为（3，3）
	int map[BLOCKNUM][BLOCKNUM]={
		{0,1,1,0},
		{0,0,0,0},
		{0,0,1,1},
		{1,0,0,0}
	};
	node *head=NULL;//栈的头指针
	Push(head,0,0,1,0);//入口进栈
	//探索路径
	while(true)
	{
	    if(Getpop(head).x==3&&Getpop(head).y==3)//找到出口，停止循环
			break;
		//对下一块进行探测
		bool sea=true;
		node  temp;

		//每一步路径探索
		while(sea)
		{
			temp=Getpop(head);		
			//temp.above!=4条件防止左右或上下循环走
			//temp.direction为前进方向
			switch (temp.direction)
			{
			case 1:
				//探索成功，即向右可以，且上一步来的方向不是左，防止左右死循环，探索成功，方向加一，便于下次回溯换一个方向探索
				if((temp.y+1)<BLOCKNUM&&map[temp.x][temp.y+1]==0&&temp.above!=3)
				{
					Change(head,temp.direction+1);	
					Push(head,temp.x,temp.y+1,1,1);//探索成功进栈
					sea=false; //停止循环
					
				}
				else
				{
					Change(head,temp.direction+1);		//向右探索失败，探索方向加一，继续探索
				}
			
				break;
			case 2:
				if((temp.x+1)<BLOCKNUM&&map[temp.x+1][temp.y]==0&&temp.above!=4)
				{
					Change(head,temp.direction+1);
					Push(head,temp.x+1,temp.y,1,2);
					sea=false;
				}
				else
				{
					Change(head,temp.direction+1);
				}
				break;
			case 3:
				if((temp.y-1)>=0&&map[temp.x][temp.y-1]==0&&temp.above!=1)
				{
					Change(head,temp.direction+1);
					Push(head,temp.x,temp.y-1,1,3);
					sea=false;
				}
				else
				{
					Change(head,temp.direction+1);
				}
				break;
			case 4:
				if((temp.x-1)>=0&&map[temp.x-1][temp.y]==0&&temp.above!=2)
				{
					Change(head,temp.direction+1);
					Push(head,temp.x-1,temp.y,1,4);
					sea=false;
				}
				else
				{
					Pop(head);
					sea=false;
				}
				break;
			default://即当temp.direction==5，此方块已经把所有方向都探索完了，把他出栈
				Pop(head);
				sea=false;
				break;
			}
		}
		
	}
	node *kk=head;
	cout<<"走出迷宫路径为："<<endl;
	//方向是反的，因为栈先进后出，可以自己进行处理实现顺序路径
	while(kk!=NULL)
	{		
		cout<<"("<<kk->x<<","<<kk->y<<")"<<endl;
		kk=kk->next;
	}

	
	return 0;
}

