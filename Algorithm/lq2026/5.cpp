#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//W'=W/C
//所以就转换成1,2,...,n的数列,去找最小的前缀和刚好等于W'
//一种情况是前缀和始终小于W',那就是-1
//一种情况是前缀和刚好等于W'那就是刚好只读一次
//一种情况是1,...k的和大于W'了，(1+2+...+k-1)<W'<(1+2+...+k)
//d=(k+1)*k/2-W'
//W'=(k+1)*k/2-d>k(k-1)/2
//k^2+k-2*d>k^2-k
//k>d
//所以d其实是1.....k中的某个数
//意思就是说把它剔除掉,去[1,d-1]和[d+1,k]两次就好
//当d为2的时候还是1词
//如果W为奇数,也是算不出来结果的，取-1

//10
//2 4 6 8
//d=2

//9
//2 4 6 8
//d=3
ll T,N,C,W;
int main(){
    cin>>T;
    vector<int> res;
    while(T--){
        cin>>N>>C>>W;
        ll sum=C*(1+N)*N/2;
        if(sum<W || W%C!=0){
            res.push_back(-1);
            continue;
        }
        if(W==0){
            res.push_back(0);
            continue;
        }
        ll w=W/C;
        ll 
    }
    for(auto num:res){
        cout<<num<<endl;
    }
    return 0;
}