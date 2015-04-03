#include<iostream>
using namespace std;

//冒泡排序
void BubbleSort(int a[],int len)
{
	int i,j,temp;
	bool change;//判断是否已经排好序

	for(i=0;i<len-1;i++)
	{
		change=false;
		for(j=len-1;j>i;j--)
		{
			if(a[j]<a[j-1])//两两比较
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				change=true;//有交换为true
			}
		
		}
		//没进行交换，说明已经排好序，结束算法
		if(!change)
		 break;
	}

	//输出结果
	for(int i=0;i<10;i++)
		cout<<a[i]<<"  ";
}


void QuickSort(int a[],int start,int end)//a[start]至a[end]进行快速排序
{
	int temp;
	
	int i=start,j=end;
	if(j>i)//至少存在2个元素
	{
		temp=a[i];//等于当前快排区间的第一个元素

		while(i!=j)
		{
			//从后向前找到第一个小于temp的元素
			while(j>i&&a[j]>temp)
				j--;
			a[i]=a[j];

			//从前往后找到第一个大于temp的元素
			while(i<j&&a[i]<temp)
				i++;
			a[j]=a[i];

		}
		a[i]=temp;

		QuickSort(a,start,i-1);//对左区间递归排序

		QuickSort(a,i+1,end);//对右区间递归排序
	}
}

int main()
{
    int a[11] = {3,1,5,7,2,4,9,6,18,8,-3};  
	
	//BubbleSort(a,10);//希尔排序
	QuickSort(a,0,10);//10,数组长度减一
	//输出结果

	
	for(int i=0;i<11;i++)
		cout<<a[i]<<"  ";
	return 0;
}