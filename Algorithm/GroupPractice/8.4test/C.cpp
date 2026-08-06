#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e8;
void solve(){
    int n, m, k, s, t, limit;
    cin >> n >> m >> k >> s >> t >> limit;
    s--;t--;
    //graph: g[n]: (neighbor, w, c)
    vector<vector<tuple<int,ll,ll>>> g(n);
    for(int i=0;i<m;i++){
        int u,v;
        ll w,c;
        cin>>u>>v>>w>>c;
        u--;v--;
        g[u].push_back({v,w,c});
        g[v].push_back({u,w,c});
    }
    //dist: 最短距离
    vector<vector<ll>> dist(n,vector<ll>(k+1,INF));
    dist[s][0]=0;
    //小根堆: distance,node,used c
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    pq.emplace(0,s,0);
    while(!pq.empty()){
        auto [d,u,used]=pq.top();
        pq.pop();
        
        //懒惰删除
        if(d!=dist[u][used]) continue;
        
        for(auto& [v,w,c]:g[u]){
            //不用图腾
            if(d+w<dist[v][used]){
                dist[v][used]=d+w;
                pq.emplace(dist[v][used],v,used);
            }
            //用图腾
            if(c!=-1 && used<k && d+c<dist[v][used+1]){
                dist[v][used+1]=d+c;
                pq.emplace(dist[v][used+1],v,used+1);
            }
        }
    }
    ll ans=INF;
    for(int j=0;j<=k;j++){
        ans=min(ans,dist[t][j]);
    }
    if(ans==INF){
        cout<<"-1 NO"<<endl;
    }
    else{
        cout<<ans<<" "<<(ans<=limit?"YES":"NO")<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}