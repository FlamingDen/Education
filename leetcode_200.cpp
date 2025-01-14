#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"



class Solution {
public:
    //--------------------------#101--------------------------------------------//
    // TreeNode<int>* root = new TreeNode<int>(1, new TreeNode<int>(2, new TreeNode<int>(4), new TreeNode<int>(5)), new TreeNode<int>(3, new TreeNode<int>(6), new TreeNode<int>(7)));
    // sh::print(solution.isSymmetric_101(root));
    bool isSymmetric_101(TreeNode<int>* root) {
        std::vector<int> vals;
        helper_101(root->left, vals, true);
        helper_101(root->right, vals, false);
        if(vals.size() % 2 == 1)
            return false;

        for(size_t i(0); i != vals.size() / 2; ++i){
            if(vals[i] != vals[i + vals.size() / 2])
                return false;
        }
        return true;
    }
    
    //--------------------------#102--------------------------------------------//
    // TreeNode<int>* root = new TreeNode<int>(1, new TreeNode<int>(2, new TreeNode<int>(4), new TreeNode<int>(5)), new TreeNode<int>(3, new TreeNode<int>(6), new TreeNode<int>(7)));
    // sh::showVecVec(solution.levelOrder_102(root));
    std::vector<std::vector<int>> levelOrder_102(TreeNode<int>* root) {
        std::vector<std::vector<int>> ans;
        LevelOrderHelper_102(root, ans);
        return ans;
    }
    
    //--------------------------#103--------------------------------------------//
    // TreeNode<int>* root = new TreeNode<int>(3, new TreeNode<int>(9), new TreeNode<int>(20, new TreeNode<int>(15), new TreeNode<int>(7)));
    // sh::showVecVec(solution.zigzagLevelOrder_103(root));
    std::vector<std::vector<int>> zigzagLevelOrder_103(TreeNode<int>* root) {
        std::vector<std::vector<int>> ans;
        zigzagLevelOrderHelper_103(root, ans);
        return ans;
    }

    //--------------------------#104--------------------------------------------//
    // TreeNode<int>* root = new TreeNode<int>(3, new TreeNode<int>(9), new TreeNode<int>(20, new TreeNode<int>(15), new TreeNode<int>(7)));
    // sh::print(solution.maxDepth(root));
    int maxDepth(TreeNode<int>* root) {
        if(root == nullptr){
            return 0;
        }
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }

    //--------------------------#111--------------------------------------------//
    int minDepth_111(TreeNode<int>* root) {
        return depth_111(root);
    }

    //--------------------------#108--------------------------------------------//
    TreeNode<int>* sortedArrayToBST(std::vector<int>& nums) {
        TreeNode<int>* root = new TreeNode<int>;
        help_108(nums, 0, nums.size() - 1, root);
        return root;
    }
    void help_108(std::vector<int>& nums, int l, int r, TreeNode<int>* curr){
        if(r - l > 3){
            int mid = (r - l) / 2;
            curr->val = nums[mid];

            curr->left = new TreeNode<int>;
            curr->right = new TreeNode<int>;
            help_108(nums, 0, mid - 1, curr->left);
            help_108(nums, mid + 1, nums.size() - 1, curr->right);
        }
    }
private:
    void helper_101(TreeNode<int>* root, std::vector<int>& vals, bool left){
        if(root == nullptr){
            vals.push_back(-1);
            return;
        }
        if(left){
            helper_101(root->left, vals, left);
            helper_101(root->right, vals, left);
        } else {
            helper_101(root->right, vals, left);
            helper_101(root->left, vals, left);
        }
        
        vals.push_back(root->val);
    }
    void LevelOrderHelper_102(TreeNode<int>* root, std::vector<std::vector<int>>& ans){
        if(root == nullptr)
            return;

        int count(1), empty(0), next_count(0);
        std::vector<int> curr;    
        std::queue<TreeNode<int>*> st;
        st.push(root);

        TreeNode<int>* tmp;
        while (!st.empty())
        {
            tmp = st.front();
            st.pop();

            if(tmp->left != nullptr){
                st.push(tmp->left);
                ++next_count;
            }
            if(tmp->right != nullptr){
                st.push(tmp->right);
                ++next_count;
            }
                
            curr.push_back(tmp->val);
            --count;

            if(count == 0){
                ans.push_back(curr);
                curr.clear();
                count = next_count;
                next_count = 0;
            }
        }
    }
    void zigzagLevelOrderHelper_103(TreeNode<int>* root, std::vector<std::vector<int>>& ans){
        if(root == nullptr)
            return;

        std::list<TreeNode<int>*> list;
        std::vector<int> tmp;
        list.push_back(root);
        bool left(true);

        TreeNode<int>* curr;
        while (!list.empty())
        {
            size_t s = list.size();
            while (s--)
            {   
                if(left){
                    curr = list.front();
                    list.pop_front();
                } else {
                    curr = list.back();
                    list.pop_back();
                }
                
                if(!left){
                    if(curr->right != nullptr)
                        list.push_front(curr->right);
                    if(curr->left != nullptr)
                        list.push_front(curr->left);
                } else {
                    if(curr->left != nullptr)
                        list.push_back(curr->left);
                    if(curr->right != nullptr)
                        list.push_back(curr->right);
                }
                tmp.push_back(curr->val);
            }   
            ans.push_back(tmp);
            tmp.clear();
            left = left ? false : true;         
        }
    }
    
    int depth_111(TreeNode<int>* root){
        if(root == nullptr)
            return 0;

        int count(1), empty(0), next_count(0), depth(1); 
        std::queue<TreeNode<int>*> st;
        st.push(root);

        TreeNode<int>* curr;
        while (!st.empty())
        {
            curr = st.front();
            st.pop();

            if(curr->left == nullptr and curr->right == nullptr)
                return depth;
            if(curr->left != nullptr){
                st.push(curr->left);
                ++next_count;
            }
            if(curr->right != nullptr){
                st.push(curr->right);
                ++next_count;
            }  
            --count;

            if(count == 0){
                depth++;
                count = next_count;
                next_count = 0;
            }
        }
        return depth;
    }
};

int main(){
    Solution solution;   
    Timer timer("LeetCode_200.cpp");
    
    

}