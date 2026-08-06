#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//上下左右
int dx1[] = {-1, 1, 0, 0};
int dy1[] = {0, 0, -1, 1};
//3*3,除了中心点
int dx2[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy2[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//5*5,除了中心点
int dx3[] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
int dy3[] = {-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2};
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,s,q;
        cin>>n>>m>>s>>q;
        vector<vector<bool>> fram(n+1,vector<bool>(m+1,false));
        vector<vector<int>> water(n + 1, vector<int>(m + 1, 0));
        vector<int> ans;
        for(int i=1;i<=n;i++){
            string row;
            cin>>row;
            for(int j=1;j<=m;j++){
                if(row[j-1]=='1'){
                    fram[i][j]=true;
                }
            }
        }
        for(int i=0;i<s;i++){
            int x,y,type;
            cin>>x>>y>>type;
            if(type==1){
                for(int j=0;j<4;j++){
                    int nx=x+dx1[j];
                    int ny=y+dy1[j];
                    if(nx>=1 && nx<=n && ny>=1 && ny<=m){
                        water[nx][ny]++;
                    }
                }
            }
            else if(type==2){
                for(int j=0;j<8;j++){
                    int nx=x+dx2[j];
                    int ny=y+dy2[j];
                    if(nx>=1 && nx<=n && ny>=1 && ny<=m){
                        water[nx][ny]++;
                    }
                }
            }
            else if(type==3){
                for(int j=0;j<24;j++){
                    int nx=x+dx3[j];
                    int ny=y+dy3[j];
                    if(nx>=1 && nx<=n && ny>=1 && ny<=m){
                        water[nx][ny]++;
                    }
                }
            }
        }

        int sum=0,count_one=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(fram[i][j]){
                    if(water[i][j]>=1) sum++;
                    if(water[i][j]==1) count_one++;
                }
            }
        }
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            ans.push_back(water[x][y]);
        }
        cout << sum << " " << count_one << endl;
        for(int i=0;i<q;i++){
            cout << ans[i] << endl;
        }
    }
    return 0;
}