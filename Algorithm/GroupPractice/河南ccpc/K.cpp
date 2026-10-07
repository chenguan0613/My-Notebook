#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//0-left:(0,-1),1-right:(0,1),2-up:(-1,0),3-down:(1,0)
int X[]={0,0,-1,1};
int Y[]={-1,1,0,0};
void dfs(vector<vector<bool>>& visited, vector<vector<int>>& nums,int x,int y,int prev){
    if(x<0 || x>=nums.size() || y<0 || y>=nums[0].size()) return;
    if(visited[x][y]==true || nums[x][y]!=prev) return;
    visited[x][y]=true;
    dfs(visited,nums,x+X[0],y+Y[0],nums[x][y]);
    dfs(visited,nums,x+X[1],y+Y[1],nums[x][y]);
    dfs(visited,nums,x+X[2],y+Y[2],nums[x][y]);
    dfs(visited,nums,x+X[3],y+Y[3],nums[x][y]);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> nums(n,vector<int>(m));
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>nums[i][j];
        }
    }
    for(int i=0;i<m;i++){
        if(nums[0][i]==0) dfs(visited,nums,0,i,nums[0][i]);
        if(nums[n-1][i]==0) dfs(visited,nums,n-1,i,nums[n-1][i]);
    }
    for(int i=0;i<n;i++){
        if(nums[i][0]==0) dfs(visited,nums,i,0,nums[i][0]);
        if(nums[i][m-1]==0) dfs(visited,nums,i,m-1,nums[i][m-1]);
    }
    int count_1=0,count_0=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==false && nums[i][j]==0){
                dfs(visited,nums,i,j,nums[i][j]);
                count_0++;
            }
            if(visited[i][j]==false && nums[i][j]==1){
                dfs(visited,nums,i,j,nums[i][j]);
                count_1++;
            }
        }
    }
    if(count_1==1 && count_0==2){
        cout<<"This is eight.";
    }
    else{
        cout<<"I don't know what this number is.";
    }
    return 0;
}