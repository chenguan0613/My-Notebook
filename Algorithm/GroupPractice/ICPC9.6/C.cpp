#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> in_degree(n+1,0);
    while(m--){
        int l,r;
        cin>>l>>r;
        vector<int> q(r-l+1);
        for(int i=0;i<r-l+1;i++){
            cin>>q[i];
        }
        for(int i=0;i<r-l;i++){
            int u=q[i+1];
            int v=q[i];
            adj[u].push_back(v);
            in_degree[v]++;
        }
    }
    priority_queue<int> pq;
    for(int i=1;i<=n;i++){
        if(in_degree[i]==0){
            pq.push(i);
        }
    }
    vector<int> ans(n+1);
    int current_assigned=n;
    int count=0;
    while(!pq.empty()){
        int u=pq.top();
        pq.pop();
        ans[u]=current_assigned--;
        count++;
        for(int v:adj[u]){
            in_degree[v]--;
            if(in_degree[v]==0){
                pq.push(v);
            }
        }
    }
    if(count==n){
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<(i==n?"":" ");
        }
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
int main(){
    int T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}