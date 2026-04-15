#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//m means the maximum groups of the sequence partition
//x means the sum_maximum in each groups
bool check(const vector<ll>& nums, int m, ll x){
    ll current_sum=0;
    //The default partition is 1
    int count=1;
    for(ll num : nums){
        if(current_sum+num>x){
            count++;
            current_sum=num;
        }
        else{
            current_sum+=num;
        }
    }
    return count<=m;
}
int main(){
    vector<ll> nums={2,2,3,4,5,1};
    int m=3;
    ll Lower_bound=0;
    ll Upper_bound=0;
    for(ll num : nums){
        if(num>Lower_bound){
            Lower_bound=num;
        }
        Upper_bound+=num;
    }
    ll ans=Upper_bound;
    //use binary search here
    while(Lower_bound<=Upper_bound){
        ll Mid=Lower_bound+(Upper_bound-Lower_bound)/2;
        if(check(nums,m,Mid)){
            //which means the upper_bound can be lower
            ans=Mid;
            Upper_bound=Mid-1;
        }
        else{
            Lower_bound=Mid+1;
        }
    }
    cout<<ans;
    return 0;
}