#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
struct Edge{
    int to;
    ll weight;
};
//n cities, m roads, b your life
int n,m;
ll b;
vector<ll> fee;
vector<vector<Edge>> adj;
bool check(ll max_fee){
    if(fee[0]>max_fee || fee[n-1]>max_fee) return false;
    vector<ll> dist(n,INF);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    dist[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        auto [current_dist,u]=pq.top();
        pq.pop();
        if(current_dist>dist[u]) continue;
        for(auto& edge : adj[u]){
            int v=edge.to;
            ll weight=edge.weight;
            if(fee[v]<=max_fee && dist[u]+weight<dist[v]){
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v});
            }
        }
    }
    return dist[n-1]<=b;
}

int main(){
    cin>>n>>m>>b;
    fee.resize(n,0);
    ll max_fee=0;
    for(int i=0;i<n;i++){
        cin>>fee[i];
        max_fee=max(max_fee,fee[i]);
    }
    adj.resize(n,vector<Edge>());
    for(int i=0;i<m;i++){
        int from,to;
        ll cost;
        cin>>from>>to>>cost;
        adj[from-1].push_back({to-1,cost});
        adj[to-1].push_back({from-1,cost});
    }
    if(!check(max_fee)){
        cout<<"AFK";
        return 0;
    }
    ll lower_bound=max(fee[0],fee[n-1]);
    ll upper_bound=max_fee;
    ll ans=upper_bound;
    while(lower_bound<=upper_bound){
        ll mid_fee=lower_bound+(upper_bound-lower_bound)/2;
        if(check(mid_fee)){
            ans=mid_fee;
            upper_bound=mid_fee-1;
        }
        else{
            lower_bound=mid_fee+1;
        }
    }
    cout<<ans;
    return 0;
}