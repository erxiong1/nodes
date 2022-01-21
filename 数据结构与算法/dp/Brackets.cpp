/*
题意：用以下方式定义合法的括号字符串

1.空串是合法的
2. 如果S是合法的, 那么(S)和[S]也都是合法的
3. 如果A和B是合法的, 那么AB是一个合法的字符串.
求最大匹配长度
题解：定义dp[i][j]是区间dp[i][j]的最大匹配长度
求一个新的dp[i][j] 我们可以判断如果 i 和 j 可以匹配
那么可以有状态 dp[i][j]=dp[i+1][j-1]+2;
还要 如果A和B是合法的, 那么AB是一个合法的字符串
那么我们也可以枚举所有i到j的点为分界点
然后组合起来 取最大值 
 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e2+5;
int dp[N][N];
string s;

bool check(int a, int b) {
    if (s[a] == '(' && s[b] == ')') return true;
    else if (s[a] == '[' && s[b] == ']') return true;
    else return false;
}
int main()
{
	while(cin>>s)
	{
		if(s=="end")return 0;
		int n=s.size();
		memset(dp,0,sizeof dp);
		for(int len=1;len<n;len++)
		{
			for(int i=0,j=len+i;j<n;j++,i++)
			{
				//j=len+i-1;
				if(check(i,j))dp[i][j]=dp[i+1][j-1]+2;
				//cout<<1<<endl;
				for(int k=i;k<j;k++)
				{
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
			}
		}
		cout<<dp[0][n-1]<<endl;
	}
	return 0;
}
