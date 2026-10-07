# 1. 高级数据结构

## 1.1 并查集

先用一个例题来举例：
**问题描述：有 $n$ 个人一起吃饭，有些人互相认识。认识的人想坐在一起，而不想跟陌生人坐在一起。例如，A 认识 B，B 认识 C，那么 A、B、C 会坐在一张桌子上。给出认识的人，问需要多少张桌子？输入：第 1 行输入整数 $T$，表示有 $T$ 个测试。每个测试中，第 1 行输入整数 $N$ 和 $M$（$1 \leqslant N, M \leqslant 1000$，$N$ 为朋友人数，编号为 $1 \sim N$）。后面 $M$ 行中，每行输入两个整数 $A$ 和 $B$，表示 $A$ 和 $B$ 认识。两个测试之间空一行。输出：对每个测试，输出一个整数，表示需要多少张桌子。**

```cpp
#include <bits/stdc++.h>
using namespace std;
const N=1050;
int s[N];
void init_set(){
    for(int i=1;i<N;i++) s[i]=i;
}
int find_set(int x){
    if(x==s[x]) return x;
    else return find_set(s[x]);
}
void merge_set(int x,int y){
    int parent_x=find_set(x),parent_y=find_set(y);
    if(parent_x!=parent_y) s[x]=s[y];
}
void solve(){
    int n,m,x,y;
    cin>>n>>m;
    init_set();
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        merge_set(x,y);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]==i) ans++;
    }
    cout<<ans<<endl;
}
int main(){
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
```