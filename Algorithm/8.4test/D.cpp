#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cmpstr(string& a, string& b){
    if(a.length()>b.length()) return 0;
    int m=0,count=0;
    //aa,  bab
    while(m<b.length()){
        if(m+a.length()>b.length()) break;
        bool check=true;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[m+i]){
                check=false;
                break;
            }
        }
        if(check) count++;
        m++;
    }
    return count;
}
void solve(){
    int p,q;
    cin>>p>>q;
    vector<string> words(p);
    vector<string> sentences(q);
    vector<int> ans;
    for(int i=0;i<p;i++) cin>>words[i];
    for(int i=0;i<q;i++) cin>>sentences[i];
    for(auto word : words){
        int count=0;
        for(auto sentence  : sentences){
            count+=cmpstr(word,sentence);
        }
        ans.push_back(count);
    }
    for(int i=0;i<p;i++){
        cout<<ans[i];
        if(i!=p-1) cout<<" ";
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}