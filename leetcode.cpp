#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#include <array>
#include <algorithm>
#include <regex>


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

enum A{
    ABC = 2,
    DEf = 3
};


class Solution {
public:
    //--------------------------#2----------------------------------------------//
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
    void showList_2(ListNode* l){
        while (l != nullptr){
            std::cout << l->val << ",";
            l = l->next; 
        }
        std::cout << std::endl;
    }

    //--------------------------#3----------------------------------------------//
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
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
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
};


//==========================================================================//

int main(){
    Solution solution;
    /*
    // // --2
    // ListNode l1(9, (new ListNode(9, (new ListNode(9,(new ListNode(9,(new ListNode(9,(new ListNode(9,(new ListNode(9,(new ListNode(9)))))))))))))));
    // ListNode l2(9, new ListNode(9, new ListNode(9,(new ListNode(9)))));
    // solution.showList_2(&l1);
    // solution.showList_2(&l2);
    // solution.addTwoNumbers_2(&l1, &l2);

    // // --3
    // std::cout << solution.lengthOfLongestSubstring_3("pwwkew") << std::endl;
    
    // // --5
    // std::string str = "gccghj";
    // std::cout << solution.longestPalindrome_5(str) << std::endl;

    // // --7
    // std::cout << solution.reverse_7(96463243) << std::endl;
    
    // // --9
    // std::cout << std::boolalpha << solution.isPalindrome_9(12321) << std::endl;

    // // --11
    // std::vector<int> vec{1,1,1,1,8,1,1,1,1,1,1,1,1,1};
    // std::cout << solution.maxArea_11(vec) << std::endl;
    
    // // --8
    // std::cout << solution.myAtoi_8("1337c0d3") << std::endl;
    
    // // --6
    // std::cout << solution.convert_6("PAYPALISHIRING", 4) << std::endl;
    
    // // --4
    // std::vector<int> a{};
    // std::vector<int> b{1};
    // std::cout << solution.findMedianSortedArrays_4(a, b) << std::endl;
    
    // // // --17
    // std::vector<std::string> str = solution.letterCombinations_17("23");
    // for (auto &i : str)
    //     std::cout << i << ", ";
    
    // // --19
    // ListNode* l1 = new ListNode(1, (new ListNode(2, (new ListNode(3,(new ListNode(4,(new ListNode(5,(new ListNode(6,(new ListNode(7,(new ListNode(8)))))))))))))));
    // solution.showList_2(l1);
    // l1 = solution.removeNthFromEnd_19(l1, 8);
    // l1 = solution.removeNthFromEnd_19(l1, 6);
    // solution.showList_2(l1);
    
    // // --24
    // ListNode* l1 = new ListNode(1, (new ListNode(2, (new ListNode(3,(new ListNode(4,(new ListNode(5,(new ListNode(6,(new ListNode(7,(new ListNode(8)))))))))))))));
    // ListNode* l2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    // solution.showList_2(l2);
    // l2 = solution.swapPairs_24(l2);
    // solution.showList_2(l2);
    // solution.showList_2(l1);
    // l1 = solution.swapPairs_24(l1);
    // solution.showList_2(l1);
    */


}