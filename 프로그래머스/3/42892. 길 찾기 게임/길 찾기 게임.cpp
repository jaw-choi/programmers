#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 노드 구조체 정의
struct Node {
    int x, y, index;
    Node* left;
    Node* right;

    Node(int x, int y, int index) : x(x), y(y), index(index), left(nullptr), right(nullptr) {}
};

// 트리 생성 함수
void insertNode(Node* parent, Node* child) {
    if (child->x < parent->x) {
        // 왼쪽 서브트리
        if (parent->left == nullptr)
            parent->left = child;
        else
            insertNode(parent->left, child);
    } else {
        // 오른쪽 서브트리
        if (parent->right == nullptr)
            parent->right = child;
        else
            insertNode(parent->right, child);
    }
}

// 전위 순회
void preorder(Node* node, vector<int>& result) {
    if (!node) return;
    result.push_back(node->index); // 현재 노드 방문
    preorder(node->left, result);
    preorder(node->right, result);
}

// 후위 순회
void postorder(Node* node, vector<int>& result) {
    if (!node) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->index); // 현재 노드 방문
}

// 솔루션 함수
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node*> nodes;

    // 노드 정보 초기화
    for (int i = 0; i < nodeinfo.size(); ++i) {
        nodes.push_back(new Node(nodeinfo[i][0], nodeinfo[i][1], i + 1));
    }

    // y 내림차순, x 오름차순 정렬
    sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
        if (a->y == b->y) return a->x < b->x;
        return a->y > b->y;
    });

    // 트리 구성
    Node* root = nodes[0];
    for (int i = 1; i < nodes.size(); ++i) {
        insertNode(root, nodes[i]);
    }

    // 순회 결과 생성
    vector<int> preorderResult;
    vector<int> postorderResult;

    preorder(root, preorderResult);
    postorder(root, postorderResult);

    return {preorderResult, postorderResult};
}

