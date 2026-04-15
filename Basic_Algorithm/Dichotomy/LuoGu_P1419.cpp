#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//假设我们找到的这个mid是段落最优平均值,我们要去看有没有更大的
//也就是(a1+a2+...+an)/n>mid,n=[S,T]
//变形一下a1+a2+...+an>n*mid
//(a1-mid)+(a2-mid)+...+(an-mid)>0
//然后我们要用前缀和去处理,所以在算前缀和的时候,就把mid剪掉
//滑动窗口也要用单调栈优化一下：
//我们假设窗口的右端点为j,所以这个j扫过的范围肯定是从S到n的
//k是窗口的左端点,也就是j-S,而左端点容忍的极限是j-T
//然后我们用单调栈来实现(也就是保持栈的单调,来了一个特别小的就把里面的大于它的尽可能pop出去)
//这也就意味着单调栈的栈顶始终代表着窗口里最小的那个数,而我们要算的就是：
//presum[j]-presum[dq.front()]
int n,S,T;
bool check(double mid,const vector<double>& nums){
    vector<double> presum(n+1,0);
    for(int i=1;i<=n;i++){
        presum[i]=(nums[i-1]-mid)+presum[i-1];
    }
    deque<int> dq;
    for(int j=S;j<n;j++){
        int k=j-S;
        while(!dq.empty() && presum[dq.back()]>=presum[k]){
            dq.pop_back();
        }
        dq.push_back(k);
        while(!dq.empty() && dq.front()<j-T){
            dq.pop_front();
        }
        if(!dq.empty() && presum[j]-presum[dq.front()]>=0){
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>S>>T;
    vector<double> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    double lower_bound=-10000.0,upper_bound=10000.0;
    while(upper_bound-lower_bound>1e-5){
        double mid=lower_bound+(upper_bound-lower_bound)/2.0;
        if(check(mid,nums)){
            lower_bound=mid;
        }
        else{
            upper_bound=mid;
        }
    }
    //keep 3 digits
    cout<<fixed<<setprecision(3)<<lower_bound;
    return 0;
}