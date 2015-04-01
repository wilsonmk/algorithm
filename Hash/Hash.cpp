
//哈希表建立查找
#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

#define MAX 13//哈希表长度

#define p 13  //不大于哈希表长度的素数

#define NULLKEY -1  //空关键字

#define DELKEY -2  //删除关键字

//除留余数法加线性探索法建立哈希表
struct node
{
	int key;//关键字
	string data;//数据域
	int num;//探测次数
	//初始化探索次数为0，关键字为空关键字
	node()
	{
		num=0;
		key=NULLKEY;
	}
};

//建立哈希表
void Create(node hash[])
{
	int data[11]={16,74,60,43,54,90,46,31,29,88,77};//生成哈希表数据

	

	for(int i=0;i<11;i++)
	{
		int count=0;
		int temp=data[i];

		//关键字插入
		while(true)
		{
			if(hash[temp%p].key==NULLKEY||hash[temp%p].key==DELKEY)//没冲突
			{
				
				count++;
				hash[temp%p].key=data[i];//关键字插入
				hash[temp%p].num=count;//探索次数
				break;
			}
			else
			{
				temp=(temp+1)%p;//线性探查法
				count++;//探测次数加一
			}
		}
	}

	for(int i=0;i<13;i++)
		cout<<"下标: "<<i<<"  key :  "<<hash[i].key<<" 探索次数: "<<hash[i].num<<endl;

}

//哈希表查找
int Search(node hash[],int key)
{
	int adr=key%p;

	while(hash[adr].key!=NULLKEY&&hash[adr].key!=key)
	{
		adr=(adr+1)%p;
	}
	if(hash[adr].key==key) //查找成功返回地址
		return adr;

	else     //查找失败
		return -1;
}
int main()
{
	node hash[MAX];//哈希表数组
    Create(hash);

	int result=Search(hash,88);
	cout<<result<<endl;
	return 0;
}