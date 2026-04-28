#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; cin>>n;
    vector<ll> res;
    ll L,V,T;
    while(n--){
        cin>>L>>V>>T;
        ll pa=V*T,pb=L-V*T,mid;
        if(pa<pb){
            mid=pa+(pb-pa)/2;
        }
        else{
            mid=pb+(pa-pb)/2;
        }
        if(L%2==1) res.push_back(abs(mid-pa)+1);
        else res.push_back(abs(mid-pa));
    }
    for(auto num : res){
        cout<<num<<endl;
    }
    return 0;
}