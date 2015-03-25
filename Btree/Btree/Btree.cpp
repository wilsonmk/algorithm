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
		 
		 CreateTree(root->lchild);
		
		 CreateTree(root->rchild);
		
	 }
}

//检查二叉树是否包含数据aim,有则返回其指针
node * Findnode(node * & root,string aim)
{
	node * p;
	if(root==NULL)//空树
		return NULL;
	else if(root->data==aim)
		return root;
	else
	{	
		p=Findnode(root->lchild,aim);
		if(p!=NULL)
			return p;
		else
			return Findnode(root->rchild,aim);	
	}
}
void  PreOrder(node * root)//先序遍历
{
	if(root!=NULL)
	{
		cout<<root->data;
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}
void  InOrder(node * root)//中序遍历
{
	if(root!=NULL)
	{
		
		InOrder(root->lchild);
		cout<<root->data;
		InOrder(root->rchild);
	}
}
void  PostOrder(node * root)//后序遍历
{
	if(root!=NULL)
	{
		
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		cout<<root->data;
	}
}

int NodeHeight(node * root)//计算二叉树高度
{
	int lchild,rchlid;
	if(root==NULL)
		return 0;
	else
	{
		lchild=NodeHeight(root->lchild);
		rchlid=NodeHeight(root->rchild);
		return (lchild>rchlid)?(lchild+1):(rchlid+1);
	}
}

void Showleaf(node * root)
{
	if(root!=NULL)
	{
		if(root->lchild==NULL&&root->rchild==NULL)
			cout<<root->data<<" ";
		Showleaf(root->lchild);//输出左子树叶子节点
		Showleaf(root->rchild);//输出右子树叶子节点
	}
}
int main()
{
	node * root=NULL;//根节点
	CreateTree(root);//生成二叉树
	int i=0;
	cout<<"请输入要查找的结点"<<endl;
	string data;
	cin>>data;
	if(Findnode(root,data))
		cout<<"查找成功"<<endl;
	else
		cout<<"查找失败"<<endl;

	cout<<"二叉树的深度为： "<<NodeHeight(root)<<endl;

	cout<<"二叉树先序遍历： ";
	PreOrder(root);
	cout<<endl;

	cout<<"二叉树中序遍历： ";
	InOrder(root);
	cout<<endl;

	cout<<"二叉树后序遍历： ";
	PostOrder(root);
	cout<<endl;

	cout<<"二叉树叶子节点有： ";
	Showleaf(root);
	cout<<endl;
	
	return 0;
}

