# 1. 基础数据结构&算法

## 1.1 基础数据结构

### 1.1.1 链表

可以用C++的STL list, 也可以手搓链表(动态&静态)，下面我会写一下基本的框架以及一道例题(洛谷P1996)。题目如下：

***P1996 约瑟夫问题***

***n 个人围成一圈，从第一个人开始报数,数到 m 的人出列，再由下一个人重新从 1 开始报数，数到 m 的人再出圈，依次类推，直到所有的人都出圈，请输出依次出圈人的编号。***

#### **动态链表**

使用结构体去表示一个节点，然后用指针把他们连接起来就好(这里使用单向链表)。

```cpp
#include <bits/stdc++.h>
using namespace std;
struct node{
    int value;
    node* next;
};
int main(){
    // int n,m; cin>>n>>m;
    node *head, *cur,*p;
    head=new node;
    head->value=1;
    head->next=NULL;
    cur=head;
    //创建循环链表
    for(int i=2;i<=n;i++){
        p=new node;
        p->value=i;
        p->next=NULL;
        cur->next=p;
        cur=p;
    }
    cur->next=head;
    
    //题目的具体解答
    cur=head;
    node *prev; prev=head;
    while(n>1){
        for(int i=1;i<m;i++){
            prev=cur;
            cur=cur->next;
        }
        //cout<<cur->value;
        prev->next=cur->next;
        delete cur;
        cur=prev->next;
        n--;
    }
    //cout<<cur->value;
    delete cur;

    return 0;
}
```

#### **静态链表**

***结构体数组实现单向链表***

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N=1000;
struct node{
    int value,next;
}nodes[N];
int main(){
    //int n,m; cin>>n>>m;
    nodes[0].next=1;
    for(int i=1;i<=n;i++){
        nodes[i].value=i;
        nodes[i].next=i+1;
    }
    nodes[n].next=1;
    //题目的具体解答
    int cur=1,prev=1;
    while(n>1){
        for(int i=0;i<m-1;i++){
            prev=cur;
            cir=nodes[cur].next;
        }
        //cout<<nodes[cur].value;
        nodes[prev].next=nodes[cur].next;
        cur=nodes[prev].next;
        n--;
    }
    //cout<<nodes[cur].value;
    return 0;
}
```

***结构体数组实现双向链表***

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N=1000;
struct node{
    int value,next,prev;
}nodes[N];
int main(){
    //int n,m; cin>>n>>m;
    nodes[0].next=1;
    for(int i=1;i<=n;i++){
        nodes[i].value=i;
        nodes[i].next=i+1;
        nodes[i].prev=i-1;
    }
    nodes[n].next=1;
    nodes[1].prev=n;
    //题目的具体解答
    int cur=1;
    while(n>1){
        for(int i=0;i<m-1;i++){
            cur=nodes[cur].next;
        }
        //cout<<nodes[cur].value;
        nodes[nodes[cur].prev].next=nodes[cur].next;
        nodes[nodes[cur].next].prev=nodes[cur].prev;
        cur=nodes[cur].next;
        n--;
    }
    //cout<<nodes[cur].value;
    return 0;
}
```

***一维数组实现单向链表***

```cpp
#include <bits/stdc++.h>
using namespace std;
int nodes[1000];
int main(){
    //int n,m; cin>>n>>m;
    for(int i=1;i<n;i++){
        nodes[i]=i+1;
    }
    nodes[n]=1;
    int cur=1,prev=1;
    while(n>1){
        for(int i=0;i<m;i++){
            prev=cur;
            cur=nodes[cur];
        }
        nodes[prev]=nodes[cur];
        cur=nodes[cur];
        n--;
    }
    cout<<cur;
    return 0;
}
```

#### **STL链表**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    //int n,m;cin>>n>>m;
    list<int> nodes;
    for(int i=1;i<=n;i++){
        nodes.push_back(i);
    }
    auto it=nodes.begin();
    while(nodes.size()>1){
        for(int i=0;i<m-1;i++){
            it++;
            if(it==nodes.end()) it=nodes.begin();
        }
        // cout<<*it;
        auto next=++it;
        if(next==nodes.end()) next=nodes.begin();
        nodes.erase(--it);
        it=next;
    }
    //cout<<*it;
    return 0;
}
```

### 1.1.2 队列

#### STL queue

```cpp
queue<Type> q; //定义
q.push(item);  //进队
q.pop();       //出队
q.front();     //return 队头
q.back();      //return 队尾
q.size();      //size
q.empty();     //empty?
```

#### 双端队列

```cpp
deque<Type> dq;
dq[i];
dq.front();
dq.back();
dq.pop_front();
dq.pop_back();
dq.push_front(e);
dq.push_back(e);
```

#### 单调队列/滑动窗口

* 单调队列其实就是你一直在维持一个有序的队列,你可以很方便地知道队列里的最大值和最小值。
* 滑动窗口其实就是一个不断进队出队的过程(维持一个窗口)

这里给一个例题

***P1886 【模板】单调队列 / 滑动窗口***

有一个长为 $n$ 的序列 $a$，以及一个大小为 $k$ 的窗口。现在这个窗口从左边开始向右滑动，每次滑动一个单位，求出每次滑动后窗口中的最小值和最大值。

例如，对于序列 $[1,3,-1,-3,5,3,6,7]$ 以及 $k = 3$，有如下过程：

| 窗口位置 | 最小值 | 最大值 |
| :--- | :---: | :---: |
| `[1   3  -1] -3   5   3   6   7` | -1 | 3 |
| `1  [3  -1  -3]  5   3   6   7` | -3 | 3 |
| `1   3 [-1  -3   5]  3   6   7` | -3 | 5 |
| `1   3  -1 [-3   5   3]  6   7` | -3 | 5 |
| `1   3  -1  -3  [5   3   6]  7` | 3 | 6 |
| `1   3  -1  -3   5  [3   6   7]` | 3 | 7 |

***解答:***

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    deque<int> q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        while(!q.empty() && a[q.back()]>a[i]) q.pop_back();
        q.push_back(i);
        if(i>=k-1){
            while(!q.empty() && i-q.front()+1>k) q.pop_front();
            cout<<a[q.front()]<<" ";
        }
    }
    cout<<endl;
    while(!q.empty()) q.pop_front();
    for(int i=0;i<n;i++){
        while(!q.empty() && a[q.back()]<a[i]) q.pop_back();
        q.push_back(i);
        if(i>=k){
            while(!q.empty() && i-q.front()+1>k) q.pop_front();
            cout<<a[q.front()]<<" ";
        }
    }
    return 0;
}
```

### 1.1.3 栈

```cpp
stack<Type> s;
s.push(item);
s.top();
s.pop();
s.size();
s.empty();
```

同理我们也有单调栈，和单调队列一样我们需要维持队列的有序

***P2947 [USACO09MAR] Look Up S***

***约翰的 $N(1\le N\le10^5)$ 头奶牛站成一排，奶牛 $i$ 的身高是 $H_i(1\le H_i\le10^6)$。现在，每只奶牛都在向右看。对于奶牛 $i$，如果奶牛 $j$ 满足 $i<j$ 且 $H_i<H_j$，我们可以说奶牛 $i$ 可以仰望奶牛 $j$。 求出每只奶牛离她最近的仰望对象。***

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> cows(n+1),res(n+1);
    stack<int> st;
    for(int i=1;i<=n;i++) cin>>cows[i];
    for(int i=n;i>=1;i--){
        while(!st.empty() && cows[i]>cows[st.top()]) st.pop();
        if(!st.empty()) ans[i]=0;
        else{
            ans[i]=st.top();
            st.push(i);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
```

### 1.1.4 二叉树&哈夫曼树

### 1.1.5 堆

## 1.2 基本算法

### 1.2.1 尺取法&二分法&三分法

### 1.2.2 倍增法&ST算法

### 1.2.3 前缀和&差分

### 1.2.4离散化

### 1.2.5 分治法

### 1.2.6 贪心法&拟阵

### 1.2.7 排序&排列
