/*
题意：n堆石子 我们要合并成一堆 每次合并石子的代价为这个2个石子的重量之和，求最大代价 和最小代价
题解：定义dp[i][j]为合并区间i到j石子的最小代价
s为石子重量的前缀和 
dp[i][j]怎么求？？
dp[i][j]一定可以是写成这样的dp[i][k]+dp[k+1][j]+s[j]-s[i-1]; 这相当于就是以k为分界点了 讲k之前的和k之和的合并
dp[i][k]+dp[k+1][j]就是yi以k为分界点的代价  s[j]-s[i-1]就是 合并这次代价 
*/
#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=130;
int a[N];
int dp[N][N];
int dp1[N][N];
void init()
{
	memset(dp,0,sizeof dp);
	return ;
}
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]+=a[i-1];
		}
		init();
		for(int len=2;len<=n;len++)
		{
			for(int i=1;i+len-1<=n;i++)
			{
				int j=i+len-1;
				dp1[i][j]=2e9;
				for(int k=i;k<j;k++)//易错点 分界k必须从左边界开始 
				{
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[j]-a[i-1]);
					dp1[i][j]=min(dp1[i][j],dp1[i][k]+dp1[k+1][j]+a[j]-a[i-1]);
				}
			}
		}
		cout<<dp1[1][n]<<" "<<dp[1][n]<<endl; 
		
	}
	return 0;
}
