#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//1 2 4 8 9
//b how many groups, x the maximum capacity
bool check(const vector<int>& position,int b,int x){
    int count=1;
    int last_pos=position[0];
    for(int i=1;i<position.size();i++){
        if(position[i]-last_pos>=x){
            count++;
            last_pos=position[i];
        }
    }
    return count>=b;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> position(n);
    for(int i=0;i<n;i++){
        cin>>position[i];
    }
    sort(position.begin(),position.end());
    int lower_bound=1,higher_bound=position[n-1]-position[0];
    int ans=higher_bound;
    while(lower_bound<=higher_bound){
        int mid=lower_bound+(higher_bound-lower_bound)/2;
        if(check(position,m,mid)){
            ans=mid;
            lower_bound=mid+1;
        }
        else{
            higher_bound=mid-1;
        }
    }
    cout<<ans;
    return 0;
}