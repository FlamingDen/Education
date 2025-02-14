#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

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
};

int main() {
    Solution solution;   
    Timer timer("LeetCode_400.cpp");
    
    
    
}