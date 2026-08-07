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
        p->data=i;
        p->next=NULL;
        cur->next=p;
        cur=p;
    }
    cur->next=head;
    
    //题目的具体解答
    cur=head;
    node *prev; prev=head;
    while(n>1){
        for(int i=0;i<m;i++){
            prev=cur;
            cur=cur->next;
        }
        //cout<<cur->data;
        prev->next=cur->next;
        delete cur;
        cur=prev->next
        n--;
    }
    //cout<<cur->data
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
    for(n>1){
        for(int i=0;i<m;i++){
            prev=cur;
            cur++;
        }
        //cout<<nodes[cur].value;
        nodes[prev].next=nodes[cur].next;
        nodes[cur]=nodes[prev].next;
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
    for(n>1){
        for(int i=0;i<m;i++){
            cur++;
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
    //int n,m;cin>>n,m;
    list<int> nodes;
    for(int i=1;i<=n;i++){
        nodes.push_back(i);
    }
    auto it=nods.begin();
    while(nodes.size()>1){
        for(int i=0;i<m;i++){
            it++;
            if(it==nodes.end()) it=nodes.begin();
        }
        // cout<<*it;
        auto next=++it;
        if(next==node.end()) next=node.begin();
        node.erase(--it);
        it=next;
    }
    //cout<<*it;
    return 0;
}
```

### 1.1.2 队列

### 1.1.3 栈

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
