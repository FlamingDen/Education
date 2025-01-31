#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

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
    int countNodes(TreeNode* root) {
        int h = countTreeHeight( root );
        if(h == 0)
            return 0;

        if( countTreeHeight(root->right) == (h-1) )
            return (1 << (h-1)) + countNodes(root->right);   
        else
            return (1 << (h-2)) + countNodes(root->left); 
    }
    inline int countTreeHeight( TreeNode* node){
        if(!node)
            return 0;
        return 1 + countTreeHeight( node->left );
    }
};

int main(){
    Solution solution;   
    Timer timer("LeetCode_300.cpp");
    
    
    
}