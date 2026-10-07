#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n; cin>>n;
    vector<ll> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    if(n==1){
        cout<<nums[0]<<endl;
        return;
    }
    ll ans=LLONG_MAX;
    ll current=0;
    for(int i=1;i<=n-1;i++){
        ll w=nums[i]+nums[i-1];
        current+=w;
        ll cost=nums[0]+current+(n-1-i)*w;
        ans=min(cost,ans);
    }
    current=0;
    for(int i=1;i<=n-1;i++){
        ll w=nums[(n-i+1)%n]+nums[(n-i)%n];
        current+=w;
        ll cost=nums[0]+current+(n-1-i)*w;
        ans=min(cost,ans);
    }
    cout<<ans<<endl;
}
int main(){
    int T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}