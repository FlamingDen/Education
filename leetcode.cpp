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
    */

    // --8
    //std::cout << solution.myAtoi_8("1337c0d3") << std::endl;
}