#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//确认了第一行和第一列,剩下的就可以自动填好了
int main(){
    ll ans=1;
    for(int i=1;i<=2047+2047-1;i++){
        ans=(ans*2)%998244353;
    }
    cout<<ans;
    return 0;
}