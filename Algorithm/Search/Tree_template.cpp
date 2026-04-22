#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct TreeNode{
    int val;
    int left;
    int right;
    TreeNode(int val): val(val),left(-1),right(-1) {}
};
vector<TreeNode> tree;
int createNode(int& val){
    tree.push_back(TreeNode(val));
    return tree.size()-1;
}
void insertNode(int root,int val){
    if(root==-1) return;
    if(val<tree[root].val){
        if(tree[root].left==-1) tree[root].left=createNode(val);
        else insertNode(tree[root].left,val);
    }
    else{
        if(tree[root].right==-1) tree[root].right=createNode(val);
        else insertNode(tree[root].right,val);
    }
}

struct MultiNode{
    int val;
    vector<int> children;
    MultiNode(int val): val(val) {}
};
vector<MultiNode> multiTree;
int createMultiNode(int& val){
    multiTree.push_back(MultiNode(val));
    return multiTree.size()-1;
}
void insertMultiNode(int parent,int val){
    if(parent==-1) return;
    int child=createMultiNode(val);
    multiTree[parent].children.push_back(child);
}

// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int v) : val(v), left(NULL), right(NULL) {}
// };
// vector<TreeNode*> tree;
// TreeNode* createNode(int v){
//     TreeNode* node=new TreeNode(v);
//     tree.push_back(node);
//     return node;
// }
// void insertNode(TreeNode* root,int v){
//     if(root==NULL) return;
//     if(v<root->val){
//         if(root->left==NULL) root->left=createNode(v);
//         else insertNode(root->left,v);
//     }
//     else{
//         if(root->right==NULL) root->right=createNode(v);
//         else insertNode(root->right,v);
//     }
// }

// struct MultiNode{
//     int val;
//     vector<MultiNode*> children;
//     MultiNode(int v) : val(v) {}
// };
// vector<MultiNode*> multiTree;
// MultiNode* createMultiNode(int v){
//     MultiNode* node=new MultiNode(v);
//     multiTree.push_back(node);
//     return node;
// }
// void insertMultiNode(MultiNode* parent,int v){
//     if(parent==NULL) return;
//     MultiNode* child=createMultiNode(v);
//     parent->children.push_back(child);
// }

int main(){

    return 0;
}