#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node{
    int x;
    int y;
    int idx;
    Node* left;
    Node* right;
    Node(int x_,int y_, int index) : x(x_), y(y_), idx(index), left(nullptr), right(nullptr){}   
};
bool cmp(Node* a, Node* b)
{
    if(a->y == b->y){
        return a->x < b->x;
    }   
    return a->y > b->y;
}

void postorder(Node* root, vector<int>& vec)
{
    if(!root)
        return;
    postorder(root->left,vec);
    postorder(root->right,vec);        
    vec.push_back(root->idx);
}

void preorder(Node* root, vector<int>& vec)
{
    if(!root)
        return;
    vec.push_back(root->idx);
    preorder(root->left,vec);
    preorder(root->right,vec);        
}
void insertNode(Node* parent, Node* child)
{
    if(parent->x > child->x){//left
        if(parent->left==nullptr)
            parent->left = child;
        else
            insertNode(parent->left,child);
    }
    else{//right
        if(parent->right==nullptr)
            parent->right = child;
        else
            insertNode(parent->right,child);        
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    vector<Node*> tree;
    for(int i=0;i<nodeinfo.size();i++)
    {
        tree.push_back(new Node(nodeinfo[i][0],nodeinfo[i][1],i+1));
    }
    
    sort(tree.begin(),tree.end(),cmp);

    Node* root = tree[0];
    for(int i=1;i<tree.size();i++)
        insertNode(root,tree[i]);    
    
    vector<int> pre;
    vector<int> post;
    preorder(root,pre);
    postorder(root,post);
    return {pre,post};
}