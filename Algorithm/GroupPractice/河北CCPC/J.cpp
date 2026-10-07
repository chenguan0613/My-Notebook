#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,ans=-1,node=0; cin>>N>>M;
    for(ll i=0;i<N;i++){
        ll A,B,val; cin>>A>>B;
        if(A*12<=B){
            val=M/A;
            if(val>ans){
                ans=val;
                node=i+1;
            }
        }
        else{
            val=(M/B)*12+(M%B)/A;
            if(val>ans){
                ans=val;
                node=i+1;
            }
        }
    }
    printf("%lld %lld",ans,node);
    return 0;
}