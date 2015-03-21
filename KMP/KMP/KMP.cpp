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
	return origin;
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
			if(state)
				*(next+j)=0;
		}

	}
}

int main()
{
	
	string s="ababcabcacbab";//主串
	string t="abcac";//模式串

	int *next=new int[t.size()];//模式串的next数组

	calculateNext(next,t);
	for(int i=0;i<t.size();i++)
		cout<<*(next+i)<<endl;
	
	int BForigin=BF(s,t);
	cout<<"模式匹配的位置是："<<BForigin<<"->"<<BForigin+t.size()<<endl;
	return 0;
}

