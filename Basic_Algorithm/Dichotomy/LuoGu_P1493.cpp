#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//BIT 树状数组
struct Pear{
    ll A,B,S;
};
struct BIT{
    int n;
    vector<int> tree;
    BIT(int n): n(n),tree(n+1,0) {}
    int lowbit(int x){
        return x&-x;
    }
    void add(int i, int delta){
        for(;i<=n;i+=lowbit(i)){
            tree[i]+=delta;
        }
    }
    //from rank 1 to rank i
    int query(int i){
        int sum=0;
        for(;i>0;i-=lowbit(i)){
            sum+=tree[i];
        }
        return sum;
    }
};
vector<ll> uniq_S;
int get_rank(ll val) {
    auto pos = lower_bound(uniq_S.begin(), uniq_S.end(), val);
    int index = pos - uniq_S.begin();
    return index + 1;
}
int get_query_rank(ll limit) {
    auto pos = upper_bound(uniq_S.begin(), uniq_S.end(), limit);
    int index = pos - uniq_S.begin();
    return index;
}
bool cmp(const Pear& p1, const Pear& p2) {
    if (p1.A != p2.A) {
        return p1.A < p2.A;
    } else {
        return p1.B < p2.B;
    }
}
int main(){
    int N;
    ll C1,C2,C3;
    cin>>N>>C1>>C2>>C3;
    vector<Pear> pears(N);
    
    for(int i=0;i<N;i++){
        cin>>pears[i].A>>pears[i].B;
        pears[i].S=C1*pears[i].A+C2*pears[i].B;
        uniq_S.push_back(pears[i].S);
    }
    sort(uniq_S.begin(),uniq_S.end());
    uniq_S.erase(unique(uniq_S.begin(),uniq_S.end()),uniq_S.end());
    sort(pears.begin(), pears.end(),cmp);
    int max_ans=0;
    for(int i=0;i<N;i++){
        if (i>0 && pears[i].A == pears[i-1].A) continue;
        ll A0=pears[i].A;
        vector<Pear> group(pears.begin()+i,pears.end());
        sort(group.begin(),group.end(),[](const Pear& p1, const Pear& p2){
            if(p1.B!=p2.B) return p1.B<p2.B;
            return p1.A<p1.B;
        });
        BIT bit(uniq_S.size());
        for (const auto& p : group){
            bit.add(get_rank(p.S), 1);
        }
        for (const auto& p : group){
            ll B0 = p.B;
            ll limit = C3 + C1 * A0 + C2 * B0;
            int valid_count = bit.query(get_query_rank(limit));
            max_ans = max(max_ans, valid_count);
            bit.add(get_rank(p.S), -1);
        }
    }
    cout<<max_ans;
    return 0;
}