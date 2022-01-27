// range -> [a,b]
// https://codeforces.com/contest/628/problem/D
#include<bits/stdc++.h>
using namespace std;
int m,d;
string a,b;
const int mod=1e9+7;
int dp[2005][2001][2][2];
int fun(int pos,int rem,int l,int r){
    if(pos==a.size()) return rem==0;
    int &x=dp[pos][rem][l][r];
    if(x!=-1) return x;
    int ll=(l==0)?a[pos]-'0':0;
    int rr=(r==0)?b[pos]-'0':9;
    int ans=0;
    for(int i=ll;i<=rr;i++){
        if((pos&1)^(i==d)) continue;
        ans=(ans+fun(pos+1,(10*rem+i)%m,l||(i>a[pos]-'0'),r||(i<b[pos]-'0')))%mod;
    }
    return x=ans;
}
int main(){
    cin>>m>>d;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<fun(0,0,0,0);
}
