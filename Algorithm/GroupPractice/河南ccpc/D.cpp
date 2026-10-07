#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,X=0; cin>>n>>m;
    vector<ll> nums_1;
    vector<ll> nums_2;
    for(ll i=0;i<n;i++){
        string val;
        ll atk;
        cin>>val>>atk;
        if(val=="1"){
            nums_1.push_back(atk);
        }
        else if(val=="2"){
            nums_2.push_back(atk);
        }
        else{
            X=max(X,atk);
        }
    }
    sort(nums_1.begin(),nums_1.end(),greater<ll>());
    sort(nums_2.begin(),nums_2.end(),greater<ll>());
    ll i=0,j=0,ans=0;
    while(m>0){
        ll cur_1=(m>=1 && i<nums_1.size())?nums_1[i]:0;
        ll cur_2=(m>=2 && i<nums_2.size())?nums_2[j]:0;
        if(cur_1*2>cur_2 && cur_1>X){
            ans+=nums_1[i];
            m-=1;
            i++;
        }
        else if(cur_2>cur_1*2 && cur_2>X*2){
            ans+=nums_2[j];
            m-=2;
            j++;
        }
        else{
            ans+=m*X;
            m=0;
        }
    }
    cout<<ans;
    return 0;
}