/*
题意：HUEL_ACM队的队长给出了一个序列，想让学妹帮队长干活，作为学妹（或者想帮助某个漂亮的学妹）的你需要处理如下两种情况。

"C a b c"表示给[a, b]区间中的值全部增加c (-10000 ≤ c ≤ 10000)。

"Q a b" 询问[a, b]区间中所有值的和。

Input
第一行包含两个整数N, Q。1 ≤ N,Q ≤ 100000.

第二行包含n个整数，表示初始的序列A (-1000000000 ≤ Ai ≤ 1000000000)。

接下来Q行询问，格式如题目描述。

Output
对于每一个Q开头的询问，你需要输出相应的答案，每个答案一行。

Sample Input
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Sample Output
4
55
9
15
题解：
线段树维护区间和加上区间修改 懒标记优化 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
int m;
const int N=200000+1000;
int a[N];
struct node
{
	int l;
	int r;
	long long add;
	long long sum;
}tr[N*4+100];
void pushup(int u)
{
	tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
	return ; 
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]={l,r,0,(long long )a[l]};
		return ;
	}
	tr[u]={l,r,0};
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void pushdown(int u)
{
	if(tr[u].add!=0)
	{
		long long t=tr[u].add;
		tr[u<<1].add+=t;
		tr[u<<1|1].add+=t;
		tr[u<<1].sum+=(tr[u<<1].r-tr[u<<1].l+1)*t;
		tr[u<<1|1].sum+=(tr[u<<1|1].r-tr[u<<1|1].l+1)*t;
		tr[u].add=0;
	}
	return ;
}
long long query(int u,int l,int r)
{
	pushdown(u);
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		return tr[u].sum;
	}
	int mid=(tr[u].l+tr[u].r)>>1;
	long long ans=0;
	if(l<=mid)ans+=query(u<<1,l,r);
	if(r>mid)ans+=query(u<<1|1,l,r);
	return ans;
}
void modify(int u,int l,int r,long long x)
{
	pushdown(u);
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		tr[u].add+=x;
		tr[u].sum+=(tr[u].r-tr[u].l+1)*x;
		return ;
	}
	int mid=(tr[u].l+tr[u].r)>>1;
	if(l<=mid)
	{
		modify(u<<1,l,r,x);
	}
	if(r>mid)
	{
		modify(u<<1|1,l,r,x);
	}
	pushup(u);
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	build(1,1,n);
	while(m--)
	{
		char ch[4];
		cin>>ch;
		if(ch[0]=='Q')
		{
			int l,r;
			cin>>l>>r;
			cout<<query(1,l,r)<<endl;
		}
		else 
		{
			int l,r;
			long long x;
			cin>>l>>r>>x;
			modify(1,l,r,x);
		}
	}
	return 0;
}
