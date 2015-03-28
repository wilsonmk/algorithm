// Floyd.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

#define INF 99999 //表示不可到达

#define MAXSIZE 4 //表示图的结点数

//邻接矩阵存储图的信息
/*int map[MAXSIZE][MAXSIZE]={
	{0,4,6,6,INF,INF,INF},
	{INF,0,1,INF,7,INF,INF},
	{INF,INF,0,INF,6,4,INF},
	{INF,INF,2,0,INF,5,INF},
	{INF,INF,INF,INF,0,INF,6},
	{INF,INF,INF,INF,1,0,8},
	{INF,INF,INF,INF,INF,INF,0}
};*/
int map[MAXSIZE][MAXSIZE]={
	{0,5,INF,7},
	{INF,0,4,2},
	{3,3,0,2},
	{INF,INF,1,0}
};

//弗洛伊德算法
void Floyd()
{
	int path[MAXSIZE][MAXSIZE];//保存最短路径

	int A[MAXSIZE][MAXSIZE];//a[i][j]表示当前顶点i到j的最短距离

	//数据初始化
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			A[i][j]=map[i][j];
			path[i][j]=-1;//初始化为-1
		}
	}
	//这个扫描所有点，没有除去对角线和划去的行和列上面的点
	/*for(int diagonal=0;diagonal<MAXSIZE;diagonal++)//左对角线
	{
		for(int k=0;k<MAXSIZE;k++)//行
		{
			
			for(int j=0;j<MAXSIZE;j++)//列
			{
				if(A[k][j]>A[k][diagonal]+A[diagonal][j])
				{
					A[k][j]=A[k][diagonal]+A[diagonal][j];
					path[k][j]=diagonal;
				}
			}
		}
	}
	*/
	for(int diagonal=0;diagonal<MAXSIZE;diagonal++)//左对角线
	{
		for(int k=0;k<MAXSIZE;k++)//行
		{
			if(k!=diagonal)//除去此行所有的点
			{
				for(int j=0;j<MAXSIZE;j++)//列
				{
					 if(j!=diagonal)//除去此列所以的点
					 {
						 if(k!=j)//除去对角线的点
						 {
							 if(A[k][j]>A[diagonal][j]+A[k][diagonal])//满足条件
							 {
								 A[k][j]=A[diagonal][j]+A[k][diagonal];
								 path[k][j]=diagonal;
							 }
						 }
					 }
				}
			}
		}
	}

	//结果输出：
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			if(A[i][j]==INF)
				cout<<"从顶点"<<i<<"到顶点"<<j<<"不存在路径"<<endl;
			else
			{
				cout<<"从顶点"<<i<<"到顶点"<<j<<"最短距离为: "<<A[i][j]<<"  其路径为：";
				vector<int>temp;
				temp.insert(temp.begin(),j);//把终点插入
				int ok1=i,ok2=j;
				while(true)
				{
				   ok1=path[ok1][ok2];
				   if(ok1==-1)
					   break;
				   temp.insert(temp.begin(),ok1);
			   
				}
				
				temp.insert(temp.begin(),i);//把起点插入

				for(int z=0;z<temp.size();z++)
					cout<<temp[z]<<" ";
				cout<<endl;
			}
		}
	}
	



}
int main()
{
	Floyd();
	return 0;
}

