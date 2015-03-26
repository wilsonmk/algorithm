// Graph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

#define MAXSIZE 5  //定义图的结点数


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


//建立邻接表
void Create(Head * & head)
{
	
	while(true)
	{
		int name,wg;
		cin>>name;//输入结点
		if(name==-1)//输入-1表示链表结束
			break;
		cin>>wg;//输入权值
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



//递归深度优先搜索
void DFS_DG(Head *head[],int v,int visited[])
{
	node * p;//表结点
	visited[v]=1;
	cout<<v;
	p=head[v]->first;//获取第一个表结点
	while(p!=NULL)
	{
		if(visited[p->data]==0)
			DFS_DG(head,p->data,visited);
		p=p->next;
	}
}

//广度优先搜索遍历--使用队列
void BFS(Head *head[],int v)
{
	node *p;//表结点指针
	
	int queue[MAXSIZE],front=0,rear=0;//顺序队列，front是头，rear是尾，队列是插尾删头，先进先出
	int visited[MAXSIZE]={0};//访问标志数组初始化为0

	//开始访问
	cout<<v;
	visited[v]=1;
	rear=(rear+1)%MAXSIZE;
	queue[rear]=v;//入队

	int ok;
	while(front!=rear)//队列不为空
	{
		front=(front+1)%MAXSIZE;
		ok=queue[front];//出队
		p=head[ok]->first;//获取第一个表结点
		while(p!=NULL)//循环遍历其表结点
		{
			if(visited[p->data]==0)//该表结点没有访问过
			{
				cout<<p->data;
				visited[p->data]=1;
				rear=(rear+1)%MAXSIZE;
				queue[rear]=p->data;//入队
			}
			p=p->next;//找下一个结点
		}
	}
}

int main()
{
	
	int visited[MAXSIZE]={0};
	Head * head[MAXSIZE];//表头指针数组
	for(int i=0;i<MAXSIZE;i++)
	{
		head[i]=new Head;
		head[i]->data=i;
		cout<<"请输入结点"<<i<<"的表结点的名和权值"<<endl;
		Create(head[i]);

	}
	cout<<endl<<"深度优先搜索遍历结果为"<<endl;
	DFS_DG(head,0,visited);

	cout<<"广度优先搜索遍历结果为"<<endl;
	BFS(head,0);

	return 0;
}

