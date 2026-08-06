#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//eat: hp=min(max_length,dp[i]+food_i)
//monster: hp=hp-min(cap_i,max(0,power_i-safe_i))
//梯子: dp[i+1]=max(dp[i+1],hp)
//竖井: dp[i+drop_i]=max(dp[i+drop_i],hp-drop_i*c)
struct floor{
    ll ladder, hole, drop, food, monster, power, safe, cap;
};
int main(){
    int t;
    cin>>t;
    vector<string> ans;
    while(t--){
        ll n,h,c,max_length;
        cin>>n>>h>>c>>max_length;
        vector<ll> dp(n+1,-1);
        dp[1]=h;
        for (ll i=1;i<=n;i++){
            struct floor cur;
            cin >> cur.ladder >> cur.hole >> cur.drop >> cur.food >> cur.monster >> cur.power >> cur.safe >> cur.cap;
            if (dp[i] <= 0) continue;
            //eat
            ll hp=min(max_length,dp[i]+cur.food);
            //monster
            if(cur.monster==1){
                hp=hp-min(cur.cap,max(0LL,cur.power-cur.safe));
            }
            //判断存活
            if(hp<=0){
                dp[i]=-1;
                continue;
            }
            //已经到底
            if(i==n){
                dp[i]=hp;
                continue;
            }
            //走梯子
            if(cur.ladder==1){
                dp[i+1]=max(dp[i+1],hp);
            }
            //掉竖井
            if(cur.hole==1){
                ll dist=min(n,i+cur.drop)-i;
                if (hp-dist*c>0){
                    dp[i+dist]=max(dp[i+dist],hp-dist*c);
                }
            }
        }
        if (dp[n] > 0){
            ans.push_back("YES");
        }
        else{
            ans.push_back("NO");
        }
    }
    for(auto i:ans){
        cout<<i<<endl;
    }
    return 0;
}