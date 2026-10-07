#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,string> mp;
string cmp(string a, string b){
    string ans="";
    for(int i=0;i<min(a.length(),b.length());i++){
        if(a[i]==b[i]) ans+=a[i];
        else break;
    }
    return ans;
}

string common(vector<string>& strs, int j){
    if(j==1){
        if(mp.find(1)==mp.end()) mp[1]=strs[0];
        return mp[1];
    }
    if(j==2){
        if(mp.find(2)==mp.end()) mp[2]=cmp(strs[0],strs[1]);
        return mp[2];
    }
    if(mp.find(j)==mp.end()){
        mp[j]=cmp(common(strs,j-1),strs[j-1]);
    }
    return mp[j];
}

int XOR(int a, int b){
    return (a | b) & ~(a & b);
}

int main(){
    int n; cin>>n;
    vector<string> strs(n);
    vector<int> presum(n+1);
    presum[0]=0;
    for(int i=0;i<n;i++){
        cin>>strs[i];
    }
    for(int j=1;j<=n;j++){
        string LCP=common(strs,j);
        int lcp=LCP.length();
        presum[j]=presum[j-1]+XOR(lcp,j);
        cout<<presum[j]<<endl;
    }
    return 0;
}