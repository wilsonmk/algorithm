// MakeTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

#define INF 100000 //表示不可到达

#define MAXSIZE 6 //表示图的结点个数

//邻接矩阵存储图的信息
int map[MAXSIZE][MAXSIZE]={
	{0,4,2,3,INF,INF},
	{4,0,5,4,3,INF},
	{2,5,0,1,INF,2},
	{3,4,1,0,6,2},
	{INF,3,INF,6,0,4},
	{INF,INF,2,2,4,0}
};

//用来存储最小生成树的边和权值
struct path
{
	int start;
	int end;
	int weight;
};

//普里姆算法--最小生成树
void Prim(int v)//v起始点
{
	path lowcost[MAXSIZE];//邻近点（未被标记）的最小距离

	path tree[MAXSIZE-1];  //存放最小生成树

	int visited[MAXSIZE]={0};  //已经访问的结点为1

	path min;

	for(int i=0;i<MAXSIZE;i++)
	{
		lowcost[i].weight=map[v][i];
		lowcost[i].start=v;	
		lowcost[i].end=i;
	}

	//循环查找路径，查找次数为结点数减1
	for(int j=0;j<MAXSIZE-1;j++)
	{
		//获取权值不为0且最小的边
		min.weight=INF;
		for(int i=0;i<MAXSIZE;i++)
		{
			
			if(lowcost[i].weight!=0&&lowcost[i].weight<min.weight)
			{
				min=lowcost[i];
			}
		}

		tree[j]=min;//获取最小权值，存入最小生成树数组里

		visited[v]=1;//已访问

		v=min.end;//修改起始点

		//修改lowcost数组
		for(int i=0;i<MAXSIZE;i++)
	    {
			//若新的权值小于之前的权值，则更改
			if(map[v][i]<lowcost[i].weight)
			{
				lowcost[i].weight=map[v][i];
				lowcost[i].start=v;
				lowcost[i].end=i;
			}

			//已经访问的结点为0
			if(visited[i]==1)
               lowcost[i].weight=0;

	    }

	}

	//输出生成的最小二叉树的结果
	for(int i=0;i<MAXSIZE-1;i++)
	{
		cout<<tree[i].start<<"->"<<tree[i].end<<"  "<<tree[i].weight<<"  "<<endl;
	}

}

int main()
{
	Prim(0);//起始点为0
	return 0;
}

