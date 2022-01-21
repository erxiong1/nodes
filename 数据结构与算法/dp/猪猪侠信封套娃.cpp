/*
题意：给定n w1 h1 其中w h为要必须寄出去的信的宽和高 
然后 n组输入 w,h每组为信封的宽和高 现在要我们把信放入信封 然后用信封套信封 信放入信封的条件是
信封的宽和高必须严格大于 信的宽和高 信封放入信封的条件也是一样 求最多套娃次数 以及套娃的信封由那些
由里层信封编号向外层信封编号输出
但是如果信件放不进去信封 那么就输出一个0就行了 
题解：定义dp[i]为 以i为最外层的信封最多能套的信封
dp[i]怎么求？
我们只要枚举 所有宽和高校园i的dp值 然后找一个dp最大值套入dp[i]内就行了
路径怎么输出？
每次套入信封 就记录一下由谁套入就行了 然后递归输出路径 
*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=5000+100;
int w[N];
int h[N];
int dp[N]; //表示第i个结点可以被套dp[i]个信封 
int road[N];
int n; 
int dfs(int u)
{
	if(dp[u]!=-1)return dp[u];
	dp[u]=1;
	 for(int i=1;i<=n;i++)
	 {
	 	if(i!=u&&w[u]<w[i]&&h[u]<h[i])
	 	{
	 		//dp[u]=max(dp[u],dfs(i)+1);
	 		if(dp[u]<dfs(i)+1)
	 		{
	 			dp[u]=dp[i]+1;
	 			road[u]=i;
			 }
		 }
	 }
	 return dp[u]; 
}
void print(int u)
{
	
	cout<<u<<" ";
	if(road[u]!=0)
	print(road[u]);
	
	
}
int main()
{
	int w1,h1;
	cin>>n>>w1>>h1;
	int res=0;
	int resi=0;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>h[i];
	}
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		if(w1<w[i]&&h1<h[i])
		{
			dfs(i);
			//res=max(res,dp[i]);
			if(res<dp[i])
			{
				resi=i;
				res=dp[i];
			}
		}
	//	cout<<dp[i]<<endl;
	}
	cout<<res<<endl;
	if(res!=0)
	print(resi);
	return 0;
 } 
