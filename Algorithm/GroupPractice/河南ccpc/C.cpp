#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    if(n>=m){
        cout<<k;
    }
    else{
        cout<<(k*m+n-1)/n;
    }
    return 0;
}