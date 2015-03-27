// Dijkstra.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<vector>
using namespace std;

#define INF 10000 //表示不可到达

#define MAXSIZE 7 //表示图的结点数

//邻接矩阵存储图的信息
int map[MAXSIZE][MAXSIZE]={
	{0,4,6,6,INF,INF,INF},
	{INF,0,1,INF,7,INF,INF},
	{INF,INF,0,INF,6,4,INF},
	{INF,INF,2,0,INF,5,INF},
	{INF,INF,INF,INF,0,INF,6},
	{INF,INF,INF,INF,1,0,8},
	{INF,INF,INF,INF,INF,INF,0}
};

void Dijkstra(int v)
{
	int away[MAXSIZE];//保存到各个点的最短距离
	int path[MAXSIZE];//最短距离路径
	int already[MAXSIZE]={0};//是否已经找到最短距离，1表示找到了

	for(int i=0;i<MAXSIZE;i++)
	{
		away[i]=map[v][i];//获取权值

		if(away[i]<INF)//存在路径为0
			path[i]=0;
		else
			path[i]=-1;//不存在路径为-1

	}
	already[v]=1;//把顶点v加入到找到数组里

	//开始寻找最短距离
	int min,ok;
	for(int i=0;i<MAXSIZE;i++)
	{
		
		min=INF;
		for(int k=0;k<MAXSIZE;k++)
		{
			if(already[k]==0&&away[k]<min)//找away里的最小值，且该顶点不在already里
			{
				min=away[k];
				ok=k;//记录最小的顶点
			}
		}
		already[ok]=1;//把顶点ok加入到找到数组里

		//修改away和path数组
		for(int j=0;j<MAXSIZE;j++)
		{
			if(already[j]==0)//此结点还没有最短距离
			{
				if(map[ok][j]<INF&&(away[ok]+map[ok][j])<away[j])
				{
					away[j]=away[ok]+map[ok][j];
					path[j]=ok;//修改path,修改过away权值的把path改为顶点值
				}
			}
		}

		
	}

	//根据path输出路径
	
	for(int h=0;h<MAXSIZE;h++)
			cout<<away[h]<<" ";
	cout<<endl;
	for(int h=0;h<MAXSIZE;h++)
			cout<<path[h]<<" ";

	for(int s=0;s<MAXSIZE;s++)
	{
		if(s!=v)//除去起点
		{
			if(already[s]==1)
			{
				cout<<endl<<"从顶点"<<v<<"到顶点"<<s<<"的最小距离为： "<<away[s]<<"  "<<"路径为: ";
				
				vector<int>temp;
				temp.insert(temp.begin(),s);//把终点插入
				int ok=s;
				while(true)
				{
				   ok=path[ok];
				   if(ok==0)
					   break;
				   temp.insert(temp.begin(),ok);
			   
				}
				temp.insert(temp.begin(),v);//把起点插入
				for(int z=0;z<temp.size();z++)
					cout<<temp[z]<<" ";
			}
			else
				cout<<endl<<"从顶点"<<v<<"到顶点"<<s<<"不存在路径"<<endl;
		}
	}
}

int main()
{
	Dijkstra(0);//计算0顶点到其他各顶点的最短距离
	return 0;
}

