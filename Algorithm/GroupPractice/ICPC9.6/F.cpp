#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int m,n,count=0;
    cin>>n>>m;
    vector<int> nums(n+1);
    nums[0]=0;
    for(int i=1;i<=n;i++){
        int k,sum=0;
        for(int j=0;j<m;j++){
            cin>>k;
            sum+=k;
        }
        nums[i]=sum;
        if(nums[i-1]-nums[i]>0) count++;
    }
    cout<<count;
    return 0;
}