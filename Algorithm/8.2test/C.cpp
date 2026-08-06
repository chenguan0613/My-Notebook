#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    vector<vector<ll>> ans;
    while(t--){
        ll n,m,k;
        ll last=0;
        vector<ll> res;
        cin>>n>>m>>k;
        for(int i=0;i<m;i++){
            ll l,r;
            cin>>l>>r;
            ll cur=max(l,last+1);
            while(cur<r){
                res.push_back(cur);
                last=cur+k-1;
                cur=last+1;
            }
        }
        ans.push_back(res);
    }
    for(auto& x:ans){
        cout<<x.size();
        for(auto& y:x){
            cout <<" "<<y;
        }
        cout<<endl;
    }
    return 0;
}