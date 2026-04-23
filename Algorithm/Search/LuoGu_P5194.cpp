#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c;
vector<ll> w;
vector<ll> post_sum;
ll ans=0;
void dfs(int u,ll current_w){
    if(current_w>c) return;
    if(u==n || current_w==c){
        ans=max(ans,current_w);
        return;
    }
    if(current_w+post_sum[u]<=ans) return;
    dfs(u+1,current_w);
    if(current_w+w[u]<=c) dfs(u+1,current_w+w[u]);
}
int main(){
    cin>>n>>c;
    w.resize(n);
    post_sum.resize(n+1);
    post_sum[n]=0;
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=n-1;i>=0;i--) post_sum[i]=post_sum[i+1]+w[i];
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}