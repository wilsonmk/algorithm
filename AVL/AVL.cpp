
//平衡二叉树

#include<iostream>
#include<queue>
using namespace std;

//平衡二叉树的建立，遍历，，

//树结点结构
struct node
{
	int data;//数据
	int bf;//平衡因子
	node*lchild,*rchild;
	node()
	{
		lchild=rchild=NULL;
	}
};

//平衡因子为  左子树高度-右子树高度
#define LH +1   //表示左边高  即1
#define EH 0    //表示等高    即0
#define RH -1  //表示右边高   小减大，即-1

void R_rotate(node * &p){//右旋，
	node * lc=p->lchild;
	p->lchild=lc->rchild;
	lc->rchild=p;
	p=lc;
}
void L_rotata(node * &p){//左旋，
	node * rc=p->rchild;
	p->rchild=rc->lchild;
	rc->lchild=p;
	p=rc;

}





void Leftbalance(node * &T){//左子树的平衡处理
	node * lc=T->lchild;
	switch(lc->bf){
	//LL的情况
	case LH:
		T->bf=lc->bf=EH;
		R_rotate(T);
		break;

	case RH://LR的情况，同时针对rd上的不同情况，进行对T，lc的平衡因子的设置
		node * rd=lc->rchild;
		switch(rd->bf){
			case LH:T->bf=RH; lc->bf=EH;break;
			case EH:T->bf=lc->bf=EH;break;
			case RH:T->bf=EH;lc->bf=LH;break;
		}
		rd->bf=EH;
		L_rotata(T->lchild);
		R_rotate(T);
	}


}


void Rightbalance(node * &T)//右子树的平衡处理，与左子树的平衡处理类似
{
	node * rc=T->rchild;
	switch (rc->bf)
	{
		case RH:
			T->bf=rc->bf=EH;
			L_rotata(T);break;
		case LH:
		   node * ld=rc->lchild;
			switch(ld->bf){
		case LH:
			T->bf=EH; rc->bf=RH;break;
		case EH:
			T->bf=rc->bf=EH;break;
		case RH:
			T->bf=LH; rc->bf=EH;break;

			}
			ld->bf=EH;
			R_rotate(T->rchild);
			L_rotata(T);
	}

}


bool InsertAVL(node * &T,int e,bool &taller){
	if(!T){//此结点为空，则插入，并设置该点平衡因子为0，taller为true，长高了
		T=new node;
		T->data =e; 
		T->lchild=T->rchild=NULL;  
		T->bf=EH;
		taller=true;
	}
	else
	{
		if(e==T->data)//已经存在，不插入，返回0;
		{
			taller =false;
			return 0;
		}
		if(e<T->data)//如果e小于本结点，则继续在左子树搜索，
		{
			 if(!InsertAVL(T->lchild,e,taller))
				 return 0;//未插入，返回0;
			 if(taller)//已经插入到了左子树，则要检查平衡度，
			 {        //注意！检查平衡度是由下往上的，哪个结点的失去平衡，则对该结点进行平衡操作
				switch(T->bf)
				{
				   case LH:   //本结点本来左比右高，现在插入了，所以要做平衡处理
					  Leftbalance(T);
					  taller=false; 
					  break;
				   case EH:  //本来等高，现在插入了，所以本结点平衡因子为1;taller 设为false ，进入下一个递归的时候，不需要在检查平衡；
					  T->bf=LH; 
					  taller=true;
					  break;
				   case RH://本来右边高，现在插入了，所以本结点平衡因子为0;taller 设为false ，进入下一个递归的时候，不需要在检查平衡；
					  T->bf =EH; 
					  taller=false; 
					  break;
				}

			 }

		}
		else
		{//在右子树中查找
				if(!InsertAVL(T->rchild,e,taller))
					return 0;//未插入，返回0;
				if(taller)
				{ //同上，检查平衡
				  switch(T->bf)
				  {
					case LH://本来左高，现在等高
						T->bf=EH; 
						taller=false; 
						break;
					case EH://本来平衡，现在右增高了，所以本结点平衡因子为-1.taller为true，进入下一个递归是继续检查平衡，
						T->bf=RH;
						taller=true;
						break;
					case RH://本来右高，现在右又增高了，所以失去平衡，对该节点进行平衡处理
						Rightbalance(T);
						taller=false;
						break;
				  }
			}
		}


	}

	return 1;
}

//输出函数
void cengcitravel(node * T){
    node * p;
    queue<node *>sq;
    sq.push(T);
	while(!sq.empty()){
	 p=sq.front();
	 cout<<p->data<<" ";
	if(p->lchild)sq.push(p->lchild);
	if(p->rchild)sq.push(p->rchild);
	 sq.pop();
	}

}


int main(){
	node * T=NULL;
	bool f=false;//表示是否插入成功，成功为true

	int data[9]={16,3,7,11,9,26,18,14,15};
	for(int i=0;i<9;i++)
	{
		InsertAVL(T,data[i],f);//插入结点
	}
	
	cengcitravel(T);//输出序列
	cout<<endl;

	return 0;
}