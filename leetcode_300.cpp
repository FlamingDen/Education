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
};

int main(){
    Solution solution;   
    Timer timer("LeetCode_300.cpp");
    
    
    
}