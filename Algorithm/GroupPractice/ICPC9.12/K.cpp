#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n; cin>>n;
    vector<int> nums(n);
    vector<int> count(n+2,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(nums[i]<=n+1){
            count[nums[i]]++;
        }
    }

    int mex=0;
    while(count[mex]>0){
        mex++;
    }
    int q; cin>>q;
    
    unordered_map<int,int> memo;
    set<int> candidates;
    for(int i=0;i<n;i++){
        candidates.insert(mex+nums[i]);
    }
    for(int k:candidates){
        int current_mex=0;
        while(true){
            
        }
    }
}
int main(){
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}