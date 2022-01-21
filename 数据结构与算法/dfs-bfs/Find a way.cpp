/*
题意：伊菲的家在乡下，而梅基的家在市中心。于是，伊菲和梅基安排在KFC见面。西安有很多KFC，他们想选择一个花费总时间最短的KFC见面。
现在给你一张西安的地图，伊菲和梅基都可以上、下、左、右移动到相邻的地点，每移动一个位置花费11分钟。

Input
输入包含多个测试用例。
每个测试用例包括前两个整数n，m.（2<=n，m<=200）。
接下来的n行，每行包含m个字符。
“Y”表示伊菲的初始位置。
“M”表示梅基初始位置。
“#”死路；
'.'可走的路。
“@” KCF
题解：bfs枚举每个人到@的最短时间 然后取个最小值 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=210;
char mp[N][N]; 
int book[N][N];
int ans[N][N];
int n;
int m;
struct node
{
	int x;
	int y;
	int f;
};
int ne[4][2]={0,1,1,0,0,-1,-1,0};
void bfs(int startx,int starty)
{
	memset(book,0,sizeof book);
	queue<node>que;
	que.push((node){startx,starty,0});
	book[startx][starty]=1;
	while(!que.empty())
	{
		node t=que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{
			int tx=t.x+ne[i][0];
			int ty=t.y+ne[i][1];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&mp[tx][ty]!='#'&&book[tx][ty]==0)
			{
				que.push((node){tx,ty,t.f+1});
				if(mp[tx][ty]=='@')ans[tx][ty]+=t.f+1;
				book[tx][ty]=1;
			}
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		memset(ans,0, sizeof ans);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",mp[i]+1);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(mp[i][j]=='Y')
				{
					bfs(i,j);
				}
				else if(mp[i][j]=='M')
				{
					bfs(i,j);
				}
			}
		}
		int res=2e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(mp[i][j]=='@'&&ans[i][j]!=0) 
				res=min(ans[i][j],res);
			//	cout<<mp[i][j];
			}
		//	cout<<endl;
		}
		cout<<res*11<<endl;
	}
	//getchar();
	
	return 0;
}
 
