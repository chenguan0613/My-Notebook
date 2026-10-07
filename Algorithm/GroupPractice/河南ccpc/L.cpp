#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a,b,c,d,e,l,r;
    cin>>a>>b>>c>>d>>e>>l>>r;
    unordered_map<ll,int> mp;
    for(ll i=l;i<=r;i++){
        for(ll j=l;j<=r;j++){
            mp[a*i+b*j]++;
        }
    }
    ll ans=0;
    for(ll i=l;i<=r;i++){
        for(ll j=l;j<=r;j++){
            ll target=e-i*c-d*j;
            if(mp.find(target)!=mp.end()){
                ans+=mp[target];
            }
        }
    }
    cout<<ans;
    return 0;
}