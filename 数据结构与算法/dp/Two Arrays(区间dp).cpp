/*
题意：给定2个数组a[N],a[N] 我们可以的操作只有反转某一数组的一个子区间 使得
a[i]*b[i]+...a[N-1]*b[N-1](简称乘积之和)最大 输出反转之后的乘积之和 
题解：定义dp[i][j]为反转a数组i到j使得a[i]*b[i]+...a[N-1]*b[N-1]变化贡献
怎么求dp[i][j]??
区间【i，j】反转的值正好就是 区间【i+1，j-1】的贡献+交换a[i]和a[j]的贡献 
那么答案 就是枚举dp[i][j]的所有值取一个最大值 然后加上原来的乘积之和就行了(反转a的区间和反转b的区间贡献是一样的)
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N=5000+100;
long long dp[N][N];
long long a[N];
long long b[N];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		cin>>b[j];
	}
	long long res=0;
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=len+i-1;
			
			dp[i][j]=dp[i+1][j-1]+a[i]*b[j]+a[j]*b[i]-a[i]*b[i]-a[j]*b[j];//直接转移就行了 
			res=max(dp[i][j],res);
		}
		
	 } 
	 for(int i=1;i<=n;i++)
	 {
	 	res+=a[i]*b[i];
	 }
	 cout<<res<<endl; 
	return 0;
}
