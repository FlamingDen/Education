#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

using namespace std;

    //--------------------------#303--------------------------------------------//
    // std::vector<int> nums{1,2,3,4,5};
    // NumArray* obj = new NumArray(nums);
    // int param_1 = obj->sumRange(0,4);
    // sh::print(param_1);
class NumArray {
    std::vector<int> pref_sum;
public:
    NumArray(vector<int>& nums){
        pref_sum.resize(nums.size() + 1);
        pref_sum[0] = 0;
        pref_sum[1] = nums[0];
        for(size_t i(1); i != nums.size(); ++i)
            pref_sum[i + 1] = pref_sum[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return pref_sum[right + 1] - pref_sum[left];
    }
};

class Solution {
public:
    //--------------------------#326--------------------------------------------//
    // std::cout << std::boolalpha;
    // sh::print(solution.isPowerOfThree(1));
    bool isPowerOfThree(int n) {
        while (n % 3 == 0 and n > 3){
            n /= 3;
        }  
        return n == 3 or n == 1? true : false;
    }

    //--------------------------#306--------------------------------------------//
    // std::cout << std::boolalpha;
    // sh::print(solution.isAdditiveNumber("121474836472147483648"));
    bool isAdditiveNumber(string num) {
        for(size_t i(1); i <= num.size() / 2; ++i){
            for(size_t j(1); j <= (num.size() - i) / 2; ++j){
                if(CheckAdditional(num.substr(0,i), num.substr(i,j), num, i + j))
                    return true;
            }
        }
        return false;
    }
    bool CheckAdditional(string n1, string  n2, string& num, int pos){
        if(pos >= num.size())
            return false;
        
        if (n1.size() > 1 && n1[0] == '0' || n2.size() > 1 && n2[0] == '0')
            return false;
        long num1 = std::stol(n1);
        long num2 = std::stol(n2);
        while (pos < num.size())
        {
            auto curr = std::to_string(num1 + num2);
            if(curr != num.substr(pos, curr.size()) )
                return false;

            pos += curr.size();
            num1 = num2;
            num2 = std::stoi(curr);
        }
        return true;
    }

    //--------------------------#315--------------------------------------------//
    // vector<int> countSmaller(vector<int>& nums) {
    //     vector<int> res(nums.size());
    //     res.push_back(0);
    //     std::map<int, std::pair<int, int>> m;
    //     m.insert({nums.back(), {1, 0}});
    //     int j(1);
    //     for(size_t i(nums.size() - 2); i + 1 > 0; --i, ++j){
    //         auto it = std::lower_bound(m.begin(), m.end(), nums[i]);
    //         auto& [freq, n] = it->second;
    //         if(it == m.end()){
    //             auto curr = m.rbegin()->second;
    //             m.insert({nums[i],{1, curr.first + curr.second}});
    //             res.push_back(curr.first + curr.second);
    //         } else if(it->first == nums[i]){
    //             ++freq;
    //             ++it;
    //             while (it++ != m.end()){
    //                 n++;
    //             }
    //             res.push_back(n);
    //         } else {
    //             m.insert({nums[i],{1, j}});
    //             res.push_back(j);
    //         }
    //     }
    //     std::reverse(begin(res), end(res));
    //     return res;
    // }
};

int main() {
    Solution solution;   
    Timer timer("LeetCode_400.cpp");
    
    
}