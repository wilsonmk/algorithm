
#include<iostream>
using namespace std;

//归并排序====================================================

//合并有序数列a[first...mid]和a[mid+1...last]， a[first...mid]和a[mid+1...last]一定为有序
void Combine(int a[], int first, int mid, int last)  
{  
	int *temp=new int[last-first+1];//临时记录数组

    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;  

     //两两对比
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
      
	//将剩下的记录放到temp中
    while (i <= m)  
        temp[k++] = a[i++];  
      
    while (j <= n)  
        temp[k++] = a[j++];  
      
	//将temp复制回a
    for (i = 0; i < k; i++)  
        a[first + i] = temp[i];  

	delete [] temp;//释放temp内存
}  

//归并排序
void mergesort(int a[], int first, int last)  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        mergesort(a, first, mid);    //左边有序  
        mergesort(a, mid + 1, last); //右边有序  
        Combine(a, first, mid, last); //再将二个有序数列合并  
    }  
}  


//============================================================


//基数排序======================================================

#define MAXSIZE 10 //桶里最大放多少值
//桶的结构
struct node
{
	int key[MAXSIZE];//桶里的数据
	int count;//桶里数据的个数
	node()
	{
		count=0;//count为0表示桶内没数字
	}
};

//各个位的值获取
int GetNumInPos(int num,int pos)  
{  
    int temp = 1;  
    for (int i = 0; i < pos - 1; i++)  
        temp *= 10;  
  
    return (num / temp) % 10;  
}  


//基数排序
void RadixSort(int a[],int len)
{
	//获取a数组的最大值来确定装几次桶
	int max=0;	
	for(int i=0;i<len;i++)
	{
		if(a[i]>max)
		  max=a[i];
	}
	//计算装桶次数d
	int d=1;
	int temp=10;
	while(true)
	{
		
		if(max/temp>0)
		{
			d++;//次数加一
			temp*=10;
		}
		else
			break;
	}
	
	

	node head[10];//10个桶 

	int pos=1;//获取哪个位上的树，1表示个位

	while(d>=pos)
	{
		//依次把数组的数字放进相应桶里
		for(int i=0;i<len;i++)
		{
			int id=GetNumInPos(a[i],pos);
			head[id].key[head[id].count]=a[i];
			head[id].count++;
		}

		//依次从桶里去除数据赋值给a数组
		int num=0;
		for(int i=0;i<10;i++)
		{
			if(head[i].count!=0)
			{
				for(int j=0;j<head[i].count;j++)
				{
					a[num]=head[i].key[j];
					num++;
				}

				//清空桶
			    head[i].count=0;
			}
			
		}

		pos++;

		
	}
}

//=============================================================
int main()
{
	int a[10]={75,23,98,44,57,12,29,2464,318,82};	//待排序列

	//mergesort(a,0,9);//调用归并排序

	RadixSort(a,10);//基数排序
	for(int i=0;i<10;i++)//输出结果
		cout<<a[i]<<" ";

	return 0;
}
