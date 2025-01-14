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


};

int main(){
    Solution solution;   
    Timer timer("DailyTasksLeetcode.cpp");
    
    
}