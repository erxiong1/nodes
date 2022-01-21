/*
题意：一个四位数变成另外一个四位数的最小代价
每次操作的方案是 要么让相邻我个数字交换 或者让 某一个数字增加1或者减少1
题解：string存四位数map存 这个四位数是否存在 然后bfs 
*/ 
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
const int N=1e5+1000;
struct node
{
	string now;
	int f;
}que[N];
string change(int i,int j,string a)
{
	swap(a[i],a[j]);
	return a;
}
string change1(string a,int i)
{
	if(a[i]=='9')
	{
		a[i]='1';
	}
	else a[i]++;
	return a;
}
string change2(string a,int i)
{
	if(a[i]=='1')
	{
		a[i]='9';
	}
	else a[i]--;
	return a;
}
int bfs(string start,string end)
{
	map<string ,int>book;
	int tail,head;
	tail=head=0;
	head=tail=0;
	book[start]=1;
	que[tail++]=node{start,0};
	while(head<tail)
	{
		for(int i=0;i<4;i++)
		{
			
			for(int j=i-1;j<i&&j>=0;j++)
			{
				string x=que[head].now;
				string t=change(i,j,x);
				if(!book[t])
				{
			//		cout<<t<<endl;
					que[tail++]={t,que[head].f+1};
					if(t==end)return que[head].f+1;
					book[t]=1;
				}
			}
			string temp1=change1(que[head].now,i);
			string temp2=change2(que[head].now,i);
		//	cout<<temp1<<endl;
		//	cout<<temp2<<endl;
			if(!book[temp1])
			{
			//	cout<<temp1<<endl;
				que[tail++]={temp1,que[head].f+1};
				book[temp1]=1;
				if(temp1==end)return que[head].f+1;
			 } 
			if(!book[temp2])
			{
			//	cout<<temp2<<endl;
				que[tail++]={temp2,que[head].f+1};
				book[temp2]=1;
				if(temp2==end)return que[head].f+1;
			 } 
		}
		head++;
	 } 
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string a;
		string b;
		cin>>a>>b;
		if(a==b)cout<<0<<endl;
		else 
		cout<<bfs(a,b)<<endl;
	 } 
	return 0;
}
