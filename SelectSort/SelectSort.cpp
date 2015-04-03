

#include<iostream>
using namespace std;

//直接选择排序
void  SelectSort(int a[],int len)
{
	int k,j;
	for(int i=0;i<len-1;i++)//要进行len-1趟选择
	{
		k=i;

		for(j=i+1;j<len;j++)//寻找最小，从未排序区间开始，即i+1
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}
		//i本身不是最小
		if(k!=i)
		{
			int temp=a[k];
			a[k]=a[i];
			a[i]=temp;
		}
	}

	for(int i=0;i<len;i++)
		cout<<a[i]<<" ";
}


//堆排序--初始化堆函数
//完全二叉树若根节点n为从0开始，则左孩子为2n+1，右孩子为2n+2。
void  init(int a[],int start,int end)//对a[low....high]进行初始化
{
	int temp = a[start];

    for(int i = 2*start + 1; i<=end; i*=2)
    {
        //因为假设根结点的序号为0而不是1，所以i结点左孩子和右孩子分别为2i+1和2i+2
        if(i<end &&a[i]<a[i+1])//左右孩子的比较
        {
            i++;//i为较大的记录的下标
        }

        if(temp > a[i])//左右孩子中获胜者与父亲的比较
        {
            break;
        }

        //将孩子结点上位，则以孩子结点的位置进行下一轮的筛选
        a[start]= a[i];
        start = i;
        
    }

    a[start]= temp; //插入最开始不和谐的元素

}

//推排序
void HeapSort(int a[],int len)
{
	//先建立大顶堆
    for(int i=len/2; i>=0; --i)
    {
        init(a,i,len);
    }
    //进行排序
    for(int i=len-1; i>0; --i)
    {
        //最后一个元素和第一元素进行交换
        int temp=a[i];
        a[i] = a[0];
        a[0] = temp;

        //然后将剩下的无序元素继续调整为大顶堆
        init(a,0,i-1);
    }
	
	//输出结果
	for(int i=0;i<len;i++)
		cout<<a[i]<<" ";
}
int main()
{
    int a[12] = {3,1,5,7,2,4,9,6,18,8,-3,-5};  
	
	//SelectSort(a,12);
	HeapSort(a,12);
	return 0;
}