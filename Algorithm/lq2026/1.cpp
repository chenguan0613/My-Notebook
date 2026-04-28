#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string binary(ll x){
    string s="";
    while(x>0){
        int t=x%2;
        s+=to_string(t);
        x/=2;
    }
    s=string(s.rbegin(),s.rend());
    return s;
}
int main(){
    //111001100101101001000001111011011000111011010001010
    //1000000000000000000000000001111111111111111111111111
    // 11111111111111111111111110000000000000000000000000

    //26个1,25个0
    cout<<binary(2026202620262026)<<endl;
    cout<<binary(1125899873288192)<<endl;
    ll ans=0,ans2=0;
    for(ll i=25;i<=49;i++){
        ans+=pow(2,i);
    }
    for(ll i=0;i<=24;i++){
        ans2+=pow(2,i);
    }
    ans2=ans2+pow(2,51);
    cout<<ans<<endl<<ans2<<endl;
    return 0;
}