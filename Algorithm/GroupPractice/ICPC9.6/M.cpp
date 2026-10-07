#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<string, int> m;
void input(int n){
    while(n--){
        string str;
        cin>>str;
        m[str]=0;
    }
}
void check(string str){
    auto it=m.find(str);
    if(it==m.end()){
        cout<<"WRONG";
    }
    else if(it->second==0){
        it->second=1;
        cout<<"OK";
    }
    else if(it->second==1){
        cout<<"REPEAT";
    }
    cout<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    input(n);
    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        check(str);
    }
    return 0;
}