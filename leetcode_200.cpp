#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
    };

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
    // sh::print(solution.maxDepth_104(root));
    int maxDepth_104(TreeNode<int>* root) {
        if(root == nullptr){
            return 0;
        }
        return 1 + std::max(maxDepth_104(root->left), maxDepth_104(root->right));
    }

    //--------------------------#105--------------------------------------------//
    // std::vector<int> v1{3,1,2,4};
    // std::vector<int> v2{1,2,3,4};
    // sh::showTreeLevel(solution.buildTree_105(v1, v2));
    TreeNode<int>* buildTree_105(std::vector<int>& preorder, std::vector<int>& inorder) {
        std::unordered_map<int, int> pos;
        int start(0);
        for(size_t i(0); i != inorder.size(); ++i){
            pos[inorder[i]] = i;
        }
        
        return help_105(preorder, inorder, pos, 0, preorder.size() - 1, start, true);
    }

    //--------------------------#107--------------------------------------------//
    std::vector<std::vector<int>> levelOrderBottom_107(TreeNode<int>* root) {
        std::vector<std::vector<int>> ans;
        std::vector<int> tmp;
        std::queue<TreeNode<int>*> q;
        q.push(root);

        TreeNode<int>* curr;
        while (!q.empty())
        {
            size_t size = q.size();
            while (size--)  
            {
                curr = q.front();
                q.pop();

                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
                tmp.push_back(curr->val);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        std::reverse(std::begin(ans), std::end(ans));
        return ans;
    }

    //--------------------------#108--------------------------------------------//
    // std::vector<int> v{-10,-3,0,5,9};
    // sh::showTreeLevel(solution.sortedArrayToBST_108(v));
    TreeNode<int>* sortedArrayToBST_108(std::vector<int>& nums) {
        return help_108(nums, 0, nums.size());
    }

    //--------------------------#109--------------------------------------------//
    TreeNode<int>* sortedListToBST(ListNode* head) {
        std::vector<int> nums;
        while (head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return help_108(nums, 0, nums.size());
    }

    //--------------------------#111--------------------------------------------//
    int minDepth_111(TreeNode<int>* root) {
        return depth_111(root);
    }

    //--------------------------#112--------------------------------------------//
    bool hasPathSum_112(TreeNode<int>* root, int targetSum) {
        if(root == nullptr)
            return false;
        return help_112(root, targetSum);
    }

    //--------------------------#113--------------------------------------------//
    std::vector<std::vector<int>> pathSum_113(TreeNode<int>* root, int targetSum) {
        if(root == nullptr)
            return {};
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        help_113(root, targetSum, res, curr);
        return res;
    }

    //--------------------------#114--------------------------------------------//
    void flatten_114(TreeNode<int>* root) {
        help_114(root);
    }
    
    //--------------------------#116--------------------------------------------//
    Node* connect_116(Node* root) {
        std::queue<Node*> q;
        if(root)
            q.push(root);

        Node* curr;
        while (!q.empty())
        {
            size_t s = q.size();
            while (s--)
            {
                curr = q.front();
                q.pop();
                if(s)
                    curr->next = q.front();
                
                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);
            }
        }
        return root;
    }

    //--------------------------#117--------------------------------------------//
    Node* connect_117(Node* root) {
        std::queue<Node*> q;
        if(root)
            q.push(root);

        Node* curr;
        while (!q.empty())
        {
            size_t s = q.size();
            while (s--)
            {
                curr = q.front();
                q.pop();
                if(s)
                    curr->next = q.front();
                
                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);
            }
        }
        return root;
    }

    //--------------------------#118--------------------------------------------//
    // sh::showVecVec(solution.generate_118(5));
    std::vector<std::vector<int>> generate_118(int numRows) {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;

        for(size_t i(1); i - 1 != numRows; ++i){
            curr.resize(i, 1);
            for(size_t j(1); j < curr.size() - 1; ++j){
                curr[j] = ans[i - 2][j - 1] + ans[i - 2][j];
            }
            ans.push_back(curr);
            curr.clear();
        }
        return ans;
    }

    //--------------------------#437--------------------------------------------//
    //         10
    //        /  \
    //       5   -3
    //     /  \    \
    //    3    2    11
    //   / \    \
    //  3  -2    1 
    // TreeNode<int>* root = new TreeNode<int>(10,
    //     new TreeNode<int>(5,
    //         new TreeNode<int>(3,
    //             new TreeNode<int>(3),
    //             new TreeNode<int>(-2)),
    //         new TreeNode<int>(2,
    //             nullptr,
    //             new TreeNode<int>(1))
    //     ),
    //     new TreeNode<int>(-3,
    //         nullptr, 
    //         new TreeNode<int>(11))
    // );
    // sh::print(solution.pathSum_437(root, 8));
    int pathSum_437(TreeNode<int>* root, int targetSum) {
        std::vector<long> partial_sum;
        return help_437(root, targetSum, partial_sum);
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
    TreeNode<int>* help_105(std::vector<int>& bylevels, std::vector<int>& inorder, std::unordered_map<int, int>& pos, int l, int r, int& ind, bool st){
        if(ind >= bylevels.size())
            return nullptr;
        if(st == false) {
            if(l == r){
                return new TreeNode<int>(bylevels[ind]);
            }
            if(l > r or pos[bylevels[ind]] > r or pos[bylevels[ind]] < l){
                return nullptr;
            }
        }
        st = false;
        TreeNode<int>* root = new TreeNode<int>(bylevels[ind]);
        
        root->left = help_105(bylevels, inorder, pos, l, pos[root->val] - 1, ++ind , st);
        if (root->left == nullptr)
            --ind;
        root->right = help_105(bylevels, inorder, pos, pos[root->val] + 1, r, ++ind,  st);
        if (root->right == nullptr)
            --ind;
        
        return root;
    }
    TreeNode<int>* help_108(std::vector<int>& nums, int l, int r){
        if(l >= r)
            return nullptr;

        int mid = (r + l) / 2; 
        TreeNode<int>* node = new TreeNode<int>(nums[mid]);

        node->left = help_108(nums, l, mid);
        node->right = help_108(nums, mid + 1, r);
        return node;
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
    bool help_112(TreeNode<int>* root, int targetSum){
        if(root == nullptr)
            return false;
        if(root->left == nullptr and root->right == nullptr and targetSum - root->val == 0){
            return true;
        }
        bool res(false);
        res = help_112(root->left, targetSum - root->val);
        if(res == true)
            return res;
        res = help_112(root->right, targetSum - root->val);
        if(res == true)
            return res;
        return res;
    }
    void help_113(TreeNode<int>* root, int targetSum, std::vector<std::vector<int>>& res, std::vector<int>& curr){
        if(root == nullptr){
            if(targetSum == 0){
                res.push_back(curr);
            }
            return;
        }
            
        curr.push_back(root->val);
        help_113(root->left, targetSum - root->val, res, curr);
        help_113(root->right, targetSum - root->val, res, curr);
        curr.pop_back();
    }
    void help_114(TreeNode<int>* root){
        if(root == nullptr)
            return;


        TreeNode<int>* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode<int>* node = root;
        
        while(node->right != nullptr){
            node = node->right;
        }
        node->right = tmp;

        help_114(root->right);
    }
    int help_437(TreeNode<int>* root, int targetSum, std::vector<long>& partial_sum){
        if(root == nullptr)
            return 0;

        int count(0);     
        partial_sum.push_back(root->val);
        for(size_t i(0); i != partial_sum.size(); ++i){
            if(i != partial_sum.size() - 1)
                partial_sum[i] += root->val;
            
            if(targetSum - partial_sum[i] == 0)
                ++count;
        }
        
        int l = help_437(root->left, targetSum, partial_sum); 
        int r = help_437(root->right, targetSum, partial_sum);
        partial_sum.pop_back();
        for(size_t i(0); i != partial_sum.size(); ++i){
            partial_sum[i] -= root->val;
        }
        return count + l + r;
    }
};

int main(){
    Solution solution;   
    Timer timer("LeetCode_200.cpp");
      
    Node* root = new Node(-9,
        new Node(-3,
            nullptr,
            new Node(4,
                new Node(-6),
                nullptr,
                nullptr
            ),
            nullptr
        ),
        new Node(2,
            new Node(4,
                new Node(-5),
                nullptr,
                nullptr
            ),
            new Node(0),
            nullptr
        ),
        nullptr    
    );
    solution.connect_117(root);
}