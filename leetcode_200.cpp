#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

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
    TreeNode* help_106(
        std::vector<int>& postorder,
        std::vector<int>& inorder, 
        std::unordered_map<int, int>& pos, 
        int l, int r, int& ind, bool st)
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
    ListNode* sortList(ListNode* head) {
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
};

int main(){
    Solution solution;   
    Timer timer("LeetCode_200.cpp");
    

}
