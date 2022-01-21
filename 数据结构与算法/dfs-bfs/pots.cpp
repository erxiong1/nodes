/*
题意:小明给你两个容器，分别能装下A升水和B升水，并且可以进行以下操作
FILL(i)        将第i个容器从水龙头里装满(1 ≤ i ≤ 2);
DROP(i)        将第i个容器抽干
POUR(i,j)      将第i个容器里的水倒入第j个容器（这次操作结束后产生两种结果，一是第j个容器倒满并且第i个容器依旧有剩余，二是第i个容器里的水全部倒入j中，第i个容器为空）
现在要求你写一个程序，来找出能使其中任何一个容器里的水恰好有C升，找出最少操作数并给出操作过程
题解：bfs而已 不过状态枚举比较麻烦要手写很多 
*/ 
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int book[500][500];
const int N=250000+100;
int flag=0;
struct node
{
	int x[2];
	int f;
	char method;
	int i,j;
	int road;
	
}que[N];
int tail;
int head;
int a,b,c;
void check(node t)
{ 
	int t1,t2;
	t1=t.x[0];
	t2=t.x[1];
	t.road=head;
	if(book[t1][t2]==1)return ;
	que[tail++]=t;
	book[t1][t2]=1;
	if(t1==c||t2==c)flag=1;
}
void fill1(node t)
{
	int t1=a;
	int t2=t.x[1];
	int f=t.f+1;
	struct node tt;
	tt=(node){t1,t2,f,'f',1};
	check(tt); 
}
void fill2(node t)
{
	int t1=t.x[0];
	int t2=b;
	int f=t.f+1;
	struct node tt;
	tt=(node){t1,t2,f,'f',2};
	check(tt); 
}
void drop1(node t)
{
	int t1=0;
	int t2=t.x[1];
	int f=t.f+1;
	struct node tt;
	tt=(node){t1,t2,f,'d',1};
	check(tt); 
}
void drop2(node t)
{
	int t1=t.x[0];
	int t2=0;
	int f=t.f+1;
	struct node tt;
	tt=(node){t1,t2,f,'d',2};
	check(tt); 
}
void pour(int &x,int &y,int a,int b)
{
	int t=b-y;
	if(x>=t)
	{
		x-=t;
		y=b;
	}
	else 
	{
		y+=x;
		x=0;
	}
}
void ypoure(node t)
{
	int t1=t.x[0];
	int t2=t.x[1];
	int f=t.f+1;
	pour(t1,t2,a,b);	
	struct node tt;
	tt=(node){t1,t2,f,'p',1,2};
	check(tt); 
}
void epoury(node t)
{
	int t1=t.x[0];
	int t2=t.x[1];
	int f=t.f+1;
	pour(t2,t1,b,a);
	struct node tt;
	tt=(node){t1,t2,f,'p',2,1};
	check(tt); 
}
void print(int i)
{
	if(i==0)return ;
	print(que[i].road);
	switch(que[i].method)
	{
		case 'f':printf("FILL(%d)\n",que[i].i);break;
		case 'p':printf("POUR(%d,%d)\n",que[i].i,que[i].j);break;
		case 'd':printf("DROP(%d)\n",que[i].i);break;
	}
}
void bfs()
{
	que[tail++]=(node){0,0,0};
	book[0][0]=1;
	while(head<tail)
	{
		
		fill1(que[head]);
		if(flag)break;
		fill2(que[head]);
		if(flag)break;
		drop1(que[head]);
		if(flag)break;
		drop2(que[head]);
		if(flag)break;
		ypoure(que[head]);
		if(flag)break;
		epoury(que[head]);
		if(flag)break;
		head++;
	}
	if(flag)
	{
		printf("%d\n",que[tail-1].f);
		print(tail-1);
	}
	else printf("impossible\n");
}
void init()
{
	memset(book,0,sizeof book);
}
int main()
{


	cin>>a>>b>>c;
/*	if(a==c||b==c)
	{
		cout<<0<<endl;
		return 0;
	}*/
	bfs();
	return 0;
}
