// Btree.cpp : 定义控制台应用程序的入口点。
//
//二叉树实例

#include "stdafx.h"

#include<iostream>
#include<string>
using namespace std;

//定义树的结构
struct node
{
	node * lchild;
	node * rchild;
	string data;
	//初始化
	node()
	{
		lchild=rchild=NULL;
	}
};
//二叉树生成--先序遍历输入要生成的二叉树数据，#代表空结点
void CreateTree(node * & root)
{
	 char data;
	 cin>>data;
	 if(data!='#')
	 {
		 root=new node;
		 root->data=data;
		 cout<<"左"<<endl;
		 CreateTree(root->lchild);
		 cout<<"you"<<endl;
		 CreateTree(root->rchild);
	 }
}


int main()
{
	node * root=NULL;//根节点
	CreateTree(root);//生成二叉树
	return 0;
}

