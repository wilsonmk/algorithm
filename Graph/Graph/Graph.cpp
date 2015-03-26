// Graph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

//使用邻接表存储图的信息

//定义邻接表结点的结构
struct node
{
	int data;//结点名
	int weight;//权值
	node * next;//下一个结点的指针
	node()
	{
		next=NULL;
	}
};

//定义邻接表的表头
struct Head
{
	int data;//结点名
	node * first;//执行第一个结点
	Head()
    {
		first=NULL;
	}
};

//定义栈，用栈实现深度优先搜索
struct shed
{
	int data[100];
	int top;
};

//建立邻接表
void Create(Head * & head)
{
	
	while(true)
	{
		int name,wg;
		cin>>name;
		if(name==-1)//输入-1表示链表结束
			break;
		cin>>wg;
		node * temp=new node;
		temp->data=name;
		temp->weight=wg;
		if(head->first==NULL)
			head->first=temp;
		else
		{
			temp->next=head->first;
			head->first=temp;
		}


	}

}


void show(Head * head[])
{
	cout<<head[1]->first->data<<endl;
}

//递归深度优先搜索
void DFS_DG(Head *head[],int v,int visited[])
{
	node * p;
	visited[v]=1;
	cout<<v<<endl;
	p=head[v]->first;
	while(p!=NULL)
	{
		if(visited[p->data]==0)
			DFS_DG(head,p->data,visited);
		p=p->next;
	}
}

void DFS_Shep(Head *head[],int v,int visited[])
{

}
int main()
{
	
	int visited[5]={0};
	Head * head[5];//表头指针数组
	for(int i=0;i<5;i++)
	{
		head[i]=new Head;
		head[i]->data=i;
		cout<<"请输入结点"<<i<<"的表结点的名和权值"<<endl;
		Create(head[i]);

	}
	while(true)
	{
		for(int i=0;i<5;i++)
			visited[i]=0;
		int ok;
		cout<<"起始点为"<<endl;
		cin>>ok;
		if(ok==10)
			break;
	    DFS_DG(head,ok,visited);
	}
	
	return 0;
}

