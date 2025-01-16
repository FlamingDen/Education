#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"


class Solution {
public:
    //--------------------------#2657-------------------------------------------//
    // std::vector<int> A{2,3,1};
    // std::vector<int> B{3,1,2};
    // sh::showContainer(solution.findThePrefixCommonArray(A, B));
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        std::vector<int> ans;
        std::unordered_map<int, int> check;

        int tmp(0);
        for(size_t i(0); i != A.size(); ++i){
            if(++check[A[i]] == 2)
                tmp++;
            if(++check[B[i]] == 2)
                tmp++;
               
            ans.push_back(tmp);
        }
        
        return ans;
    }

    //--------------------------#2429-------------------------------------------//
    // sh::print(solution.minimizeXor(1, 12));
    int minimizeXor(int num1, int num2) {
        int ans = num1;
        int k = __builtin_popcount(num2);
        // for(size_t i(0); i != 32; ++i){
        //     if((num2 >> i) % 2 == 1)
        //         ++k;
        // }
        for(size_t i(31); i + 1 > 0; --i){
            if((num1 >> i) % 2 == 1){
                if(k != 0)
                    --k;
                else
                    SetBit(ans, i, 0); 
            }    
        }
        if(k != 0){
            for(size_t i(0); i != 32 and k != 0; ++i){
                int curr = (ans >> i) % 2;
                if(curr == 0){
                    --k;
                    SetBit(ans, i, 1);
                }
            }
        }

        return ans;
    }
    void SetBit(int& num, int shifts, int value){
        if(value == 1){
            num |= (value << shifts);
        }
        if(value == 0){
            value = ~(1 << shifts);
            num &= value;
        }
    }

    //--------------------------#2425-------------------------------------------//
    int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) {
        int res(0);
        int bitwise2(0);
        for(size_t i(0); i != nums2.size(); ++i){
            bitwise2 ^= nums2[i];
        }
        int n = nums2.size();
        for(size_t i(0); i != nums1.size(); ++i){
            int curr = nums1[i];
            if(n % 2 == 1)
                res ^= (curr ^ bitwise2);
            else 
                res ^= bitwise2;
        }
        return res;
    }
};

int main(){
    Solution solution;   
    Timer timer("DailyTasksLeetcode.cpp");



    
}