// maze.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;

//定义栈的结构
struct node
{
	int x;
	int y;
	bool state;//方块是否可以通过
	node *next;
	node()
	{
		next=NULL;
		state=true;//默认为false，不可通过
	}
};
//进栈---插入到head之后
void Push(node * &head,int x,int y)
{
	
     node * temp=new node;
	 temp->x=x;temp->y=y;
	 if(head==NULL)
		 head=temp;
	 else
	 {
		 temp->next=head;
		 head=temp;
	 }

}

//出栈--取head后
node Pop(node * &head)
{
	node * ok;node temp;
	if(head!=NULL)
	{
		temp.x=head->x;
		temp.y=head->y;temp.state=head->state;
		ok=head;
		head=head->next;
		delete ok;
	}
	return temp;
	
}

//查看栈中是否含此元素
bool GetItem(node *head)
{
	while(head!=NULL)
	{
		
	}
	return true;
}

int main()
{
	//0表示可以通行
	int map[4][4]={
		{0,0,1,0},
		{1,0,0,0},
		{0,0,1,1},
		{1,0,0,0}
	};
	node *head=NULL;//栈的头指针
	
	for(int i=0;i<10;i++)
	{
		
		Push(head,i,i);

	}
	Pop(head);	Pop(head);	Pop(head);	Pop(head);	
	node * ok=head;
	while(ok!=NULL)
	{
		cout<<"xx: "<<ok->x<<"  yy: "<<ok->y<<endl;
		ok=ok->next;
	}
	return 0;
}

