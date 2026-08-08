#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
    char v;
    Node* left;
    Node* right;
};
void postorder(Node* start){
    if(start==nullptr) return;
    postorder(start->left);
    postorder(start->right);
    cout<<start->v;
}
vector<int> N={1,2,4,8,16,32,64,128,256,512,1024};
int main(){
    int n; cin>>n;
    int len=N[n];
    Node* m;
    string str;
    cin>>str;
    queue<Node*> q;
    for(char c : str){
        m = new Node;
        if(c=='0') m->v='B';
        else m->v='I';
        m->left=nullptr;
        m->right=nullptr;
        q.push(m);
    }
    while(q.size()!=1){
        Node* node1=q.front(); q.pop();
        Node *node2=q.front(); q.pop();
        m=new Node;
        if(node1->v=='B' && node2->v=='B') m->v='B';
        else if(node1->v=='I' && node2->v=='I')m->v='I';
        else m->v='F';
        m->left=node1;
        m->right=node2;
        q.push(m);
    }
    postorder(q.front());
    return 0;
}