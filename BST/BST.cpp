
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//树结点结构
struct node
{
	int key;//关键字项
	node * lchild;
	node * rchild;
	node()
	{
		lchild=rchild=NULL;
	}
};

//二叉排序树节点插入
int  Insert(node * &root,int key)
{
	if(root==NULL)
	{
		root=new node;
		root->key=key;
		return 1;//插入成功
	}
	else if(key==root->key)//已经存在
		return 0;//插入失败

	else if(key<root->key)//插到左子树
		return Insert(root->lchild,key);
	else
		return Insert(root->rchild,key);

}

//二叉排序树创建
void Create(node * &root)
{
	int a[]={9,7,10,5,8,15,4,6,14};//结点数据
	for(int i=0;i<9;i++)
	   Insert(root,a[i]);//节点插入
	
}

//节点查找
node * Search(node * root,int key)
{
	if(root==NULL)
		return NULL;
	if(root->key==key)
		return root;
	if(root->key>key)
		return Search(root->lchild,key);//左子树查找
	else
		return Search(root->rchild,key);//右子树查找
}

void Delete2(node * & root, node * & right)//要用引用类型，因为要对树本身操作
{
	node * temp;
	if(right->rchild!=NULL)//即找到左子树最右下的结点，即左子树最大值,此时的right指向这个最大结点
		Delete2(root,right->rchild);
	else
	{
		root->key=right->key;
		temp=right;
		right=NULL;
		delete temp;
	}
}

int Delete(node * &root,int key)
{
	if(root==NULL)
		return 0;//空树失败
	else
	{
		if(root->key>key)
			return Delete(root->lchild,key);//递归左子树删除

		else if(root->key<key)
			return Delete(root->rchild,key);//递归右子树删除
		
		else//找到了key值的结点
		{
			//删除
			if(root->rchild==NULL&&root->lchild==NULL)//没有左右子树，即叶子结点，直接删除
			{
				node * temp=root;
				root=NULL;
				delete temp;
				
				//2.delete root;能删除叶子结点，但父结点的lchild或rchild没置NULL
			}

			else if(root->rchild==NULL)//没有右子树。
			{
				 node *temp=root;
				 root=root->lchild;
				 delete temp;
			}
			else if(root->lchild==NULL)//没有左子树
			{
				 node *temp=root;
				 root=root->rchild;
				 delete temp;
			}
			//有左右子树
			else
			{
				Delete2(root,root->lchild);//要用引用类型，因为要对树本身操作
				 
			}
			return 1;
		}


	}
}



int main()
{
	node *root=NULL;//根节点
	Create(root);

	node * ok=Search(root,7);
	cout<<ok->lchild->key<<endl;
	Delete(root,7);
	
	return 0;
}

