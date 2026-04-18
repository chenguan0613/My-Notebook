#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int C1,C2,N;
ll C3,A_min=1e9,B_min=1e9;
vector<ll> A,B;
bool check(int mid){
    
}
int main(){
    cin>>N>>C1>>C2>>C3;
    A.resize(N);
    B.resize(N);
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
    }
    int lower_bound=0,upper_bound=N;
    int ans=0;
    while(lower_bound<=upper_bound){
        int mid=lower_bound+(upper_bound-lower_bound)/2;
        if(check(mid)){
            lower_bound=mid+1;
            ans=lower_bound;
        }
        else{
            upper_bound=mid-1;
        }
    }
    cout<<ans;
    return 0;
}