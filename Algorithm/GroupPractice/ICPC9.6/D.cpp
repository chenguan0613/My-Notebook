#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll counts=0;
void check(int x, int y,vector<int>& nums){
    if(x==0 && y==0){
        counts=(counts+1)%MOD;
        return;
    }
    if(x<0 || y<0) return;
    if(x==y){
        if(nums[x]>0){
            nums[x]--;
            ll before=counts;
            check(x-1,y,nums);
            ll added=(counts-before+MOD)%MOD;
            counts=(before+added*2)%MOD;
            nums[x]++;
        }
        return;
    }
    //left
    if(nums[y]>0){
        nums[y]--;
        check(x-1,y,nums);
        nums[y]++;
    }
    //down
    if(nums[x]>0){
        nums[x]--;
        check(x,y-1,nums);
        nums[x]++;
    }
}
int main(){
    int n,len=-1;
    cin>>n;
    vector<int> seq(n);
    for(int i=0;i<n;i++){
        cin>>seq[i];
        len=max(seq[i],len);
    }
    vector<int> nums(n+1,0);
    for(int x:seq){
        nums[x]++;
    }
    check(len,n-len,nums);
    if(len!=n-len){
        counts=(counts*2)%MOD;
    }
    cout<<counts;
    return 0;
}