#pragma once

//-------------Sample------------------------//
//        10
//       /  \
//      5   -3
//     / \    \
//    3   2    11
//   / \   \
//  3  -2   1 
// TreeNode* root = new TreeNode(10,
//     new TreeNode(5,
//         new TreeNode(3,
//             new TreeNode(3),
//             new TreeNode(-2)),
//         new TreeNode(2,
//             nullptr,
//             new TreeNode(1))
//     ),
//     new TreeNode(-3,
//         nullptr, 
//         new TreeNode(11))
// );
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

namespace sh {
    void showTree(TreeNode* root);

    void showTreeLevel(TreeNode* root);
};


//==============================================================================
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node();
    Node(int _val);
    Node(int _val, Node* _left, Node* _right, Node* _next);
};