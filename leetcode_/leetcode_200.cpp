#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

    //--------------------------#173--------------------------------------------//
class BSTIterator {
    std::stack<TreeNode*> st;

    void PushNodes(TreeNode* node){
        while(node){
            st.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        PushNodes(root);
    }
    
    int next(){
        TreeNode* curr = st.top();
        st.pop();
        PushNodes(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty(); 
    }
};

    //--------------------------#155--------------------------------------------//
    // MinStack* minStack = new MinStack();
    // minStack->push(-2);
    // minStack->push(0);
    // minStack->push(-3);
    // sh::print(minStack->getMin()); // return -3
    // minStack->pop();
    // sh::print(minStack->top());    // return 0
    // sh::print(minStack->getMin());
class MinStack {
    std::vector< std::pair<int,int> > s;
public:
    MinStack() { }
    
    void push(int val) {
        if(s.empty())
            s.push_back({val,val});
        else
            s.push_back({val,std::min(s.back().second,val)});    
    }
    
    void pop() { s.pop_back(); }
    
    int top() { return s.back().first; }
    
    int getMin() {
        return s.back().second; 
    }
};

class Solution {
    void helper_101(TreeNode* root, std::vector<int>& vals, bool left){
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
    
    void LevelOrderHelper_102(TreeNode* root, std::vector<std::vector<int>>& ans){
        if(root == nullptr)
            return;

        int count(1), empty(0), next_count(0);
        std::vector<int> curr;    
        std::queue<TreeNode*> st;
        st.push(root);

        TreeNode* tmp;
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
    
    void zigzagLevelOrderHelper_103(TreeNode* root, std::vector<std::vector<int>>& ans){
        if(root == nullptr)
            return;

        std::list<TreeNode*> list;
        std::vector<int> tmp;
        list.push_back(root);
        bool left(true);

        TreeNode* curr;
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
    TreeNode* help_105(std::vector<int>& bylevels, std::vector<int>& inorder, std::unordered_map<int, int>& pos, int l, int r, int& ind, bool st){
        if(ind >= bylevels.size())
            return nullptr;
        if(st == false) {
            if(l == r){
                return new TreeNode(bylevels[ind]);
            }
            if(l > r or pos[bylevels[ind]] > r or pos[bylevels[ind]] < l){
                return nullptr;
            }
        }
        st = false;
        TreeNode* root = new TreeNode(bylevels[ind]);
        
        root->left = help_105(bylevels, inorder, pos, l, pos[root->val] - 1, ++ind , st);
        if (root->left == nullptr)
            --ind;
        root->right = help_105(bylevels, inorder, pos, pos[root->val] + 1, r, ++ind,  st);
        if (root->right == nullptr)
            --ind;
        
        return root;
    }
    TreeNode* help_106(std::vector<int>& postorder, std::vector<int>& inorder, std::unordered_map<int, int>& pos, int l, int r, int& ind, bool st)
    {
        if(ind < 0){
            return nullptr;
        }
        if(st == false) {
            if(l == r){
                return new TreeNode(postorder[ind]);
            }
            if(l > r or pos[postorder[ind]] > r or pos[postorder[ind]] < l){
                return nullptr;
            }
        }

        st = false;
        TreeNode* root = new TreeNode(postorder[ind]);
        

        root->right = help_105(postorder, inorder, pos, pos[root->val] + 1, r, --ind,  st);
        if (root->right == nullptr)
            ++ind;
        root->left = help_105(postorder, inorder, pos, l, pos[root->val] - 1, --ind , st);
        if (root->left == nullptr)
            ++ind;
        
        return root;
    }
    TreeNode* help_108(std::vector<int>& nums, int l, int r){
        if(l >= r)
            return nullptr;

        int mid = (r + l) / 2; 
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = help_108(nums, l, mid);
        node->right = help_108(nums, mid + 1, r);
        return node;
    }
    int help_110(TreeNode* root, bool& ans){
        if(root == nullptr or !ans)
            return 0;

        int l = help_110(root->left, ans);
        int r = help_110(root->right, ans);
        if(abs(l - r) > 1){
            ans = false;
        }

        return 1 + std::max(l, r);
    }
    int depth_111(TreeNode* root){
        if(root == nullptr)
            return 0;

        int count(1), empty(0), next_count(0), depth(1); 
        std::queue<TreeNode*> st;
        st.push(root);

        TreeNode* curr;
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
    bool help_112(TreeNode* root, int targetSum){
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
    void help_113(TreeNode* root, int targetSum, std::vector<std::vector<int>>& res, std::vector<int>& curr){
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
    void help_114(TreeNode* root){
        if(root == nullptr)
            return;


        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* node = root;
        
        while(node->right != nullptr){
            node = node->right;
        }
        node->right = tmp;

        help_114(root->right);
    }
    int help_129(TreeNode* root, int curr_num){
        if(!root)
            return 0;

        curr_num = curr_num * 10 + root->val;
        if (!root->left and !root->right)
            return curr_num;
        
        return help_129(root->left, curr_num) + help_129(root->right, curr_num); 
    }
    void check_130(std::vector<std::vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 1) check_130(board, i - 1, j);
            if (j > 1) check_130(board, i, j - 1);
            if (i + 1 < board.size()) check_130(board, i + 1, j);
            if (j + 1 < board[0].size()) check_130(board, i, j + 1);
        }
    }
    void Comb_131( std::vector<std::vector<std::string>>& res, std::string& s, std::vector<std::string>& curr, int start){
        int n = s.length();
        if(start == n){
            res.push_back(curr);
        } else {
            for(size_t i(start); i != n; ++i){
                if(IsPalinnrom_131(s, start, i)){
                    curr.push_back(s.substr(start, i - start + 1));
                    Comb_131(res, s, curr, i + 1);
                    curr.pop_back();
                }
            }
        }
        
    }
    bool IsPalinnrom_131(std::string& s, int l, int r){
        while (l < r)
        {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    bool Segmented_139(std::string& s,  std::unordered_set<std::string>& dict, std::vector<bool>& dp, int st){
        if(dp[st])
            return false;
        for(auto it = std::begin(dict); it != std::end(dict); ++it){
            if(s.substr(st, it->size()) == *it){
                Segmented_139(s, dict, dp,  st + it->size());
            }
        }
        dp[st] = true;
        return dp[s.size()];
    }
    void Segmented_140(std::string& s, std::unordered_set<std::string>& dict,std::vector<std::string>& res, std::vector<std::string>& curr, int st){
        if(st == s.size()){
            res.push_back(GetStr(curr));
            return;
        }
           
        for(auto it = std::begin(dict); it != std::end(dict); ++it){
            std::string str = s.substr(st, it->size());
            if(str == *it){
                curr.push_back(str);
                Segmented_140(s, dict, res, curr,  st + it->size());
                curr.pop_back();
            }
        }
        
    }
    std::string GetStr(std::vector<std::string> str){
        std::string res;
        for(const auto& s : str){
            if(!res.empty())
                res.push_back(' ');
            res.append(s);
        }
        return res;
    }
public:
    //--------------------------#101--------------------------------------------//
    // TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    // sh::print(solution.isSymmetric_101(root));
    bool isSymmetric_101(TreeNode* root) {
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
    // TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    // sh::showVecVec(solution.levelOrder_102(root));
    std::vector<std::vector<int>> levelOrder_102(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        LevelOrderHelper_102(root, ans);
        return ans;
    }
    
    //--------------------------#103--------------------------------------------//
    // TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    // sh::showVecVec(solution.zigzagLevelOrder_103(root));
    std::vector<std::vector<int>> zigzagLevelOrder_103(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        zigzagLevelOrderHelper_103(root, ans);
        return ans;
    }

    //--------------------------#104--------------------------------------------//
    // TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    // sh::print(solution.maxDepth_104(root));
    int maxDepth_104(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return 1 + std::max(maxDepth_104(root->left), maxDepth_104(root->right));
    }

    //--------------------------#105--------------------------------------------//
    // std::vector<int> v1{3,1,2,4};
    // std::vector<int> v2{1,2,3,4};
    // sh::showTreeLevel(solution.buildTree_105(v1, v2));
    TreeNode* buildTree_105(std::vector<int>& preorder, std::vector<int>& inorder) {
        std::unordered_map<int, int> pos;
        int start(0);
        for(size_t i(0); i != inorder.size(); ++i){
            pos[inorder[i]] = i;
        }
        
        return help_105(preorder, inorder, pos, 0, preorder.size() - 1, start, true);
    }

    //--------------------------#106--------------------------------------------//
    TreeNode* buildTree_106(std::vector<int>& inorder, std::vector<int>& postorder) {
        std::unordered_map<int, int> pos;
        int start(postorder.size() - 1);
        for(size_t i(0); i != inorder.size(); ++i){
            pos[inorder[i]] = i;
        }
        return help_106(postorder, inorder, pos, 0, postorder.size() - 1, start, true);
    }

    //--------------------------#107--------------------------------------------//
    std::vector<std::vector<int>> levelOrderBottom_107(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        std::vector<int> tmp;
        std::queue<TreeNode*> q;
        q.push(root);

        TreeNode* curr;
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
    TreeNode* sortedArrayToBST_108(std::vector<int>& nums) {
        return help_108(nums, 0, nums.size());
    }

    //--------------------------#109--------------------------------------------//
    TreeNode* sortedListToBST_109(ListNode* head) {
        std::vector<int> nums;
        while (head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return help_108(nums, 0, nums.size());
    }

    //--------------------------#110--------------------------------------------//
    bool isBalanced_110(TreeNode* root) {
        bool ans(true);
        help_110(root, ans);
        return ans;
    }
    
    //--------------------------#111--------------------------------------------//
    int minDepth_111(TreeNode* root) {
        return depth_111(root);
    }

    //--------------------------#112--------------------------------------------//
    bool hasPathSum_112(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        return help_112(root, targetSum);
    }

    //--------------------------#113--------------------------------------------//
    std::vector<std::vector<int>> pathSum_113(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return {};
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        help_113(root, targetSum, res, curr);
        return res;
    }

    //--------------------------#114--------------------------------------------//
    void flatten_114(TreeNode* root) {
        help_114(root);
    }
    
    //--------------------------#115--------------------------------------------//
    // sh::print(solution.numDistinct_115("babgbag", "bag"));
    int numDistinct_115(std::string s, std::string t) {
        // if(t.size() > s.size())
        //     return 0;
        // if(t.size() == s.size())
        //     return t == s;
        // std::vector<std::pair<int, int>> prev;
        // for(size_t i(0); i != t.size(); ++i){
        //     char curr = t[i];
        //     std::vector<std::pair<int, int>> next;
        //     for(size_t j(0); j != s.size(); ++j){
        //         if(curr == s[j]){
        //             if(i == 0){
        //                 next.push_back({j, 1});
        //             } else {
        //                 int sum(0);
        //                 for(size_t k(0); k != prev.size(); ++k){
        //                     if(j > prev[k].first)
        //                         sum += prev[k].second;
        //                     else
        //                         break;
        //                 }
        //                 next.push_back({j, sum});
        //             }
        //         } 
        //     }
        //     prev = std::move(next);
        // }
        // return std::accumulate(std::begin(prev), std::end(prev), 0, [](int sum, std::pair<int,int> curr){
        //     return sum += curr.second;
        // });
            //     rabbit 
            //     000000 
            //   r 100000 
            //   a 110000 
            //   b 111000 
            //   b 112100 
            //   b 113300 
            //   i 113330 
            //   t 113333 
        int m = t.length(), n = s.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int> (n + 1, 0));
        for (int j = 0; j <= n; j++)
            dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
        return dp[m][n];
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

    //--------------------------#119--------------------------------------------//
    // sh::showContainer(solution.getRow_119(3));
    std::vector<int> getRow_119(int rowIndex) {
        std::vector<int> prev;
        std::vector<int> curr;

        for(size_t i(1); i - 2 != rowIndex; ++i){
            curr.resize(i, 1);
            for(size_t j(1); j < curr.size() - 1; ++j){
                curr[j] = prev[j - 1] + prev[j];
            }
            prev = std::move(curr);
        }
        return prev;
    }

    //--------------------------#120--------------------------------------------//
    // std::vector<std::vector<int>> tr{
    //    {2},
    //    {3,4},
    //    {6,5,7},
    //    {4,1,8,3} 
    // };
    // solution.minimumTotal_120(tr);
    int minimumTotal_120(std::vector<std::vector<int>>& triangle) {
        std::vector<int> prev(1, triangle[0][0]);
        std::vector<int> next;
        for(size_t i(1); i != triangle.size(); ++i){
            next.reserve(i + 1);
            int add;
            for(size_t j(0); j != triangle[i].size(); ++j){
                if(j == 0)
                    add = prev[j];
                else if(j == triangle[i].size() - 1)
                    add = prev[j-1];
                else 
                    add = std::min(prev[j-1], prev[j]);
                next.push_back(triangle[i][j] + add);
            }
            prev = std::move(next);
        }
        return *std::min_element(std::begin(prev), std::end(prev));
    }
    
    //--------------------------#121--------------------------------------------//
    // std::vector<int> v{7,1,5,3,6,4,4,7,3,9};
    // sh::print(solution.maxProfit(v));
    int maxProfit_121(std::vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }

    //--------------------------#122--------------------------------------------//
    // std::vector<int> v{7,6,4,3,1};
    // sh::print(solution.maxProfit_122(v));
    int maxProfit_122(std::vector<int>& prices) {
        int buy = prices[0];
        int profit(0);
        for(size_t i(1); i != prices.size(); ++i){
            if(prices[i] < buy)
                buy = prices[i];
            else if (prices[i] > buy)
            {
                profit += prices[i] - buy;
                buy = prices[i];
            }   
        }
        return profit;
    }

    //--------------------------#123--------------------------------------------//
    // std::vector<int> v{3,3,5,0,0,3,1,4};
    // sh::print(solution.maxProfit_123(v));
    int maxProfit_123(std::vector<int>& prices) {
        int oneBuyOneSell = 0;
        int twoBuyTwoSell = 0;
        int oneBuy = INT_MAX;
        int twoBuy = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            const int p = prices[i];
            oneBuy = std::min(oneBuy, p);
            oneBuyOneSell = std::max(oneBuyOneSell, p - oneBuy);
            twoBuy = std::min(twoBuy, p - oneBuyOneSell);
            twoBuyTwoSell = std::max(twoBuyTwoSell, p - twoBuy);
        }
        return twoBuyTwoSell;
    }

    //--------------------------#124--------------------------------------------//
    int maxPathSum_124(TreeNode* root) {
        int res(root->val);
        GetPathSum_124(root, res);
        return res;
    }
    int GetPathSum_124(TreeNode* root, int& res){
        if(!root)
            return 0;
        
        int leftSum = std::max(GetPathSum_124(root->left, res), 0);
        int rightSum = std::max(GetPathSum_124(root->right, res), 0);
        
        res = std::max(res, root->val + leftSum + rightSum);

        return root->val + std::max(leftSum, rightSum);
    }

    //--------------------------#125--------------------------------------------//
    // sh::print(solution.isPalindrome_125("ab2a"));
    bool isPalindrome_125(std::string s) {
        int l(0), r(s.size() - 1);
        bool res(true);
        
        while (l < r)
        {
            while(l <= r and !((tolower(s[l]) >= 'a' and tolower(s[l]) <= 'z') or (s[l] >= '0' and s[l] <= '9')))
                ++l;
            if(l >= r)
                break;
            while(l <= r and !((tolower(s[r]) >= 'a' and tolower(s[r]) <= 'z') or (s[r] >= '0' and s[r] <= '9')))
                --r;
            if(l >= r)
                break;
            if(tolower(s[l++]) != tolower(s[r--])){
                res = false;
                break;
            }
        }
        return res;
    }

    //--------------------------#128--------------------------------------------//
    // std::vector<int> v{100,4,105,1,3,2,101, 102,103,104};
    // sh::print(solution.longestConsecutive(v));
    int longestConsecutive_128(std::vector<int>& nums) {
        if(nums.empty())
            return 0;
        std::set<int> seq(std::begin(nums), std::end(nums));
        
        int len(1), res(1);
        std::set<int>::iterator prev = std::begin(seq);
        for(auto it = ++std::begin(seq); it != std::end(seq); ++it){
            *prev == *it - 1 ? ++len : len = 1;
            res = std::max(res, len);
            prev = it;
        }
        return res;
    }

    //--------------------------#129--------------------------------------------//
    int sumNumbers(TreeNode* root) {
        return help_129(root, 0);
    }
    
    //--------------------------#130--------------------------------------------//
    // std::vector<std::vector<char>> board{
    //     {'O','O','X','O' },
    //     {'O','O','O','O' },
    //     {'O','O','O','O' }
    // };
    // sh::showVecVec(board);
    // solution.solve_130(board);
    // sh::showVecVec(board);
    void solve_130(std::vector<std::vector<char>>& board) {
        if (board.empty()) return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            check_130(board, i, 0);             // first column
            check_130(board, i, col - 1);       // last column
        }
        for (int j = 1; j < col - 1; ++j) {
            check_130(board, 0, j);             // first row
            check_130(board, row - 1, j);       // last row
        }
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
    }
    
    //--------------------------#131--------------------------------------------//
    std::vector<std::vector<std::string>> partition_131(std::string s) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> curr;
        Comb_131(res, s, curr, 0);
        return res;
    }
    
    //--------------------------#134--------------------------------------------//
    // std::vector<int> gas{1,2,3,4,5};
    // std::vector<int> cost{3,4,5,1,2};
    // sh::print(solution.canCompleteCircuit_134(gas, cost));
    int canCompleteCircuit_134(std::vector<int>& gas, std::vector<int>& cost) {
        int n = gas.size();
        int sum(0), profit, prev;
        int max(-1), index(n - 1);
        for(size_t i(n - 1); i + 1 > 0; --i){
            profit = gas[i] - cost[i];
            sum += profit;
            if(i != n - 1){
                profit += prev;
            }
            if(max < profit){
                max = profit;
                index = i;
            }
            prev = profit;
        }
        return sum < 0 ? -1 : index; 
    }

    //--------------------------#133--------------------------------------------//
    // Node* l1 = new Node(1);
    // Node* l2 = new Node(2);
    // Node* l3 = new Node(3);
    // Node* l4 = new Node(4);
    // l1->neighbors.push_back(l2);
    // l1->neighbors.push_back(l4);
    // l2->neighbors.push_back(l1);
    // l2->neighbors.push_back(l3);
    // l3->neighbors.push_back(l2);
    // l3->neighbors.push_back(l4);
    // l4->neighbors.push_back(l1);
    // l4->neighbors.push_back(l3);
    // Node* n = solution.cloneGraph_133(l1);
    // Node* cloneGraph_133(Node* node) {
    //     if(!node)
    //         return nullptr;
    //     std::unordered_map<int, Node*> nodes;
    //     std::unordered_set<int> visited;
    //     std::queue<Node*> q;
    //     q.push(node);
    //     Node* curr;
    //     while (!q.empty())
    //     {
    //         curr = q.front();
    //         q.pop();
    //         Node* new_node = nodes.contains(curr->val) ? nodes[curr->val] : new Node(curr->val);
    //         nodes[curr->val] = new_node;
    //         visited.insert(curr->val);
    //         std::vector<Node*>& connections = curr->neighbors; 
    //         for(size_t i(0); i != connections.size(); ++i){
    //             if(nodes.contains(connections[i]->val)){
    //                 new_node->neighbors.push_back(nodes[connections[i]->val]);
    //             } else {
    //                 Node* con = new Node(connections[i]->val);
    //                 nodes[connections[i]->val] = con;
    //                 new_node->neighbors.push_back(con); 
    //             }
    //             if(!visited.contains(connections[i]->val)){
    //                 q.push(connections[i]);
    //                 visited.insert(connections[i]->val);
    //             }
    //         }
    //     }
    //     return nodes[1];
    // }

    //--------------------------#136--------------------------------------------//
    int singleNumber_136(std::vector<int>& nums) {
        int num(0);
        for(size_t i(0); i != nums.size(); ++i)
            num ^= nums[i];
        return num;
        //return std::accumulate(begin(nums), end(nums), 0, std::bit_xor<int>());
    }

    //--------------------------#137--------------------------------------------//
    // std::vector<int> nums{2,2,2,3};
    // sh::print(solution.singleNumber_137(nums));
    int singleNumber_137(std::vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (const int num : nums) {
            ones ^= (num & ~twos);
            twos ^= (num & ~ones);
        }

        return ones;
        // std::vector<int> bits(32, 0);
        // for(size_t i(0); i != nums.size(); ++i){
        //     int curr = nums[i];
        //     int bit, j(0);
        //     while (j != 32)
        //     {
        //         bit = curr % 2;
        //         curr = curr >> 1;
        //         bits[j++] += bit;  
        //     }
        // }
        // int res(0);
        // for(size_t i(0); i != bits.size(); ++i){
        //     if(bits[i] % 3 != 0){
        //         res += 1 << i;
        //     }
        // }
        // return res;
    }

    //--------------------------#139--------------------------------------------//
    // std::string s = "leetcode";
    // std::vector<std::string> wordDict = {"leet","code"};
    // sh::print(solution.wordBreak_139(s, wordDict));
    bool wordBreak_139(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> dict(std::begin(wordDict), std::end(wordDict));
        std::vector<bool> dp(s.size() + 1);
        return Segmented_139(s, dict, dp, 0);
    }

    //--------------------------#140--------------------------------------------//
    // std::string s = "catsanddog";
    // std::vector<std::string> wordDict = {"cat","cats","and","sand","dog"};
    // sh::showContainer(solution.wordBreak_140(s, wordDict));
    std::vector<std::string> wordBreak_140(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> dict(std::begin(wordDict), std::end(wordDict));
        std::vector<std::string> res;
        std::vector<std::string> curr;
        Segmented_140(s, dict, res, curr, 0);
        return res;
    } 
    
    //--------------------------#141--------------------------------------------//
    bool hasCycle_141(ListNode *head) {
        std::unordered_set<ListNode*> check;
        while (head != nullptr)
        {
            if(check.contains(head)){
                return true;
            }
            check.insert(head);
            head = head->next;
        }
        return false;
    }

    //--------------------------#142--------------------------------------------//
    ListNode *detectCycle_142(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
        // std::unordered_set<ListNode*> check;
        // while (head != nullptr)
        // {
        //     if(check.contains(head)){
        //         return head;
        //     }
        //     check.insert(head);
        //     head = head->next;
        // }
        // return nullptr;
    }

    //--------------------------#143--------------------------------------------//
    // ListNode l1(1, new ListNode(2, new ListNode(3,(new ListNode(4, new ListNode(5))))));
    // sh::showList(&l1);
    // solution.reorderList_143(&l1);
    // sh::showList(&l1);
    void reorderList_143(ListNode* head) {
        std::vector<ListNode*> nodes;
        while(head != nullptr){
            nodes.push_back(head);
            head = head->next;
        }
        ListNode* curr = nodes[0];
        for(size_t i(1); i != nodes.size(); ++i){
            int pos = i % 2 == 0 ? i / 2 : nodes.size() - i / 2 - 1; 
            ListNode* next_node = nodes[pos];
            curr->next = next_node;
            curr = curr->next;
        }
        curr->next = nullptr;
    }

    //--------------------------#144--------------------------------------------//
    std::vector<int> preorderTraversal_144(TreeNode* root) {
        std::vector<int> res;
        PreOrder_144(root, res);
        return res;
    }
    void PreOrder_144(TreeNode* root, std::vector<int>& res){
        if(!root){
            return;
        }
        res.push_back(root->val);
        PreOrder_144(root->right, res);
        PreOrder_144(root->left, res);
    }

    //--------------------------#145--------------------------------------------//
    std::vector<int> postorderTraversal_145(TreeNode* root) {
        std::vector<int> res;
        PostOrder_145(root, res);
        return res;
    }
    void PostOrder_145(TreeNode* root, std::vector<int>& res){
        if(!root){
            return;
        }
        PostOrder_145(root->left, res);
        PostOrder_145(root->right, res);
        res.push_back(root->val);
    }

    //--------------------------#147--------------------------------------------//
    // ListNode l1(4, new ListNode(2, new ListNode(1,(new ListNode(3)))));
    // sh::showList(&l1);
    // solution.insertionSortList(&l1);
    ListNode* insertionSortList_147(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* end = dummy->next;
        ListNode* curr;
        ListNode* prev;
        ListNode* next_el;
        while (end->next != nullptr)
        {
            // new elem 
            next_el = end->next;

            // swap pointers
            end->next = next_el->next;
            next_el->next = nullptr;

            // find new place and insert nwxt_el in
            prev = dummy;
            curr = dummy->next;
            while (prev != end and curr->val < next_el->val )
            {
                prev = curr;
                curr = curr->next;
            }

            prev->next = next_el;
            next_el->next = curr;
            if(prev == end)
                end = end->next;
        }
        return dummy->next;
    }

    //--------------------------#148--------------------------------------------//
    ListNode* sortList_148(ListNode* head) {
        std::vector<int> tmp;
        ListNode* curr = head;
        while (curr){
            tmp.push_back(curr->val);
            curr = curr->next;
        }
            
        std::sort(begin(tmp), end(tmp));
        curr = head;
        for(size_t i(0); i != tmp.size(); ++i){  
            curr->val = tmp[i];
            curr = curr->next;
        }
        return head;
    }

    //--------------------------#160--------------------------------------------//
    ListNode *getIntersectionNode_160(ListNode *headA, ListNode *headB) {
		int lenA = 0;
		int lenB = 0;
		ListNode* ptrA = headA;
		ListNode* ptrB = headB;
        while(ptrA->next or ptrB->next)
        {
            if(ptrA){
                ++lenA;
                ptrA = ptrA->next;
            }
            if(ptrB){
                ++lenB;
                ptrB = ptrB->next;
            }     
        }
        if(ptrA != ptrB)
            return nullptr;
        ++lenA;
        ++lenB;
        
		int diff = abs(lenA - lenB);
		if(lenA > lenB){
			while(diff){
				headA = headA -> next;
				diff--;
			}
		}
		else{
			while(diff){
				headB = headB -> next;
				diff--;
			}
		}
		while(headA != nullptr and headB != nullptr){
			if(headA == headB)
				return headA;
			headA = headA -> next;
			headB = headB -> next;
		}
		return nullptr;
	}

    //--------------------------#162--------------------------------------------//
    // std::vector<int> nums{4,3,2,1};
    // sh::print(solution.findPeakElement_162(nums));
    int findPeakElement_162(std::vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        return findPeak_162(nums, 0, nums.size() - 1);
    }
    int findPeak_162(std::vector<int>& nums, int l, int r){
        if(l > r)
            return -1;
        int mid = (l + r) / 2;
        int left(-1), right(-1);
        if(mid == 0){
            if(nums[mid] > nums[mid + 1])
                return mid;
            right = findPeak_162(nums, mid + 1, r);
        } else if (mid == nums.size() - 1)
        {
            if(nums[mid] > nums[mid - 1])
                return mid;
            left = findPeak_162(nums, l, mid - 1);
        } else {
            if(nums[mid] > nums[mid + 1] and nums[mid] > nums[mid - 1])
                return mid;
            left = findPeak_162(nums, l, mid - 1);
            right = findPeak_162(nums, mid + 1, r);
        }
        return left == -1 ? right : left;
    }

    //--------------------------#165--------------------------------------------//
    // std::string version1("1");
    // std::string version2("1.1");
    // sh::print(solution.compareVersion_165(version1, version2));
    int compareVersion_165(std::string version1, std::string version2) {
        int res(0);
        int prev1(0), prev2(0);
        int ptr1(0), ptr2(0);
        while (ptr1 < version1.size() or ptr2 < version2.size())
        {
            while (ptr1 < version1.size() and version1[ptr1] != '.')
                ++ptr1;
            while (ptr2 < version2.size() and version2[ptr2] != '.')
                ++ptr2;

            if(prev1 != ptr1 and prev2 != ptr2){
                int str1 = std::stoi(version1.substr(prev1, ptr1 - prev1));
                int str2 = std::stoi(version2.substr(prev2, ptr2 - prev2));
                if(str1 != str2)
                    return str1 < str2 ? -1 : 1;
            } else if(prev1 == ptr1){
                ptr2 = prev2;
                while (ptr2 < version2.size()){
                    if(version2[ptr2] != '0' and version2[ptr2] != '.')
                        return -1;
                    ++ptr2;
                }
            } else if(prev2 == ptr2){
                ptr1 = prev1;
                while (ptr1 < version1.size()){
                    if(version1[ptr1] != '0' and version1[ptr1] != '.')
                        return 1;
                    ++ptr1;
                }    
            }
            if(ptr2 < version2.size() and version2[ptr2] == '.')
                ptr2++;
            if(ptr1 < version1.size() and version1[ptr1] == '.')
                ptr1++;
            prev1 = ptr1;
            prev2 = ptr2;
            
        }
        return res;
    }

    //--------------------------#167--------------------------------------------//
    // std::vector<int> num{-1, 0};
    // sh::showContainer(solution.twoSum_167(num, -1));
    std::vector<int> twoSum_167(std::vector<int>& numbers, int target) {
        std::vector<int> ans(2, 0);
        int l(0), r(numbers.size() - 1);
        while (l < r)   
        {
            if(numbers[l] + numbers[r] == target){
                ans[0] = ++l;
                ans[1] = ++r;
                break;
            } else if (numbers[l] + numbers[r] > target){
                r--;
            } else {
                l++;
            }
        }
        return ans;
    }
   
    //--------------------------#168--------------------------------------------//
    // sh::print(solution.convertToTitle_168(52));
    std::string convertToTitle_168(int columnNumber) {
        std::string ans;
        while (columnNumber != 0)
        {
            columnNumber--;
            int curr = columnNumber % 26;
            ans = (char('A' + curr)) + ans;
            columnNumber /= 26;
        }
        return ans;
    }

    //--------------------------#169--------------------------------------------//
    int majorityElement_169(std::vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) 
                candidate = num;
            
            if (num == candidate) 
                count++;
            else
                count--;
        }
        return candidate;
    }

    //--------------------------#171--------------------------------------------//
    // sh::print(solution.titleToNumber("ZY"));
    int titleToNumber(std::string columnTitle) {
        int ans(0);
        for(size_t i(0); i != columnTitle.size(); ++i){
            char curr = columnTitle[i] ;
            ans *= 26;
            ans += ++curr - 'A';
        }
        return ans;
    }

    //--------------------------#172--------------------------------------------//
    int trailingZeroes(int n) {
        int count = 0;
        while (n != 0) {
            int tmp = n / 5;
            count += tmp;
            n = tmp;
        }
        return count;
    }

    //--------------------------#175--------------------------------------------//
    // SELECT p.firstName, p.lastName, a.city, a.state
    // FROM Person p
    // left join Address a
    //     ON p.personId = a.personId;

    //--------------------------#176--------------------------------------------//
    // WITH highest_salary AS (
    //     SELECT MAX(salary) AS salary
    //     FROM Employee
    // )
    // SELECT MAX(salary) AS "SecondHighestSalary" 
    // FROM Employee
    // WHERE salary < (SELECT salary FROM highest_salary);
    // };

    //--------------------------#187--------------------------------------------//
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        if(s.size() < 10)
            return {};
        std::unordered_map<std::string, int> m;
        std::vector<std::string> ans;

        for(size_t i(0); i != s.size() - 9; ++i)
            m[s.substr(i, 10)]++;
        

        for(auto it = std::begin(m); it != std::end(m); ++it){
            if(it->second >= 2)
                ans.push_back(it->first);
        }
        return ans;
    }

    //--------------------------#189--------------------------------------------//
    // std::vector<int> v{1,2,3,4,5};
    // sh::showContainer(v);
    // solution.rotate_189(v, 3);
    // sh::showContainer(v);
    void rotate_189(std::vector<int>& nums, int k) {
        k = k % nums.size();
        if(k == 0)
            return;
        int swaped_pos(0), j(0);
        int nok = std::abs((int)nums.size() * k) / std::gcd(nums.size(), k);
        int n = nok / k;
        for(size_t i(0); i != nums.size() - 1; ++i){
            int pos = (swaped_pos + k) % nums.size();
            std::swap(nums[j], nums[pos]);
            swaped_pos = pos;
            if(--n == 0){
                ++j;
                ++swaped_pos;
                n = nok / k;
            }
        }
    }

    //--------------------------#190--------------------------------------------//
    uint32_t reverseBits_190(uint32_t n) {
        uint32_t ans(0);
        for(size_t i(0); i != 32; ++i){
            if((n >> i) % 2 != 0){
                ans |= (1 << 31 - i);
            } 
        }
        return ans;
    }

    //--------------------------#191--------------------------------------------//
    int hammingWeight_191(int n) {
        int ans(0);
        for(size_t i(0); i != 32; ++i){
            if((n >> i) % 2 == 1)
                ++ans;
        }
        return ans;
    }

    //--------------------------#198--------------------------------------------//
    // std::vector<int> v{2,7,9,3,1};
    // sh::print(solution.rob_198(v));
    int rob_198(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for(size_t i(2); i != nums.size(); ++i)
            dp[i] = std::max(dp[i-2] + nums[i], dp[i - 1]);
        
        
        return dp[nums.size() - 1];
    }

    //--------------------------#199--------------------------------------------//
    std::vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        std::vector<int> ans;
        std::queue<TreeNode*> q;
        q.push(root);

        TreeNode* curr;
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                curr = q.front();
                q.pop();

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);

                if(s == 0)
                    ans.push_back(curr->val);
            }
        }
        return ans;
    }

    //--------------------------#200--------------------------------------------//
    // std::vector<std::vector<char>> grid{
    //     {'1','1','0','0','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','1','0','0'},
    //     {'0','0','0','1','1'}
    // };
    // sh::print(solution.numIslands_200(grid));
    int numIslands_200(std::vector<std::vector<char>>& grid) {
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        int ans(0);
       
        for(size_t i(0); i != grid.size(); ++i){
            for(size_t j(0); j != grid[0].size(); ++j){
                if(!visited[i][j] and grid[i][j] == '1' ){
                    ++ans;
                    CheckIslad(grid, visited, {i, j});
                }
            }
        }   

        return ans;
    }
    void CheckIslad(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& visited, std::pair<int, int> start){
        std::queue<std::pair<int, int>> q;
        q.push(start);
        std::vector<std::pair<int, int>> SHIFTS{
            {-1, 0},
            { 1, 0},
            {0 ,-1},
            {0 , 1}
        };
        while (!q.empty())
        {   
            auto [x, y] = q.front();
            q.pop();
            visited[x][y] = true;

            for(size_t i(0); i != SHIFTS.size(); ++i){
                int x_ = x + SHIFTS[i].first;
                int y_ = y + SHIFTS[i].second;
                if(x_ >= 0 and x_ < grid.size() and y_ >= 0 and y_ < grid[0].size() and grid[x_][y_] == '1' and !visited[x_][y_]){
                    q.push({x_, y_});
                    visited[x_][y_] = true;
                }
            }
        }
    }

    //--------------------------#179--------------------------------------------//
    // std::vector<int> nums{3,30,34,5,9};
    // sh::print(solution.largestNumber_179(nums));
    std::string largestNumber_179(std::vector<int>& nums) {
        std::string ans;

        std::sort(std::begin(nums), std::end(nums),[](int a, int b){
            std::string a_ = std::to_string(a);
            std::string b_ = std::to_string(b);
            return (a_ + b_) > (b_ + a_);
        });
        if(nums[0] == 0)
            return "0";

        for(size_t i(0); i != nums.size(); ++i)
           ans.append(std::to_string(nums[i])); 
        return ans;
    }

    //--------------------------#151--------------------------------------------//
    // std::string str("a good example");
    // sh::print(solution.reverseWords_151(str));
    std::string reverseWords_151(std::string s) {
        std::string ans;
        ans.reserve(s.size());
        int end(0), j(0);
        while (s[j] == ' '){
            j++;
        }
        

        for(size_t i(s.size() - 1); i + 1 - j > 0; --i){
            if(s[i] == ' '){
                if(i != s.size() - 1)
                    ans.push_back(s[i]);
                while (i + 1 - j > 0 and s[i] == ' '){
                    --i;
                }
            }
            // word
            std::string tmp;
            if(s[i] != ' '){
                while (i + 1 - j > 0 and s[i] != ' '){
                    tmp.push_back(s[i]);
                    --i;
                }
                std::reverse(std::begin(tmp), std::end(tmp));
                ++i;
            }
            ans.append(tmp);

        }
        return ans;
    }

    //--------------------------#152--------------------------------------------//
    // std::vector<int> nums{2,3,-2,4};
    // solution.maxProduct_152(nums);
    int maxProduct_152(std::vector<int>& nums) {
        // int prod(1);
        // int result(INT_MIN);
        
        // for (int i = 0; i < nums.size(); i++) {
        //     prod *= nums[i];
        //     result = std::max(prod, result);
        //     if(prod == 0) 
        //         prod = 1;
        // }
        // prod = 1;
        
        // for (int i = nums.size() - 1; i >= 0; i--) {
        //     prod *=  nums[i];
        //     result = std::max(prod, result);
        //     if(prod == 0) 
        //         prod = 1;      
        // }
        // return result;

        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(nums[i] < 0){
                std::swap(maxi,mini);
            }
            maxi = std::max(nums[i],maxi*nums[i]);
            mini = std::min(nums[i],mini*nums[i]);
            ans = std::max(ans,maxi);
        }
        return ans;
    }

};

int main(){
    Solution solution;   
    Timer timer("LeetCode_200.cpp");
    
    
    
}
