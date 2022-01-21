/*
题意：给你有26个字母的密码表，a[i]表示第i个字母经过密码表转变成的密码
字符。（如a[2]==‘c’，表示字母‘b’加密后变成‘c’）
现在有一条信息，前一半为经过加密的字符，后一半为前一半加密前的字符。不过由
于某些原因，后一半的部分内容消失了，你现在的任务是，恢复整条信息的内容。
题解：可以先想到，密文肯定是大于len/2.
那么就找到了明文是后半段，（不一定）。设这一串为T。
之后根据加密方法，逆推：把串2都转换为原文。设此串为p
对p求next，并与s进行kmp即可。（返回j jj值,成功匹配的个数，即串2中有的原文）
输出（考虑到要转换，可以先把串2输出，之后再把不齐的补全即可）。
*/
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1e5+10;
int nxt[maxn];
char p[maxn],s[maxn];
void getnxt(char *p){
    int m = strlen(p);
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<m){
        if(j==-1||p[i]==p[j])nxt[++i]=++j;
        else j=nxt[j];
    }
}
int kmp(char *s, char *p){
    int n = strlen(s);
    int i=0, j=0;
    while(i<n){
        if(j==-1||s[i]==p[j])i++,j++;
        else j=nxt[j];
    }
    return j;
}
char ch[26];
int main()
{
    int tt;cin>>tt;
    while(tt--){
        char x;
        for(int i=0; i<26; i++)cin>>x,ch[x-'a']=i+'a';
        cin>>p;
        cout<<p;
        int len = strlen(p);
        int i=0,j=(len+1)/2;
        for(i,j; j<len; i++,j++)s[i]=p[j];//ch[p[i]-'a'];
        s[i]='\0';
        for(i=0; i<len; i++)p[i]=ch[p[i]-'a'];
        //cout<<s<<endl;
        getnxt(p);
        int res=kmp(s,p);
        for(int i=res; i<len-res; i++)cout<<p[i];
        cout<<endl;
    }
    return 0;
}

