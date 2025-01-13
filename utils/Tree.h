#pragma once

template<typename T>
struct TreeNode{
    T val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode() : val(0){}
    TreeNode(int v) : val(v){}
    TreeNode(int v, TreeNode* l, TreeNode* r) :  val(v), left(l), right(r){}
};

namespace sh {
    template<typename T>
    void showTree(TreeNode<T>* root){
        if(root == nullptr)
            return;
        showTree(root->left);
        showTree(root->right);
        std::cout << root->val << ", ";
    }

    // TreeNode
    // TreeNode<int>* root = new TreeNode<int>(4, new TreeNode<int>(5, new TreeNode<int>(12), new TreeNode<int>(11)), new TreeNode<int>(10, new TreeNode<int>(22), new TreeNode<int>(44)));
    // sh::showTree(root);
    // std::cout << std::endl;
    // sh::showTreeLevel(root);
    template<typename T>
    void showTreeLevel(TreeNode<T>* root){
        if (root == nullptr)
            return;

        std::queue<TreeNode<T>*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode<T>* temp = q.front();
            q.pop();

            std::cout << temp->val << ", ";
            if(temp->left != nullptr)
                q.push(temp->left);
            if(temp->rigth != nullptr)
                q.push(temp->right);
        }
        std::cout << std::endl;
    }
};