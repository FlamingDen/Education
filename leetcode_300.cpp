#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

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
};

int main(){
    Solution solution;   
    Timer timer("LeetCode_300.cpp");
    
    
}