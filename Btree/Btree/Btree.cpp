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
		 cout<<"zou"<<endl;
		 CreateTree(root->lchild);
		 cout<<"you"<<endl;
		 CreateTree(root->rchild);
		 cout<<"endl"<<endl;
	 }
}

//检查二叉树是否包含数据aim
bool Findnode(node * & root,string aim)
{
	if(root==NULL)//空树
		return false;
	else
	{
		if(root->data==aim)
			return true;
		else
		{
			Findnode(root->lchild,aim);
			Findnode(root->lchild,aim);
		}

	}
}

int main()
{
	node * root=NULL;//根节点
	CreateTree(root);//生成二叉树
	
	return 0;
}

