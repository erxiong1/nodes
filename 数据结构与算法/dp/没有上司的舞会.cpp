/*
题意：有一群人搞聚会 告诉你每个人的开心值并且告诉你这群人的上司和下属的关系
求不存在上司下属关系的最大开心值
题解：将每个人的开心值存起来 然后链式向星建图 因为是上下级关系 数据一定存在
最高级别的上司 那么这个图就可以看作为有根树  根就是最高级别上司
然后定义dp[i][0]为以i为根i这个人不去的最大开心值
dp[i][1]为以i为根这个人去的最大开心值
dp[i][0]怎么求？
dp[i][0]i是不去的 那么儿子去或者不去都是满足题意的 
那么让dp[i][0]最大就是求所有儿子max(dp[son][0],dp[son][1])之和 
dp[i][1]怎么求？？
dp[i][1]i是去的 那么儿子就不能去 所有就是求所有dp[son][0]之和
最终答案就是max(dp[root][0],dp[root][1]); 
*/
#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=6000+100;
int start[N];
int ne[N];
int idx;
int happy[N];
int root[N];
int e[N]; 
int dp[N][2];
void add(int y,int x)
{
	e[idx]=y;
	ne[idx]=start[x];
	start[x]=idx++;
	root[y]=1;
	return ;
}
void init()
{
	memset(start,-1,sizeof start);
	memset(root,0,sizeof root);
	idx=0;
}
void dfs(int u)
{
	dp[u][1]=happy[u];
	dp[u][0]=0; 
	for(int i=start[u];~i;i=ne[i])
	{
		int t=e[i];
		dfs(t);
		dp[u][1]+=dp[t][0];
		dp[u][0]+=max(dp[t][0],dp[t][1]);
	}
	return ;
}
int main()
{
	while(cin>>n)
	{
		init();
		for(int i=1;i<=n;i++)
		{
			cin>>happy[i];
		}
		while(1)
		{
			int x;
			int y;
			cin>>x>>y;
			if(x==0&&y==0)break;
			add(x,y);
		}
		int x=1;
		while(root[x])x++;
		dfs(x);
		cout<<max(dp[x][0],dp[x][1])<<endl;
	}
	return 0;
 } 
