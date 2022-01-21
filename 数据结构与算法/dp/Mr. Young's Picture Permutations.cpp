/*
题意： 给出n行，每行有人数限制num[i]，
并且num[i]>=num[i+1]，总人数暂且称为tot
=∑num[i]，把1~tot这些数字填入矩阵，使得
矩阵满足每行单调递增，每列单调递增，求满
足要求的矩阵数目
题解：杨氏矩阵又叫杨氏图表，它是这样一个矩阵，满足条件：
(1)如果格子(i,j)没有元素，则它右边和上边的相邻格子也一定没有元素。
(2)如果格子(i,j)有元素a[i][j]，则它右边和上边的相邻格子要么没有元素，
要么有元素且比a[i][j]大。
1 ~ n所组成杨氏矩阵的个数可以通过下面的递推式得到：
f(1)=1,f(2)=2
f(n)=f(n-1)+(n-1)f(n-2),(n>2)
 
 
*/ 
#include<cstdio>  
#include<cstring>  
int gcd(int a,int b)  
{  
    return b==0?a:gcd(b,a%b);  
}   
int d[36];  
int num[36];  
int main()  
{  
    int n;  
    while(scanf("%d",&n)&&n)  
    {  
    for(int i=1;i<=n;i++)  
    scanf("%d",&d[i]);  
    int tot=0;  
    memset(num,0,sizeof(num));  
    for(int i=n;i>=1;i--)  
    {  
        for(int j=1;j<=d[i];j++)  
        {  
            tot++;  
            for(int k=i+1;k<=n;k++)  
            if(d[k]>=j)  
            num[tot]++;  
            else  
            break;  
            num[tot]+=d[i]-j+1;  
        }     
    }  
    long long int t1=1,t2=1;  
    for(int i=1;i<=tot;i++)  
    {  
        t1*=i;   
        t2*=num[i];  
        int t=gcd(t1,t2);  
        t1/=t;  
        t2/=t;  
    }  
    printf("%lld\n",t1/t2);  
   }  
   return 0;  
}  
