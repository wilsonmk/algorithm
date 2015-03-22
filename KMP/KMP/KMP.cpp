// KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include<string>
using namespace std;

int BF(string s,string t)//Brute-Force,简单匹配算法
{
	int origin=-1;//模式匹配的起始位置
	for(int i=0;i<s.size();i++)
	{
		int k;
		for(k=0;k<t.size();k++)
		{
			if(s[i+k]!=t[k])
				break;
		}
		if(k==t.size())//匹配成功
		{
			origin=i;
			break;
		}
	}
	return origin;//匹配成功返回起始位置，失败就返回-1
}

//计算next数组，t为计算字符串
void calculateNext(int * & next,string t)
{
	for(int j=0;j<t.size();j++)
	{
		bool state=true;//是否是等于0的情况
		if(j==0)
			*next=-1;
		else 
		{
			int k=j-1;//0<k<j,获取最大的k
			while(k>0)
			{
				string str1="",str2="";
				for(int i=0;i<=k-1;i++)
				{
					str1=str1+t[i];
					str2=str2+t[j-k+i];
				}
				if(str1==str2)//若，p[0....k-1]=p[j-k...j-1];
				{	
					*(next+j)=k;
					state=false;//不是等于0的情况
					break;
				}
				k--;
				
			}
			if(state)//满足其他条件，即为0
			 *(next+j)=0;
		}

	}
}

//kmp匹配算法,s为主串，t为模式串
int KMP(int * next,string s,string t)
{
	int j=0,i=0;//i为主串s正在匹配的字符，j为t正在匹配的字符
	
	while(i<s.size()&&j<t.size())
    {
        if(t[j] == s[i])
        {
            j++;i++;
        }
        else
        {
            if(j==0) 
            {
                i++;//若第一个字符就匹配失败，则从s的下一个字符开始
            }
            else
            {
				
                j = *(next+j);//,也可以j=next[j],用next确定t应回溯到的字符
            }
        }
    }
    if(j < t.size())//整个过程匹配失败
    {
        return -1;
    }
    return i-t.size();//匹配成功
	//第二种写法
	/*2. while(i < s.size())  
         {  
                  while(j > -1 && t[j] != s[i])  
                          j = next[j];  
                  i++, j++;  
                  if(j >= t.size()) return i - j;  
         }  
	 return -1;  */


	
}


int main()
{
	
	string s="ababcabcacbab";//主串
	string t="acbab";//模式串

	int *next=new int[t.size()];//模式串的next数组

	calculateNext(next,t);

	for(int i=0;i<t.size();i++)
		cout<<*(next+i)<<endl;
	
	int BForigin=BF(s,t);
	if(BForigin==-1)
		cout<<"BF匹配失败！"<<endl;
	else
	
	cout<<"BF算法模式匹配的位置是："<<BForigin<<"->"<<BForigin+t.size()<<endl;

    int KMPorigin=KMP(next,s,t);
	if(KMPorigin==-1)
		cout<<"KMP匹配失败！"<<endl;
	else
	cout<<"KMP算法模式匹配的位置是："<<KMPorigin<<"->"<<KMPorigin+t.size()<<endl;
	return 0;
}

