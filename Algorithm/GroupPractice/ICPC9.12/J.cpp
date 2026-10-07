#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int check(string str){
    if(str=="UnreasonableProblemArrangement") return 10;
    else{
        string a=str.substr(0,str.size()-1);
        char b=str.back();
        if(b>='A'&&b<='L'){
            if(a=="WrongProblem") return 100;
            if(a=="SameProblem") return 30;
            if(a=="UnreasonableLimitForProblem") return 5;
            if(a=="WeakTestsForProblem") return 3;
            if(a=="BadProblem") return 1;
            return 0;
        }
        else{
            return 0;
        }
    }
}
void solve(){
    int n,P;
    cin>>n>>P;
    int sum=0;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        sum+=check(str);
    }
    if(sum>P){
        cout<<"Joker\n";
    }
    else{
        cout<<"Judger\n";
    }
}
int main(){
    int T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}