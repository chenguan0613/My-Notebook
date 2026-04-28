#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> woods;
bool check(ll x,ll limit){
    ll count=0;
    for(ll wood : woods){
        count+=(wood-1)/x;
    }
    return count<=limit;
}
int main(){
    ll N,K; cin>>N>>K;
    ll Max=0;
    while(N--){
        ll len; cin>>len;
        Max=max(Max,len);
        woods.push_back(len);
    }
    ll lower_bound=1,upper_bound=Max;
    ll ans=upper_bound;
    while(lower_bound<=upper_bound){
        ll mid=lower_bound+(upper_bound-lower_bound)/2;
        if(check(mid,K)){
            ans=mid;
            upper_bound=mid-1;
        }
        else{
            lower_bound=mid+1;
        }
    }
    cout<<ans;
    return 0;
}