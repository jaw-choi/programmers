#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Node{
    int x;
    int y;
    int val;
    Node* left;
    Node* right;
    Node(int x_, int y_, int val_) : x(x_), y(y_), val(val_), left(nullptr), right(nullptr) {}
};
bool cmp(Node* a, Node* b)
{
    if(a->y == b->y){
        return a->x < b->x;
    }
    return a->y > b->y;
}
void insert(Node* root, Node* node)
{
    if(root->x > node->x){
        if(root->left==nullptr)
            root->left = node;
        else
            insert(root->left,node);
    }
    else{
        if(root->right==nullptr)
            root->right = node;
        else
            insert(root->right,node);
    }
}
void preorder(Node* node,vector<int>& v)
{
    if(node==nullptr)
        return;
    v.push_back(node->val);
    preorder(node->left,v);
    preorder(node->right,v);
}
void postorder(Node* node,vector<int>& v)
{
    if(node==nullptr)
        return;
    postorder(node->left,v);
    postorder(node->right,v);
    v.push_back(node->val);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node*> tree;
    for(int i=0;i<nodeinfo.size();i++)
    {
        tree.push_back(new Node(nodeinfo[i][0],nodeinfo[i][1],i+1));
    }
    sort(tree.begin(),tree.end(),cmp);
    Node* root = tree[0];
    for(int i = 1;i<tree.size();i++)
    {
        insert(root,tree[i]);
    }
    vector<int> pre;
    vector<int> post;
    preorder(root,pre);
    postorder(root,post);
    for(auto t : tree)
        delete t;
    return {pre,post};
}