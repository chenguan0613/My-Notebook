#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//1234567890321
string fun(ll x){
    string s="";
    while(x>0){
        ll reminder=x%9+1;
        s+=to_string(reminder);
        x/=9;
    }
    s=string(s.rbegin(),s.rend());
    return s;
}
int main(){
    cout<<fun(1234567890321);
    //5441675366887
    return 0;
}