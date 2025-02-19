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
    bool isPowerOfThree_326(int n) {
        while (n % 3 == 0 and n > 3){
            n /= 3;
        }  
        return n == 3 or n == 1? true : false;
    }

    //--------------------------#306--------------------------------------------//
    // std::cout << std::boolalpha;
    // sh::print(solution.isAdditiveNumber("121474836472147483648"));
    bool isAdditiveNumber_306(string num) {
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

    //--------------------------#318--------------------------------------------//
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size());
        int result = 0;
        for (int i=0; i<words.size(); ++i) {
            for (char c : words[i])
                mask[i] |= 1 << (c - 'a');
            for (int j=0; j<i; ++j)
                if (!(mask[i] & mask[j]))
                    result = max(result, int(words[i].size() * words[j].size()));
        }
        return result;
    }
 
    //--------------------------#319--------------------------------------------//
    // sh::print(solution.bulbSwitch_319(5));
    int bulbSwitch_319(int n) {
        int res(1);
        for(size_t i(2); i <= n; ++i){
            bool lamp(true);
            for(size_t j(2); j <= i; ++j){
                if(i % j == 0)
                    lamp = !lamp;
            }
            if(lamp)
                ++res;
        }
        return res;
        // 2 решение
        // sqrt(n);
    }

    //--------------------------#322--------------------------------------------//
    int coinChange_322(vector<int>& coins, int n) {
        int dp[++n];
        dp[0] = 0;
        sort(begin(coins), end(coins));
        
        for (int i = 1; i < n; i++) {
            dp[i] = INT_MAX;
            for (const int& c: coins) {
                if (i - c < 0) 
                    break;
                
                if (dp[i - c] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[--n] == INT_MAX ? -1 : dp[n];
    }
};

int main() {
    Solution solution;   
    Timer timer("LeetCode_400.cpp");
 
     
    vector<int> coins{186,419,83,408};
    sh::print(solution.coinChange_322(coins, 6249));

    auto sp1 = std::shared_ptr<int>(new int(10));   // 1
    auto sp2 = std::make_shared<int>(10);           // 2
}