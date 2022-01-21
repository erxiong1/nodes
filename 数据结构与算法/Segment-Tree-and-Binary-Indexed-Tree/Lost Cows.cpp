/*
题目意思：有n只小动物，每只都有一个独特的编号，分别从1到n。现在他们从左到右依次排在一条直线上，顺序是乱的。
现在，我们只知道每个位置前面有几个比他小的数。请你根据给出的信息计算出每个位置上的数是多少。
输入第一行是一个正整数n，表示小动物的数量。
接下来有n-1个数，第i个数表示在第i+1个位置以前有多少个比第i+1个位置上的数小的数。
输出n行，每行一个整数，表示对应位置小动物的编号。
Sample Input
5
1
2
1
0
Sample Output
2
4
5
3
1
题解：我们只晓得 每个i前面有a[i]个比他小的数
换而言之 就是他是区间[1,i]第rank[i]=a[i]+1大的数字
其实我们要求的也就是a[i]在[1,n]区间第几大(排名  因为这是一个1到n的序列)
因为我们是晓得之前的排名的 那么我们只要考虑他之后的数字会影响他的排名吗
答案是 可能会 所有我们只要将i之后的数字删除掉 之后看看剩下的数字第排名a[i]+1
是多少
那么我们就可以弄n这么大一个桶 初始化桶里所有的元素为1
从n（n是最后一个不受影响）开始算到1位置 每算一个n位置的真实值 
然后求这个桶 那个位置上面的值为1并且 前缀和  最后把这个数删掉
既然用到前缀和 还有用到删除数据 
那么就可以树状数组来写
而找的过程也可以用二分来优化

*/
#include<iostream>
#include<cstdio>
using namespace std;
int n;
const int N=1e5+100;
int rank1[N];//其实保存的不是真正排名 而是 前面有多少个数
int ans[N];
int tr[N];
int lowbit(int i)
{
    return i&-i;
}
int  ask(int i)
{
    int sum=0;
    for(;i;i-=lowbit(i))
    sum+=tr[i];
    return sum;
}
void add(int i,int d)
{
    for(;i<=n;i+=lowbit(i))
    {
        tr[i]+=d;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        tr[i]=lowbit(i);
    }
    for(int i=2;i<=n;i++)
    {
        cin>>rank1[i];
    }
    for(int i=n;i;i--)
    {
        int k=rank1[i]+1;//我是第几小的数
        int l=1;
        int r=n;
        int mid;
        while(l<r)//为什么取最小值等于k的  
        {			//因为当答案是 i是  i+1，i+2，。。。为0时 那么ask(i+1)==ask(i)
					// 并且答案是i是 那么原数组i的值一定为1 那么k<i ask(k)最大只能是ask(i)-1
					//故最小值一定是正解 
            mid=l+r>>1;
            if(ask(mid)>=k)r=mid;//当ask(mid)==k时  答案可能会是r  suo这个时候不能把r排除答案区间 
            else l=mid+1;  
        }
        ans[i]=r;
        add(r,-1);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
