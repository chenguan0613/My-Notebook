#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int find(int x,vector<int>& nums){
    if(nums[x]==x) return x;
    return nums[x]=find(nums[x],nums);
}

bool merge(int x,int y,vector<int>& nums){
    int fx=find(x,nums);
    int fy=find(y,nums);
    if(fx!=fy){
        nums[fx]=fy;
        return true;
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,q;
        cin>>n>>m>>q;
        vector<int> nums(n+1);
        vector<pair<int,int>> edges(m+1);
        vector<int> queries(q+1);
        vector<int> first_delete(m+1,0);
        int components=n;
        for(int i=1;i<=n;i++){
            nums[i]=i;
        }
        for(int i=1;i<=m;i++){
            cin>>edges[i].first>>edges[i].second;
        }

        for(int i=1;i<=q;i++){
            cin>>queries[i];
            if(first_delete[queries[i]]==0){
                first_delete[queries[i]]=i;
            }
        }

        for(int i=1;i<=m;i++){
            if(first_delete[i]==0){
                if(merge(edges[i].first,edges[i].second,nums)){
                    components--;
                }
            }
        }
        
        vector<int> ans(q+1);
        vector<bool> connected(q+1);
        for(int i=q;i>=1;i--){
            ans[i]=components;
            connected[i]=(find(1,nums)==find(n,nums));
            int index=queries[i];
            if(first_delete[index]==i){
                int x=edges[index].first;
                int y=edges[index].second;
                if(merge(x,y,nums)){
                    components--;
                }
            }
        }
        for(int i=1;i<=q;i++){
            if(connected[i]){
                cout<<"Yes ";
            }
            else{
                cout<<"No ";
            }
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}