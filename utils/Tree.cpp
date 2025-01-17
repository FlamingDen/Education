#include "Tree.h"

#include <iostream>
#include <queue>


TreeNode::TreeNode(): val(0), left(nullptr), right(nullptr){}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

void sh::showTree(TreeNode *root)
{
    if(root == nullptr)
        return;
    showTree(root->left);
    showTree(root->right);
    std::cout << root->val << ", ";
}

void sh::showTreeLevel(TreeNode *root)
{
    if (root == nullptr)
        return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();

        std::cout << temp->val << ", ";
        if(temp->left != nullptr)
            q.push(temp->left);
        if(temp->right != nullptr)
            q.push(temp->right);
    }
    std::cout << std::endl;
}


Node::Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

Node::Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

Node::Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
