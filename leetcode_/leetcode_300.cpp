﻿#include "ForLeetcode.h"
#include "show.h"
#include "TimeGuard.hpp"

    //--------------------------#211--------------------------------------------//
    // WordDictionary* wordDictionary = new WordDictionary();
    // wordDictionary->addWord("bad");
    // wordDictionary->addWord("dad");
    // wordDictionary->addWord("mad");
    // std::cout << std::boolalpha;
    // sh::print(wordDictionary->search("pad")); // return False
    // sh::print(wordDictionary->search("bad")); // return True
    // sh::print(wordDictionary->search(".ad")); // return True
    // sh::print(wordDictionary->search("b..")); // return True
class WordDictionary {
private:
    struct Vertex
    {
        std::unordered_map<char, std::shared_ptr<Vertex>> to;
        bool terminal = {false};
    };
    std::shared_ptr<Vertex> root;
public:
    WordDictionary() {
        root = std::make_shared<Vertex>();
    }
    
    void addWord(std::string word) {
        auto currVer = root;
        for (auto c : word)
        {
            if(!currVer->to.contains(c)){
                currVer->to.insert({c, std::make_shared<Vertex>()});
            }
            currVer = currVer->to[c];
        }
        currVer->terminal = true;
    }
    
    bool search(std::string word, std::shared_ptr<Vertex> root_ = nullptr) {
        std::shared_ptr<Vertex> currVer = root_ == nullptr ? root : root_;
        for (size_t i(0); i != word.size(); ++i)
        {
            if(word[i] == '.'){
                for(auto it = std::begin(currVer->to); it != std::end(currVer->to); ++it){
                    if(search(word.substr(i + 1, word.size() - i), it->second)){
                        return true;
                    }
                }
            }
            if(!currVer->to.contains(word[i])){
                return false;
            }
            currVer = currVer->to[word[i]];
        }
        return currVer->terminal;
    }
};

    //--------------------------#225--------------------------------------------//
    // MyStack* obj = new MyStack();
    // obj->push(4);
    // int param_2 = obj->pop();
    // int param_3 = obj->top();
    // bool param_4 = obj->empty();
class MyStack {
    std::queue<int> q;
public:
    MyStack() {    
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int s = q.size() - 1;
        int a;
        for(size_t i(0); i < q.size(); ++i){
            a = q.front();
            q.pop();
            if(s--){
                q.push(a);
            }
        }
        return a;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

    //--------------------------#232--------------------------------------------//
class MyQueue {
    std::stack<int> st;
    bool reverse = false;

    void ReverseSt(){
        std::stack<int> nst;
        while (!st.empty())
        {
            nst.push(st.top());
            st.pop();
        }
        std::swap(st, nst);
        reverse = !reverse;
    }
public:
    MyQueue() {}
    
    void push(int x) {
        if(reverse)
            ReverseSt();
        st.push(x);
    }
    
    int pop() {
        if(!reverse)
            ReverseSt();
        int x = st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        if(!reverse)
            ReverseSt();
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};


class Solution {
public:

    //--------------------------#201--------------------------------------------//
    int rangeBitwiseAnd_201(int left, int right) {
        int i = 0;
        while(left!=right){
            left=left>>1;
            right=right>>1;
            ++i;        
        }
        return left<<i;
    }

    //--------------------------#202--------------------------------------------//
    bool isHappy_202(int n) {
        std::unordered_set<int> visit;
        while (visit.find(n) == visit.end()) {
            visit.insert(n);
            n = getNextNumber(n);
            if (n == 1)
                return true;
        }
        return false;
    }
    int getNextNumber(int n) {
        int output = 0;
        while (n > 0) {
            int digit = n % 10;
            output += digit * digit;
            n = n / 10;
        }
        return output;
    }

    //--------------------------#203--------------------------------------------//
    // ListNode l1(6, new ListNode(2, new ListNode(6,(new ListNode(4, new ListNode(6))))));
    // sh::showList(&l1);
    // l1 = *solution.removeElements_203(&l1, 6);
    // sh::showList(&l1);
    ListNode* removeElements_203(ListNode* head, int val) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr)
        {
            if(curr->val == val){
                ListNode* next_el = curr->next;
                if(!prev){
                    head = next_el;
                    prev = nullptr;
                } else {
                    prev->next = next_el;
                }
                //delete curr;
                curr = next_el;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }

    //--------------------------#204--------------------------------------------//
    int countPrimes_204(int n) {
        int cnt = 0;
        std::vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                for (int j = i * 2; j < n; j = j + i) {
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }

    //--------------------------#205--------------------------------------------//
    // std::string s{"badc"}; 
    // std::string t{"baba"};
    // std::cout << std::boolalpha;
    // sh::print(solution.isIsomorphic_205(s, t));
    bool isIsomorphic_205(std::string s, std::string t) {
        if(s.size() != t.size())
            return false;

        std::unordered_map<char, char> convert;
        std::unordered_set<char> storage;
        for(size_t i(0); i != s.size(); ++i){
            if(!convert.contains(s[i])){
                if(!storage.contains(t[i])){
                    convert[s[i]] = t[i];
                    storage.insert(t[i]);
                } else {
                    return false;
                }
            }
                
            if(convert[s[i]] != t[i])
                return false;   
        }
        return true;
    }

    //--------------------------#206--------------------------------------------//
    // ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3,(new ListNode(4, new ListNode(5))))));
    // sh::showList(l1);
    // l1 = solution.reverseList_206(l1);
    // sh::showList(l1);
    ListNode* reverseList_206(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode *prev, *curr, *next;
        prev = nullptr;
        curr = head;
        
        while (curr)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    //--------------------------#208--------------------------------------------//
    // algo -> Trie.hpp and Trie.cpp

    //--------------------------#209--------------------------------------------//
    // std::vector<int> nums{2,3,1,2,4,3};
    // sh::print(solution.minSubArrayLen_209(7, nums));
    int minSubArrayLen_209(int target, std::vector<int>& nums) {
        int l(0), sum(0), len(INT_MAX);
        for(int i(0); i != nums.size(); ++i){
            sum += nums[i];
            if(sum >= target){
                len = std::min(len , i - l + 1);
                while(l != i and sum >= target){
                    sum -= nums[l++];
                    if(sum >= target)
                        len = std::min(len , i - l + 1);
                }
            }
        }
        return len == INT_MAX ? 0 : len;
    }

    //--------------------------#215--------------------------------------------//
    int findKthLargest_215(std::vector<int>& nums, int k) {
        std::sort(begin(nums), end(nums));
        return nums[nums.size() - k];
    }

    //--------------------------#213--------------------------------------------//
    // std::vector<int> nums{1,3,1,3,100};
    // sh::print(solution.rob_213(nums));
    int rob_213(std::vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return std::max(nums[0], nums[1]);
        }

        std::vector<int> dp1(nums.size() - 1, 0);
        std::vector<int> dp2(nums.size() - 1, 0);
        dp1[0] = nums[0];
        dp1[1] = std::max(dp1[0], nums[1]); 
        dp2[0] = nums[1];
        dp2[1] = std::max(dp2[0], nums[2]);
        for(size_t i(2); i < nums.size() - 1; ++i){
            dp1[i] = std::max(nums[i] + dp1[i - 2], dp1[i - 1]);
            dp2[i] = std::max(nums[i + 1] + dp2[i - 2], dp2[i - 1]);
        }
        return std::max(dp1.back(), dp2.back());
    }

    //--------------------------#217--------------------------------------------//
    // std::vector<int> nums{1,2,3,1};
    // sh::print(solution.containsDuplicate_217(nums));
    bool containsDuplicate_217(std::vector<int>& nums) {
        std::unordered_map<int, int> fr;
        for(size_t i(0); i != nums.size(); ++i){
            int val = ++fr[nums[i]];
            if(val > 1)
                return true;
        }
        return false;
    }

    //--------------------------#219--------------------------------------------//
    bool containsNearbyDuplicate_219(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> fr;
        for(int i = 0; i != nums.size(); ++i){
            if(fr.count(nums[i]) and i - fr[nums[i]] <= k)
                    return true;
            fr[nums[i]] = i; 
        }
        return false; 
    }

    //--------------------------#220--------------------------------------------//
    // std::vector<int> nums{10,100,10,90,11,9};
    // std::cout << std::boolalpha;
    // sh::print(solution.containsNearbyAlmostDuplicate(nums, 1, 2));
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
        std::multiset<int> fr;
        for(int i = 0; i != nums.size(); ++i){
            auto lb = fr.lower_bound(nums[i] - valueDiff);
            if(lb != fr.end() and *lb - nums[i] <= valueDiff)
                return true;
            fr.insert(nums[i]); 
            if(fr.size() > indexDiff)
                fr.erase(nums[i - indexDiff]);
        }
        return false; 
    }

    //--------------------------#221--------------------------------------------//
    // std::vector<std::vector<char>> matrix{
    //     {'1','1','1','1','1'},
    //     {'0','1','1','1','1'},
    //     {'1','1','1','1','1'},
    //     {'1','1','1','1','1'},
    //     {'1','1','1','1','1'}
    // };
    // sh::print(solution.maximalSquare_221(matrix));
    int maximalSquare_221(std::vector<std::vector<char>>& matrix) {
        std::vector<std::vector<int>> dp(matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0));
        int res(0);
        for(size_t i(1); i != matrix.size() + 1; ++i){
            for(size_t j(1); j != matrix[0].size() + 1; ++j){
                int curr_val = matrix[i - 1][j - 1] - '0';
                if(curr_val){
                    curr_val = std::min({dp[i - 1][j], dp[i][j - 1], dp[i-1][j-1]}) + 1;
                }
                dp[i][j] = curr_val;
                res = std::max(res, curr_val);
            } 
        }
        return res * res;
    }

    //--------------------------#222--------------------------------------------//
    int countNodes_222(TreeNode* root) {
        int h = countTreeHeight( root );
        if(h == 0)
            return 0;

        if( countTreeHeight(root->right) == (h-1) )
            return (1 << (h-1)) + countNodes_222(root->right);   
        else
            return (1 << (h-2)) + countNodes_222(root->left); 
    }
    inline int countTreeHeight( TreeNode* node){
        if(!node)
            return 0;
        return 1 + countTreeHeight( node->left );
    }

    //--------------------------#223--------------------------------------------//
    // sh::print(solution.computeArea_223(-3, 0, 3, 4, 0, -1, 9, 2));
    int computeArea_223(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x = GetSide(ax1, ax2, bx1, bx2);
        int y = GetSide(ay1, ay2, by1, by2);
        int S1 = (ax2 - ax1) * (ay2 - ay1);
        int S2 = (bx2 - bx1) * (by2 - by1);
        return  S1 + S2 - x * y;
    }
    int GetSide(int ax1, int ax2, int bx1, int bx2){
        if(ax1 >= bx1 and ax1 <= bx2 and ax2 >= bx1 and ax2 <= bx2)
            return ax2 - ax1;
        if(ax1 <= bx1 and ax1 <= bx2 and ax2 >= bx1 and ax2 >= bx2)
            return bx2 - bx1;
        if(ax1 >= bx1 and ax1 <= bx2)
            return bx2 - ax1;
        if(ax2 >= bx1 and ax2 <= bx2)
            return ax2 - bx1;
        return 0;
    }

    //--------------------------#226--------------------------------------------//
    TreeNode* invertTree_226(TreeNode* root) {
        InvTree(root); 
        return root;
    }
    void InvTree(TreeNode* root){
        if(!root)
            return;
        
        std::swap(root->left, root->right);
        InvTree(root->left);
        InvTree(root->right);
    }

    //--------------------------#228--------------------------------------------//
    // std::vector<int> nums{0,1,2,4,5,7};
    // sh::showContainer(solution.summaryRanges_228(nums));
    std::vector<std::string> summaryRanges_228(std::vector<int>& nums) {
        std::vector<std::string> res;
        int l(0);
        for(size_t i(0); i != nums.size(); ++i){
            if(!(i != nums.size() - 1 and nums[i] == nums[i + 1] - 1)){
                if(l == i){
                    res.push_back(std::to_string(nums[i]));
                } else {
                    res.push_back(std::to_string(nums[l]) + "->" + std::to_string(nums[i]));
                }
                l = i + 1;
            }
        }
        return res; 
    }

    //--------------------------#229--------------------------------------------//
    std::vector<int> majorityElement_229(std::vector<int>& nums) {
        int num1 = INT_MIN, num2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            else if(num2 == element){
                count2++;
            }
            else if(count1 == 0){
                num1 = element;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = element;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        std::vector<int> output;
        int countMajority = nums.size()/3;
        count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            if(num2 == element){
                count2++;
            }
        }
        if(count1 > countMajority){
            output.push_back(num1);
        }
        if(count2 > countMajority){
            output.push_back(num2);
        }
        return output;
    }

    //--------------------------#230--------------------------------------------//
    // TreeNode* root = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4));
    // sh::print(solution.kthSmallest_230(root, 1));
    int kthSmallest_230(TreeNode* root, int k) {
        int min(INT_MAX), iter(0);
        KSmallestHelp(root, k, min, iter);
        return min;
    }
    void KSmallestHelp(TreeNode* root, int k, int& min, int& iter){
        if(!root or iter == k)
            return;

        KSmallestHelp(root->left, k, min, iter);
        if(iter != k){
            min = root->val;
            ++iter;
        } else {
            return;
        }
        KSmallestHelp(root->right, k, min, iter);
    }

    //--------------------------#231--------------------------------------------//
    bool isPowerOfTwo_231(int n) {
        if(n <= 0)
            return false;
        return  !(n & (n - 1));
    }

    //--------------------------#234--------------------------------------------//
    // ListNode* l1 = new ListNode(1, new ListNode(0, new ListNode(0)));
    // sh::showList(l1);
    // sh::print(solution.isPalindrome_234(l1));
    bool isPalindrome_234(ListNode* head) {
        std::vector<int> nums;
        ListNode *slow = head, *fast = head;
        while (fast != nullptr and fast->next != nullptr){
            nums.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast)
            slow = slow->next;
        
        int i(nums.size() - 1);
        while (slow){
            if(nums[i--] != slow->val)
                return false;
            slow = slow->next;
        }
        return true;
    }

    //--------------------------#235--------------------------------------------//
    TreeNode* lowestCommonAncestor_235(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val and root->val > q->val){
            return lowestCommonAncestor_235(root->left, p, q);
        }
        if(root->val < p->val and root->val < q->val){
            return lowestCommonAncestor_235(root->right, p, q);
        }
        return root;
    }

    //--------------------------#236--------------------------------------------//
    TreeNode* lowestCommonAncestor_236(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor_236(root->left, p, q);
        TreeNode* right = lowestCommonAncestor_236(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
  
    //--------------------------#237--------------------------------------------//
    void deleteNode_237(ListNode* node) {
        ListNode* to_del = node->next;
        *node = *to_del;
        delete to_del;
    }

    //--------------------------#238--------------------------------------------//
    std::vector<int> productExceptSelf_238(std::vector<int>& nums) {
        std::vector<int> ans(nums.size(), 1);
        int pref(1), suff(1);
        for(size_t i(0); i != nums.size() - 1; ++i){
            pref *= nums[i];
            suff *= nums[nums.size() - 1 - i];
            ans[i + 1] *= pref;
            ans[nums.size() - 2 - i] *= suff;
        }        
        return ans;
    }

    //--------------------------#240--------------------------------------------//
    bool searchMatrix_240(std::vector<std::vector<int>>& matrix, int target) {
        int row(0), col(matrix[0].size() - 1);
        while (row < matrix.size() and col >= 0){
            if(matrix[row][col] == target)
                return true;
            matrix[row][col] > target ? --col : ++row;
        }
        return false;
    }

    //--------------------------#242--------------------------------------------//
    bool isAnagram_242(std::string s, std::string t) {
        if(s.size() != t.size()){
            return false;
        }

        std::map<char, int> rate;
        for(size_t i(0); i != s.size(); ++i){
            rate[s[i]]++;
            rate[t[i]]--;
        }
        for(const auto& x: rate){
            if(x.second != 0)
                return false;
        }
        return true;
    }

    //--------------------------#257--------------------------------------------//
    // TreeNode* root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3));
    // sh::showContainer(solution.binaryTreePaths_257(root));
    std::vector<std::string> binaryTreePaths_257(TreeNode* root) {
        std::vector<std::string> res; 
        std::vector<int> curr;
        GetPathsToLeafs(root, res, curr);
        return res;
    }
    void GetPathsToLeafs(TreeNode* root, std::vector<std::string>& res, std::vector<int>& curr){
        if(!root)
            return;
        if(!root->left and !root->right){
            curr.push_back(root->val);
            res.push_back(BuildPath(curr));
            curr.pop_back();
            return;
        }

        curr.push_back(root->val);
        GetPathsToLeafs(root->left, res, curr);
        GetPathsToLeafs(root->right, res, curr);
        curr.pop_back();
    }
    std::string BuildPath(const std::vector<int>& curr){
        std::string s;
        s.reserve(curr.size()*3);
        for(size_t i(0); i != curr.size(); ++i){
            if(i != 0)
                s.append("->");
            s.append(std::to_string(curr[i]));
        }
        return std::move(s);
    }

    //--------------------------#258--------------------------------------------//
    // sh::print(solution.addDigits_258(38));
    int addDigits_258(int num) {
        int sum(0);
        while (num >= 10)
        {
            while (num)
            {
                sum += num % 10;
                num /= 10;
                
            }
            num = sum;
            sum = 0;
        }
        return num;
    }

    //--------------------------#260--------------------------------------------//
    std::vector<int> singleNumber_260(std::vector<int>& nums) {
        int firstXorSec(0), mask(1), first(0);
        for (auto &num: nums) 
            firstXorSec ^= num;
        
        while (!(firstXorSec & mask)) 
            mask <<= 1;
        
        for (auto &num: nums){
            if (num & mask) 
                first ^= num;
        }

        return {first, firstXorSec ^ first};
    }

    //--------------------------#263--------------------------------------------//
    bool isUgly_263(int n) 
    {
        if (n <= 0) return false;
        while(n > 1)
        {
            if (n % 2 == 0) n = n / 2;
            else if (n % 3 == 0) n = n / 3;
            else if (n % 5 == 0) n = n / 5;
            else break;
        }
        return (n == 1);
    }

    //--------------------------#264--------------------------------------------//
    int nthUglyNumber_264(int n) {
        if(n <= 0) return false; 
        if(n == 1) return true; 
        int t2 = 0, t3 = 0, t5 = 0; 
        std::vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = std::min(k[t2]*2,std::min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++; 
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }

    //--------------------------#268--------------------------------------------//
    // std::vector<int> nums{0,1};
    // sh::print(solution.missingNumber_268(nums));
    int missingNumber_268(std::vector<int>& nums) {
        int total = (1. + nums.size()) / 2 * nums.size();
        int sum = std::accumulate(std::begin(nums), std::end(nums),0);
        return total - sum;
    }

    //--------------------------#300--------------------------------------------//
    // std::vector<int> nums{0,1,0,3,2,3};
    // sh::print(solution.lengthOfLIS_300(nums));
    int lengthOfLIS_300(std::vector<int>& nums) {
        std::map<int, std::set<int>> hist;
        hist.insert({1,{nums[0]}});
        for(size_t i(1); i != nums.size(); ++i){
            for(auto it = std::rbegin(hist); it != std::rend(hist); ++it){
                int len =it->first;
                auto& curr_set = it->second;

                auto f = std::lower_bound(std::begin(curr_set), std::end(curr_set), nums[i]);
                if(f != std::begin(curr_set)){
                    hist[++len] = {nums[i]};
                    break;
                } else if(*it == *std::begin(hist)){
                    hist[1].insert(nums[i]);
                }
            }
        }
        return hist.rbegin()->first;
        // std::vector<int> res;
        // for(int i=0; i<nums.size(); i++) {
        //     auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        //     if(it==res.end()) res.push_back(nums[i]);
        //     else *it = nums[i];
        // }
        // return res.size();
    }

    //--------------------------#299--------------------------------------------//
    std::string getHint(std::string secret, std::string guess) {
        std::unordered_map<char, int> s;
        std::unordered_map<char, int> g;
        int x(0), y(0);
        for(size_t i(0); i != secret.size(); ++i){
            if(secret[i] == guess[i]){
                ++x;
            } else {
                ++s[secret[i]];
                ++g[guess[i]];
            }
        }
        for(auto it = std::begin(s); it != std::end(s); ++it){
            auto f = g.find(it->first);
            if(f != g.end()){
                y += std::min(it->second, f->second);
            }
        }
        return std::to_string(x) + "A" + std::to_string(y) + "B";
    }

    //--------------------------#290--------------------------------------------//
    // std::string s("dog cat cat dog");
    // std::cout << std::boolalpha;
    // sh::print(solution.wordPattern("abba", s));
    bool wordPattern(std::string pattern, std::string s) {
        std::vector<std::string> words = Split(s, " ");
        if(words.size() != pattern.size())
            return false;
        std::unordered_map<char, std::string> m;
        std::set<std::string> set;
        int i(0);
        for(char ch : pattern){
            auto word = m.find(ch);
            if(word != m.end()){
                if(word->second != words[i])
                    return false;
            } else {
                if(set.contains(words[i]))
                    return false;
                m.insert({ch, words[i]});
                set.insert(words[i]);
            }
            ++i;
        }
        return true;
    }
    std::vector<std::string> Split(const std::string& str, std::string delimiter){
        std::vector<std::string> res;
        int pos(0);
        int ds = delimiter.size();
        for(size_t i(0); i != str.size(); ++i){
            if(str.substr(i, ds) == delimiter ){
                res.push_back(str.substr(pos, i - pos));
                pos = i + ds;
                i += ds - 1;
            }else if(i == str.size() - 1){
                res.push_back(str.substr(pos));
            }
        }
        return res;
    }
};


int main(){
    Solution solution;   
    TimeGuard timer("LeetCode_300.cpp");

    


}