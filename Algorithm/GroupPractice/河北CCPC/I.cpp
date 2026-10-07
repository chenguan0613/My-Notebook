#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll mid,int N,vector<ll>& nums,ll M){
    ll total=0;
    for(int i=0;i<N;i++){
        total+=mid/nums[i];
    }
    if(total>=M) return true;
    else return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,m_val=0; cin>>N>>M;
    vector<ll> nums(N);
    for(ll i=0;i<N;i++){
        cin>>nums[i];
        m_val=max(m_val,nums[i]);
    }
    ll lower=0,upper=m_val*M,ans=0;
    while(lower<upper){
        ll mid=lower+(upper-lower)/2;
        if(check(mid,N,nums,M)){
            ans=mid;
            upper=mid;
        }
        else{
            lower=mid+1;
        }
    }
    cout<<ans;
    return 0;
}