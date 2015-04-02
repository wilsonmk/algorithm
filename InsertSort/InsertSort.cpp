
#include<iostream>
#include<string>
using namespace std;


//直接插入排序
void InsertSort(int a[],int len)//递增排列
{
	int temp;
	for(int i=1;i<len;i++)//a[0]在有序区,需要依次把a[1...len-1]插入到有序区
	{
		temp=a[i];
		int j=i-1;//从有序区间最右边对比插入

		while(j>=0&&temp<a[j])//从后到前进行对比
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;

	

	}

	//输出结果
	for(int i=0;i<10;i++)
		cout<<a[i]<<"  ";
}


//二分插入排序
void InsertSort1(int a[],int len)//递增排列
{
	int temp,low,high,mid;
	for(int i=1;i<len;i++)//a[0]在有序区,需要依次把a[1...len-1]插入到有序区
	{
		temp=a[i];
		low=0;high=i-1;
		while(low<=high)//在a[low....high]中二分查找有序插入的位置
		{
			mid=(low+high)/2;
			if(temp<a[mid])
				high=mid-1;
			else
				low=mid+1;
		}
		for(int j=i-1;j>=high+1;j--)
			a[j+1]=a[j];
		a[high+1]=temp;

	

	}

	//输出结果
	for(int i=0;i<10;i++)
		cout<<a[i]<<"  ";
}

//希尔排序
void ShellSort(int a[],int len)
{
	int gap,temp,j;
	gap=len/2;//增量初始值

	while(gap>0)
	{
		for(int i=gap;i<len;i++)//对相隔增量gap位置的所有元素直接插入排序
		{
			temp=a[i];
			j=i-gap;
			while(j>=0&&temp<a[j])//对相隔gap的元素进行排序
			{
				a[j+gap]=a[j];
				j=j-gap;

			}
			a[j+gap]=temp;
			j=j-gap;
		}
		gap=gap/2;
	}

	//输出结果
	for(int i=0;i<10;i++)
		cout<<a[i]<<"  ";
}
int main()
{
    int a[10] = {3,1,5,7,2,4,9,6,18,8};  
	//InsertSort(a,10);//直接插入排序
	//InsertSort1(a,10);//二分插入排序
	ShellSort(a,10);//希尔排序
	return 0;
}