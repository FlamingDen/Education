#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <array>
#include <algorithm>
#include <regex>
#include <queue>
#include <math.h>
//#include <functional>
#include <numeric>

 
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template<typename T>
struct TreeNode{
    T val;
    TreeNode* left = nullptr;
    TreeNode* rigth = nullptr;
    TreeNode() : val(0){}
    TreeNode(int v) : val(v){}
    TreeNode(int v, TreeNode* l, TreeNode* r) :  val(v), left(l), rigth(r){}
};

class ShowSmt{
public:
    template<typename T>
    void show_vec(std::vector<T> v){
        std::cout <<'[';
        for (int i = 0; i < v.size(); i++)
        {
            if(i == v.size() - 1){
                std::cout << v[i] <<']'<<  std::endl;
                break;
            }
            std::cout << v[i] << ", ";
        }
    }

    template<typename T>
    void show_vec_vec(std::vector<std::vector<T>> v){
        std::cout <<'[';
        for (int i = 0; i < v.size(); i++)
        {
            if(i == v.size() - 1){
                show_vec(v[i]);
                std::cout << ']' << std::endl;
                break;
            }
            show_vec(v[i]);
            std::cout << ",";
        }
    }



    void showList(ListNode* l){
        while (l != nullptr){
            std::cout << l->val << " -> ";
            l = l->next; 
        }
        std::cout << "nullptr" <<  std::endl;
    }
    
    template<typename T>
    void showTree(TreeNode<T>* root){
        if(root == nullptr)
            return;
        showTree(root->left);
        showTree(root->rigth);
        std::cout << root->val << ", ";
    }

    // TreeNode
    // TreeNode<int>* root = new TreeNode<int>(4, new TreeNode<int>(5, new TreeNode<int>(12), new TreeNode<int>(11)), new TreeNode<int>(10, new TreeNode<int>(22), new TreeNode<int>(44)));
    // sh.showTree(root);
    // std::cout << std::endl;
    // sh.showTreeLevel(root);
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
                q.push(temp->rigth);
        }
        std::cout << std::endl;
    }
};

class Solution {
public:
    //--------------------------#2----------------------------------------------//
    // // --2
    // ListNode l1(9, (new ListNode(9, (new ListNode(9,(new ListNode(9,(new ListNode(9,(new ListNode(9,(new ListNode(9,(new ListNode(9)))))))))))))));
    // ListNode l2(9, new ListNode(9, new ListNode(9,(new ListNode(9)))));
    // sh.showList(&l1);
    // sh.showList(&l2);
    // solution.addTwoNumbers_2(&l1, &l2);
    ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2) {
        /*ListNode* ans = new ListNode();
        ListNode* head = ans;
        ListNode* prev;
        int transfer(0);
        while (l1 != nullptr or l2 != nullptr or transfer != 0)
        {
            ans->next = new ListNode();
            if(l1 == nullptr and l2 == nullptr and transfer != 0){
                ans->val = transfer--;

            }else if(l1 != nullptr and l2 != nullptr){
                ans->val = (l1->val + l2->val + transfer) % 10 ;
                transfer = (l1->val + l2->val + transfer) / 10;
                
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1 != nullptr and l2 == nullptr){
                ans->val = (l1->val + transfer) % 10;
                transfer = (l1->val + transfer) / 10;
                
                l1 = l1->next;
            }else if(l1 == nullptr and l2 != nullptr){
                ans->val = (l2->val + transfer) % 10;
                transfer = (l2->val + transfer) / 10;

                l2 = l2->next;
            }
            prev = ans;
            ans = ans->next;
        }
        prev->next = nullptr;
        prev = nullptr;
        ans  = nullptr;
        return head;*/
        int sum = 0;
        ListNode *l3 = nullptr;
        ListNode **node = &l3;
        while(l1 != NULL|| l2!= NULL||sum > 0)
        {
            if(l1 != NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            (*node)=new ListNode(sum%10);
            sum /= 10;
            node=&((*node)->next);
        }        
        return l3;
    }

    //--------------------------#3----------------------------------------------//
    // --3
    // std::cout << solution.lengthOfLongestSubstring_3("pwwkew") << std::endl;
    int lengthOfLongestSubstring_3(std::string s) {
        // std::map<char, int> chars;
        // int len(0), i(0);
        // int curr_len(0);
        // for(const auto &a: s){ 
        //     if(!chars.contains(a)){
        //         chars.insert(std::pair<char,int>(a, i++));
        //         curr_len++;
        //         if(len < curr_len)
        //             len = curr_len; 
        //         continue;
        //     }
        //     curr_len = 0;
        //     for(auto entry: chars){
        //         if(entry.first != a){
        //             chars.erase(a);
        //             continue;
        //         } 
        //         break;
        //     }
        //     //chars[a] = i++;
        //     chars.insert(std::pair<char,int>(a, i++));
        // }
        // return chars.size();
        int left = 0;
        int maxLength = 0;
        std::unordered_set<char> charSet;

        for (int right = 0; right < s.length(); right++) {
            while (charSet.contains(s[right])) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }

    //--------------------------#5----------------------------------------------//
    // // --5
    // std::string str = "gccghj";
    // std::cout << solution.longestPalindrome_5(str) << std::endl;
    std::string longestPalindrome_5(std::string s) {
        /*int n = s.size();
        std::vector<std::vector<bool>> m(n,std::vector<bool>(n));
        int l(0), r(0);

        // init
        for(int i(0); i < n - 1; i++){
            m[i][i] = true;
            if(s[i] == s[i+1]){
                m[i][i+1] = true;
                l = i;
                r = i+1;
            }
        }
        m[n-1][n-1] = true;

        // solution
        for (int len(2); len < n; len++){
            for (int i(0); i < n - len ; i++){
                if(m[i+1][i + len - 1] && (s[i] == s[i+len])){
                    m[i][i + len] = true;
                    l = i;
                    r = i + len;
                }       
            }
        }
        return s.substr(l,r - l + 1);*/
        std::string ans = "";

        for (int i = 0; i < s.size(); i++) {
            std::string odd = expand_5(i, i, s);
            if (odd.size() > ans.size()) {
                ans = odd;
            }

            std::string even = expand_5(i, i + 1, s);
            if (even.size() > ans.size()) {
                ans = even;
            }
        }

        return ans;
    }

    //--------------------------#7----------------------------------------------//
    // // --7
    // std::cout << solution.reverse_7(96463243) << std::endl;
    int reverse_7(int x) {
        int ans(0), i(0);
        while(x != 0){
            if(ans >= INT_MAX/10)
                return 0;
            ans *= 10;
            ans += (x % 10);
            x /= 10;
            i++;
        }
        return ans;
    }

    //--------------------------#9----------------------------------------------//
    // // --9
    // std::cout << std::boolalpha << solution.isPalindrome_9(12321) << std::endl;
    bool isPalindrome_9(int x) {
        std::string str = std::to_string(x);
        int l(0), r(str.size()-1);
        while(l < r){
            if(str[l] == str[r]){
                l++;
                r--;
                continue;
            }
            return false;
        }
        return true; 
    }

    //--------------------------#11---------------------------------------------//
    // // --11
    // std::vector<int> vec{1,1,1,1,8,1,1,1,1,1,1,1,1,1};
    // std::cout << solution.maxArea_11(vec) << std::endl;
    int maxArea_11(std::vector<int>& h) {
        int l(0), r(h.size()-1), maxArea(0), curr_h;
        while(l < r){
            curr_h = std::min(h[l], h[r]);
            maxArea = std::max(maxArea, curr_h * (r - l));
            h[l] > h[r] ? r-- : h[l] < h[r] ? l++: r-- , l++;
        }
        return maxArea;
    }

    //--------------------------#8----------------------------------------------//
    // // --8
    // std::cout << solution.myAtoi_8("1337c0d3") << std::endl;
    int myAtoi_8(std::string s) {
        int ans(0);

        std::string number;
        std::smatch res;
        const std::regex reg_valid(R"((^\s*)([-+]?[0-9]+))");

        if(std::regex_search(s, res, reg_valid)){
            number = res[2];
            int start;
            int sign;
            if(number[0] == '-'){
                sign = -1;
                start = 1;
            } else if (number[0] == '+') {
                sign = 1;
                start = 1;
            } else {
                sign = 1;
                start = 0;
            }
            for (int i(start); i < number.size(); i++)
            {
                int pop = (number[i] - 48);
                if((ans > INT_MAX / 10) or ((ans == INT_MAX / 10) and ((sign == 1 and pop > 7) or (sign == -1 and pop > 8)))){
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                ans = ans * 10 + pop; 
            }
            ans *= sign;
        }
        return ans;
    }

    //--------------------------#6----------------------------------------------//
    // // --6
    // std::cout << solution.convert_6("PAYPALISHIRING", 4) << std::endl;
    std::string convert_6(std::string s, int numRows) {
        std::string ans;
        ans.reserve(s.size()-1);
        if (numRows == 1)
            return s;

        int step(0);
        bool rotation(true);
        for(int i(0); i < numRows; i++){
            for (int j(i); j < s.size();){
                ans += (s[j]);
                rotation = (rotation ? false : true);
                step = (!rotation ? ((numRows - 1) - (i % (numRows - 1))) * 2 : ((numRows - 1) - ((numRows - i - 1) % (numRows - 1))) * 2);
                j += step;
            }
            rotation = true;
        }
        return ans;
    }

    //--------------------------#15---------------------------------------------//
    // std::vector<int> vec{-3,4,8,1,-4,7,5,3};
    // solution.threeSum_15(vec);
    std::vector<std::vector<int>> threeSum_15(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());

        int l,r;
        for(int i(0); i < nums.size() - 2; i++){
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            l = i + 1;
            r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (nums[l] == nums[l-1] && l < r) {
                        l++;
                    }
                    continue;
                }
                if(sum > 0)
                    r--;
                if(sum < 0)
                    l++; 
            }
        }
        return ans;
    }

    //--------------------------#4----------------------------------------------//
    // // --4
    // std::vector<int> a{};
    // std::vector<int> b{1};
    // std::cout << solution.findMedianSortedArrays_4(a, b) << std::endl;
    double findMedianSortedArrays_4(std::vector<int>& nums1, std::vector<int>& nums2) {
        int l(0) , r(0);
        int curr = INT_MIN, prev;
        int len = (nums1.size() + nums2.size()) / 2 + 1;
        for(int i(0); i <  len; i++){
            if (l < nums1.size() && r < nums2.size()){
                if(nums1[l] > nums2[r]){
                    prev = curr;
                    curr = nums2[r];
                    r++;
                    continue;
                }
                if(nums1[l] <= nums2[r]){
                    prev = curr;
                    curr = nums1[l];
                    l++;
                } 
            }else if(l < nums1.size()){
                prev = curr;
                curr = nums1[l];
                l++;
            }else if(r < nums2.size()){
                prev = curr;
                curr = nums2[r];
                r++;
            }
        }
        if((nums1.size() + nums2.size()) % 2 == 1 )
            return curr;
        return (curr + prev) / 2.;
    }

    //--------------------------#17---------------------------------------------//
    // // --17
    // std::vector<std::string> str = solution.letterCombinations_17("23");
    // for (auto &i : str)
    //     std::cout << i << ", ";
    std::vector<std::string> letterCombinations_17(std::string digits) {
        std::vector<std::string> ans;
        std::vector<std::string> vec_str;
        int start;
        std::string temp("");
        if(digits.size() == 0)
            return {};

        for(const auto &d: digits){
            start = 'a' +  (d - '2') * 3;
            if (d  == '8' || d == '9')
                start++;
            temp.push_back(start);
            temp.push_back(start + 1);
            temp.push_back(start + 2);    
            if ((d == '7') || (d == '9'))
                temp.push_back(start + 3);
            
            vec_str.push_back(temp);
            temp.clear();
        }
        if(digits.size() == 1){
            for(const auto &t: vec_str[0])
                ans.push_back({t});
            return ans;
        }
        
        int j(0);
        solve_17(ans, vec_str, temp, j);
        return ans;
    }

    //--------------------------#19---------------------------------------------//
    // // --19
    // ListNode* l1 = new ListNode(1, (new ListNode(2, (new ListNode(3,(new ListNode(4,(new ListNode(5,(new ListNode(6,(new ListNode(7,(new ListNode(8)))))))))))))));
    // sh.showList(l1);
    // l1 = solution.removeNthFromEnd_19(l1, 8);
    // l1 = solution.removeNthFromEnd_19(l1, 6);
    // sh.showList(l1);
    ListNode* removeNthFromEnd_19(ListNode* head, int n) {
        ListNode* h = head;
        ListNode* prev = h;
        ListNode* next_node = h;
        ListNode* to_del;

        int i(0);
        while (h != nullptr)
        {
            if(i <= n){
                i++;
                h = h->next;
                continue;
            }
            prev = prev->next;
            h = h->next;
            i++;
        }
        if (i == n){
            to_del = head;
            head = head->next;
            to_del->next = nullptr;
            delete to_del;

            return head; 
        }

        next_node = prev->next->next;
        to_del = prev->next;
        prev->next = next_node;
        
        to_del->next = nullptr;
        delete to_del;
        
        return head;
    }

    //--------------------------#24---------------------------------------------//
    // // --24
    // ListNode* l1 = new ListNode(1, (new ListNode(2, (new ListNode(3,(new ListNode(4,(new ListNode(5,(new ListNode(6,(new ListNode(7,(new ListNode(8)))))))))))))));
    // ListNode* l2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    // sh.showList(l2);
    // l2 = solution.swapPairs_24(l2);
    // sh.showList(l2);
    // sh.showList(l1);
    // l1 = solution.swapPairs_24(l1);
    // sh.showList(l1);
    ListNode* swapPairs_24(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* next_pair;
        ListNode* first = head;
        ListNode* second = head->next;
        head = second;

        while (second != nullptr)
        {
            next_pair = second->next;

            second->next = first;
            first->next =  (next_pair == nullptr ? nullptr : next_pair->next == nullptr ? next_pair : next_pair->next);
            
            first = next_pair;
            second = next_pair != nullptr ? next_pair->next: nullptr;
        }
        return head;
    }

    //--------------------------#23---------------------------------------------//
    // // -- 23
    // ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    // ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    // ListNode* l3 = new ListNode(2, new ListNode(6));
    // sh.showList(l1);
    // sh.showList(l2);
    // sh.showList(l3);
    // std::vector<ListNode*> list = {l1, l2, l3};
    // ListNode* l4 = solution.mergeKLists_23(list);
    // sh.showList(l4);
    ListNode* mergeKLists_23(std::vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return {};
        if(lists.size() == 1)
            return lists[0];

        ListNode* ans =new ListNode(-999);
        ListNode* curr_el = ans;
        int j(0);

        while(true){
            ListNode* next_el = lists[0];
            j = 0;
            for(const auto &t: lists){
                if(t != nullptr){
                    next_el = t;
                    break;
                }
                j++;
            }
            if(next_el == nullptr)
                break;
            
            for(int i(1); i < lists.size(); i++){
                if(lists[i] == nullptr)
                    continue;
                if(next_el->val > lists[i]->val){
                    next_el = lists[i];
                    j = i;
                }
            }
            curr_el->next = next_el;
            curr_el = curr_el->next;
            lists[j] = lists[j]->next;

        }
        return ans->next;
    }

    //--------------------------#31---------------------------------------------//
    // // --31
    // std::vector<int> vec{2,3,1,3,3};
    // sh.show_vec(vec);
    // solution.nextPermutation_31(vec);
    // sh.show_vec(vec);
    void nextPermutation_31(std::vector<int>& nums) {
        int l = nums.size() - 2, r = nums.size() - 1;
        int i(0);
        for(; i < nums.size() - 1; i++){
            if(nums[r] > nums[l]){
                if(i == 0){
                    swap(nums, r, l);
                    return;
                } 
                break;
            }
            if(nums[r] <= nums[l]){
                l--;
                r--; 
            }
        }
        if(i == nums.size() - 1){
            std::reverse(nums.begin(), nums.end());
            return;
        }

        int to_swap = r; // min
        for(int j(r); j < nums.size() ; j++){
            if ((nums[j] <= nums[to_swap]) and nums[j] > nums[l])
                to_swap = j;
        }
        swap(nums, l, to_swap);
        l++;
        std::reverse(nums.begin() + l, nums.end());
    }

    //--------------------------#34---------------------------------------------//
    // --34
    // std::vector<int> vec{1,2};
    // sh.show_vec(vec);
    // sh.show_vec(solution.searchRange_34(vec,2));
    std::vector<int> searchRange_34(std::vector<int>& nums, int target) {
        return {binarySearch_l(nums, target), binarySearch_r(nums, target)};
    }

    //--------------------------#34---------------------------------------------//
    // --33
    // std::vector<int> vec{4,5,6,7,0,1,2};
    // sh.show_vec(vec);
    // std::cout << solution.search_33(vec,0);
    int search_33(std::vector<int>& nums, int target) {
        int gap = binarySearchGap(nums);
        if(gap == -1)
            return binarySearch(nums, target);
        
        int v1 = binarySearchRange(nums, target, 0, gap - 1);
        int v2 = binarySearchRange(nums, target, gap, nums.size() - 1);
        return std::max(v1, v2);
    }

    //--------------------------#36---------------------------------------------//
    // // --36
    // std::vector<std::vector<char>> board =
    // {{'.','.','4', '.','.','.', '6','3','.'},
    // {'.','.','.', '.','.','.', '.','.','.'},
    // {'5','.','.', '.','.','.', '.','9','.'},
    // {'.','.','.', '5','6','.', '.','.','.'},
    // {'4','.','3', '.','.','.', '.','.','1'},
    // {'.','.','.', '7','.','.', '.','.','.'},
    // {'.','.','.', '5','.','.', '.','.','.'},
    // {'.','.','.', '.','.','.', '.','.','.'},
    // {'.','.','.', '.','.','.', '.','.','.'}};
    // std::cout <<  std::boolalpha << solution.isValidSudoku_36(board);
    bool isValidSudoku_36(std::vector<std::vector<char>>& board) {
        bool row = rowValid(board);
        bool col = collValid(board);
        bool sq = squareValid(board);
        if(row && col && sq)
            return true;
        return false;    
    }

    //--------------------------#38---------------------------------------------//
    // --38
    // std::cout << solution.countAndSay_38(5) << std::endl;
    std::string countAndSay_38(int n) {
        return RLE(n);
    }
    std::string RLE(int n){
        if(n == 1)
            return "1";
        if(n == 2)
            return "11";

        std::string curr = RLE(n-1);
        std::string ans("");
        ans.reserve(curr.size());
        int count(1);
        char h = curr[0]; 
        for(int i(1); i < curr.size(); i++){
            if(h != curr[i]){
                ans += std::to_string(count) + h;
                count = 1;
                h = curr[i];
            }else{
                count++;
            }
                

            if(i == curr.size() - 1){
                ans += std::to_string(count) + h;
            }
        }
        return ans;
    }

    //--------------------------#41---------------------------------------------//
    // std::vector<int> vec{1,1};
    // sh.show_vec(vec);
    // std::cout << solution.firstMissingPositive_41(vec) << std::endl;
    int firstMissingPositive_41(std::vector<int>& nums) {
        int index;
        for (int i(0); i < nums.size(); i++)
        {
            index = nums[i] - 1;
            if(index >= 0 and index < nums.size() and index != i and nums[index] != nums[i]){
                swap(nums,index, i);
                i--;
            }  
        }
        for (int i(0); i < nums.size(); i++)
        {
            if(nums[i] != i+1){
                return i + 1;
            }
        }
        return nums.size() + 1;
        
    }

    //--------------------------#45---------------------------------------------//
    // std::vector<int> nums{1,1,1,1};
    // std::cout << solution.jump_45(nums) << std::endl;
    int jump_45(std::vector<int>& nums) {
        if(nums.size() == 1 )
            return 0;

        int steps(0);
        int i(0);
        
        while (i != nums.size() - 1)
        {
            int curr_step(i+1); // index
            int max(1+nums[i+1]);
            int j(i+1);
            for (; j < i + nums[i] + 1; j++)
            {
                if(j > (nums.size() - 1))
                    break;

                if(j == nums.size() - 1)
                    return ++steps;

                if(j - i + nums[j] > max){
                    max = j - i + nums[j];
                    curr_step = j;
                }
            }
            steps++;
            i = curr_step;
        }
        return steps;
    }

    //--------------------------#14---------------------------------------------//
    // std::vector<std::string> vec{"abab","aba",""};
    // std::cout << solution.longestCommonPrefix_14(vec) << std::endl;
    std::string longestCommonPrefix_14(std::vector<std::string>& strs) {
        if (strs.size() == 0)
            return {};

        std::string res(strs[0]);
        for(int i(1); i < strs.size(); i++){
            int size = (strs[0].size() < strs[i].size() ?  strs[0].size() : strs[i].size());
            if(size == 0)
                return {};
            for (int j(0); j < size ; j++){
                if(res[j] == strs[i][j]){
                    if(j ==  size - 1 and res.size() > j){
                        res.erase(res.begin() + j + 1, res.end());
                    }
                    continue;
                }
                res.erase(res.begin() + j, res.end());
                break;
            }            
        }
        return res;
    }

    //--------------------------#42---------------------------------------------//
    // //[0,1,0,2,1,0,1,3,2,1,2,1]
    // std::vector<int> vec{9,8,9,5,8,8,8,0,4};
    // sh.show_vec(vec);
    // std::cout << solution.trap_42(vec) << std::endl;
    int trap_42(std::vector<int>& height) {
        if(height.size() < 3)
            return {};

        std::vector<int> peaks;
        int max(0);
        for(int i(0); i < height.size(); i++){
            // begin
            if(i == 0){
                if(height[i] > height[i + 1]){
                    peaks.push_back(i);
                    max = (height[max] >= height[i] ? max : i); 
                    continue;
                }
                if(height[i] == height[i + 1]){
                    int st(i);
                    while (i != height.size() - 1 and height[i] == height[i+1]){
                        i++;
                    }
                    if(i == height.size() - 1){
                        return {};
                    }
                    if(height[i] > height[i+1]){
                        peaks.push_back(i);
                        max = (height[max] >= height[i] ? max : i);
                        i++;
                    }
                    continue;
                }
                continue;
            }
            

            // end
            if(i == height.size() - 1 and height[i] > height[i - 1]){
                peaks.push_back(i);
                max = (height[max] >= height[i] ? max : i);
                continue;
            }

            // middle
            if (height[i] > height[i - 1] and height[i] > height[i+1]){
                peaks.push_back(i);
                max = (height[max] >= height[i] ? max : i);
                continue;
            }
            if (height[i] > height[i - 1] and height[i] == height[i+1]){
                int st(i);
                while (i != height.size() - 1 and height[i] == height[i+1]){
                    i++;
                }
                if(i == height.size() - 1){
                    peaks.push_back(st);
                    max = (height[max] >= height[i] ? max : i);
                    continue;
                }
                if(height[i] > height[i+1]){
                    peaks.push_back(st);
                    peaks.push_back(i);
                    max = (height[max] >= height[i] ? max : i);
                    i++;
                }
            }
        }
        if(peaks.size() <= 1)
            return {};
        
        // optimization
        std::vector<int> opt_peaks;
        opt_peaks.push_back(peaks[0]);
        int sec_p(0);
        for(int i(1); i < peaks.size(); i++){
            if (peaks[i] > max)
                break;
            if(height[peaks[i]] < height[peaks[sec_p]] and height[peaks[i]] < height[max])
                continue;
            if(height[peaks[i]] >= height[peaks[sec_p]]){
                opt_peaks.push_back(peaks[i]);
                sec_p = i;
            }
        }
        std::vector<int> temp;
        sec_p = peaks.size() - 1;
        if (peaks[sec_p] != max)
            temp.push_back(peaks[sec_p]);
        for(int i(peaks.size() - 2); i >= 0; i--){
            if (peaks[i] <= max)
                break;
            if(height[peaks[i]] < height[peaks[sec_p]] and height[peaks[i]] < height[max])
                continue;
            if(height[peaks[i]] >= height[peaks[sec_p]]){
                temp.push_back(peaks[i]);
                sec_p = i;
            }
        }
        std::reverse(temp.begin(), temp.end());
        opt_peaks.insert(opt_peaks.end() ,temp.begin(), temp.end());

        
        // count water
        int res{};
        for(int i(0); i < opt_peaks.size() - 1; i++){
            res += countWater_42(height, opt_peaks[i], opt_peaks[i + 1]); 
        }
        return res;
    }

    //--------------------------#21---------------------------------------------//
    // ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    // sh.showList(l1);
    // ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    // sh.showList(l2);
    // solution.mergeTwoLists(l1, l2);
    // sh.showList(l1);
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        while (list1 != nullptr or list2 != nullptr){
            if(list1 == nullptr){
                head->next = list2;
                list2 = list2->next;
                head = head->next;
                continue;
            }
            if(list2 == nullptr){
                head->next = list1;
                list1 = list1->next;
                head = head->next;
                continue;
            }
            if(list1->val >= list2->val){
                head->next = list2;
                list2 = list2->next;
                head = head->next;
                continue;
            }
            head->next = list1;
            list1 = list1->next;
            head = head->next;
        }
        return dummy->next;
    }

    //--------------------------#27---------------------------------------------//
    // std::vector<int> vec{3,2,2,3};
    // solution.removeElement(vec, 3);
    int removeElement(std::vector<int>& nums, int val) {
        int count(0);
        for(int i(0); i < nums.size() - count; i++){
            if(nums[i] == val){
                count++;
                std::swap(nums[i], nums[nums.size() - count]);
                i--;
            }
        }
        nums.erase(nums.end() - count, nums.end());
        return nums.size();
    }

    //--------------------------#49---------------------------------------------//
    // std::vector<std::string> strs{"eat","tea","tan","ate","nat","bat"};
    // sh.show_vec(strs);
    // sh.show_vec_vec(solution.groupAnagrams(strs));
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        if(strs.size() == 0)
            return {};
        if(strs.size() == 1)
            return {{strs[0]}};

        std::unordered_map<std::string, std::vector<std::string>> mp;
        for(auto x: strs){
            std::string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        std::vector<std::vector<std::string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }

    //--------------------------#26---------------------------------------------//
    // std::vector<int> vec{1};
    // sh.show_vec(vec);
    // std::cout << solution.removeDuplicates_26(vec) << std::endl;
    // sh.show_vec(vec);
    int removeDuplicates_26(std::vector<int>& nums) {
        int prev(nums[0]);
        auto end = std::remove_if(nums.begin() + 1, nums.end(), [&prev](int a){
            if(a == prev)
                return true;
            prev = a;
            return false;
        });
        nums.erase(end, nums.end());
        return nums.size();
    }

    //--------------------------#28---------------------------------------------//
    int strStr_28(std::string haystack, std::string needle) {
        int i = haystack.find(needle);
        return (i == std::string::npos ? -1 : i);
    }

    //--------------------------#35---------------------------------------------//
    // std::vector<int> vec{1,3,4,5,6};
    // sh.show_vec(vec);
    // std::cout << solution.searchInsert_35(vec, -1);
    int searchInsert_35(std::vector<int>& nums, int target) {
        int l(0), r(nums.size() - 1), mid;
        while(l <= r){
            mid = (r + l) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target){
                if(mid == 0 or nums[mid - 1] < target)
                    return mid;
                r = mid - 1;
                continue;
            }
            if(nums[mid] < target){
                if(mid == nums.size() - 1 or nums[mid + 1] > target )
                    return mid + 1;
                l = mid + 1;
            }
        }
        return -1;
    }

    //--------------------------#48---------------------------------------------//
    // std::vector<std::vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    // sh.show_vec_vec(matrix);
    // solution.rotate_48(matrix);
    // sh.show_vec_vec(matrix);
    void rotate_48(std::vector<std::vector<int>>& matrix) {
        if(matrix.size() == 1)
            return;
        
        for (int i(0); i < matrix.size(); i++){
            for (int j(i + 1); j < matrix.size(); j++){
                std::swap(matrix[i][j], matrix[j][i]);
            }
            std::reverse(std::begin(matrix[i]), std::end(matrix[i]));
        }
    }

    //--------------------------#46---------------------------------------------//
    // std::vector<int> vec{1,2,3};
    // sh.show_vec(vec);
    // sh.show_vec_vec(solution.permute_46(vec));
    std::vector<std::vector<int>> permute_46(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
    void backtrack(std::vector<int>& nums, int start, std::vector<std::vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums, start, i);
            backtrack(nums, start + 1, res);
            swap(nums, start, i);
        }
    }

    //--------------------------#53---------------------------------------------//
    // std::vector<int> vec{-2,1,-3,4,-1,2,1,-5,4}; //1-> 3->  
    // std::cout << solution.maxSubArray(vec) << std::endl;
    int maxSubArray(std::vector<int>& nums) {
        int res = nums[0];
        int total = 0;

        for (int n : nums) {
            if (total < 0) {
                total = 0;
            }

            total += n;
            res = std::max(res, total);
        }

        return res;
    }

    //--------------------------#54---------------------------------------------//
    // std::vector<std::vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    // sh.show_vec(solution.spiralOrder(matrix));
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        res.resize(matrix.size() * matrix[0].size());
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                res[getSpiralPlace(i, j, matrix[i].size(), matrix.size())] = matrix[i][j];
            }
        }
        return res;
    }
    int getSpiralPlace(const int& i,const int& j, int n , int m){
        if(i == 0)
            return j;
        if(j == n - 1)
            return j + i;
        if(i == m - 1)
            return i + 2 * (n - 1) - j;
        if(j == 0)
            return 2 * (n - 1) + 2 * (m - 1) - i; 
        return  2 * (n - 1) + 2 * (m - 1) + getSpiralPlace(i - 1, j - 1, n - 2, m - 2);
    }


//================================================================================================================================================
private:
    bool isPalindrom_5(const std::string &str, int start, int end){
        int l = start, r = end;
        while(l <= r){
            if(str[l] != str[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    std::string expand_5(int i, int j, std::string s) {
        int left = i;
        int right = j;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }
    void solve_17(std::vector<std::string> &ans,std::vector<std::string> &vec_str, std::string temp, int j){
        if(j >= vec_str.size()){
            ans.push_back(temp);
            //j--;
            return;
        }
        for(int i(0); i < vec_str[j].size(); i++){
            temp.push_back(vec_str[j][i]);
            solve_17(ans, vec_str, temp, j + 1);
            temp.pop_back();
        }
    }
    void swap(std::vector<int>& nums, int i, int j){
        if(i == j)
            return;
        nums[i] += nums[j]; 
        nums[j] = nums[i] - nums[j]; 
        nums[i] -= nums[j];
    }
    
    // --34
    int binarySearch(std::vector<int> &nums, int target){
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r){
            mid = (r + l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                r = mid - 1;
            }
            if(nums[mid] < target){
                l = mid + 1;
            }
        }
        return -1;
    }
    int binarySearch_r(std::vector<int> &nums, int target){
        int l = 0, r = nums.size() - 1, mid, i = -1;
        while(l <= r){
            mid = (r + l) / 2;
            if(nums[mid] == target){
                if(nums[mid + 1] == target){
                    l = mid + 1;
                    i = mid;
                    continue;
                }
                return mid;
            }
            if(nums[mid] > target){
                r = mid - 1;
            }
            if(nums[mid] < target){
                l = mid + 1;
            }
        }
        return i;
    }
    int binarySearch_l(std::vector<int> &nums, int target){
        int l = 0, r = nums.size() - 1, mid, i;
        while(l <= r){
            mid = (r + l) / 2;
            if(nums[mid] == target){
                if(nums[mid - 1] == target){
                    r = mid - 1;
                    i = mid;
                    continue;
                }
                return mid;
            }
            if(nums[mid] > target){
                r = mid - 1;
            }
            if(nums[mid] < target){
                l = mid + 1;
            }
        }
        return -1;
    }

    // --33
    // return start index of second array
    int binarySearchGap(std::vector<int> &nums){
        if(nums.size() == (0 || 1))
            return -1;

        int l = 0, r = nums.size() - 1, mid;
        while(l < r){
            mid = std::ceil((r + l) / 2.);
            if(nums[mid] < nums[mid-1]){
                return mid;
            }
            if(nums[mid] > nums[l]){
                l = mid;
            }
            if(nums[mid] < nums[r]){
               r = mid;
            }
        }
        return -1;
    }
    int binarySearchRange(std::vector<int> &nums, int target, int left, int rigth){
        int l = left, r = rigth, mid;
        while(l <= r){
            mid = (r + l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                r = mid - 1;
            }
            if(nums[mid] < target){
                l = mid + 1;
            }
        }
        return -1;
    }

    // --36
    bool rowValid(std::vector<std::vector<char>>& board){
        std::unordered_set<char> check;
        for(const auto &row: board){
            for(const auto &t: row){
                if(t == '.')
                    continue;

                if(check.contains(t))
                    return false;

                check.insert(t);
            }
            check.clear();
        }
        return true;
    }
    bool collValid(std::vector<std::vector<char>>& board){
        std::unordered_set<char> check;
        for (int i(0); i < board.size(); i++)
        {
            for (int j(0); j < board[i].size(); j++)
            {   
                if(board[j][i]   == '.')
                    continue;

                if(check.contains(board[j][i]))
                    return false;

                check.insert(board[j][i]);
            }
            check.clear();
        }
        return true;
    }
    bool squareValid(std::vector<std::vector<char>>& board){
        std::unordered_set<char> check;
        int size = 3;
        for (int i_gl(0); i_gl < board.size() / size; i_gl ++)
        {
            for (int j_gl(0); j_gl < board.size() / size; j_gl++)
            {  
                for (int i(i_gl); i < size; i++)
                {
                    for (int j(j_gl); j < size; j++)
                    {   
                        if(board[i][j]   == '.')
                            continue;

                        if(check.contains(board[i][j]))
                            return false;

                        check.insert(board[i][j]);
                    }
                }
                check.clear();
            }    
        }
        return true;
    }

    int countWater_42(std::vector<int>& h, int l, int r){
        int peak = std::min(h[l], h[r]);
        int sum{};
        for(int i(l+1) ; i < r; i++)
            sum +=  (peak <= h[i] ? 0 : peak - h[i]);
        return sum;
    }

    // --49
    bool isAnagramm(std::string& root, std::string& word){
        if(root.size() != word.size())
            return false;

        std::unordered_map<char, int> check;
        for (int i = 0; i < root.size(); i++){
            if(check.contains(root[i])){
                check[root[i]]++;
            }else{
                check[root[i]] = 1;
            }
            
            if(check.contains(word[i])){
                check[word[i]]--;
            }else{
                check[word[i]] = -1;
            }
        }
        for(const auto& t: check){
            if(t.second != 0)
                return false;
        }
        return true;
    }
    bool isAnagramm(std::unordered_map<char, int> check, std::string& word){
        if(check.size() != word.size())
            return false;

        for (int i = 0; i < check.size(); i++){
           if(check.contains(word[i])){
                check[word[i]]--;
            }else{
                return false;
            }
        }
        for(const auto& t: check){
            if(t.second != 0)
                return false;
        }
        return true;
    }
    void addInCheck(std::vector<std::unordered_map<char, int>>& check, std::string& root){
        std::unordered_map<char, int> ch;
        for (int i = 0; i < root.size(); i++){
            if(ch.contains(root[i])){
                ch[root[i]]++;
            }else{
                ch[root[i]] = 1;
            }
        }
        check.push_back(ch);
    }
};


//==========================================================================//

int main(){
    Solution solution;
    ShowSmt sh;
    
    

}