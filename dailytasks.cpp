#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

using namespace std;

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

    //--------------------------#2683-------------------------------------------//
    // std::vector<int> dev{0,1};
    // sh::print(solution.doesValidArrayExist(dev));
    bool doesValidArrayExist(std::vector<int>& derived) {
        std::pair<int, int> start, curr;
        for(size_t i(0); i != derived.size(); ++i){
            if(i == 0){
                start.first = derived[i] ^ 1;
                start.second = derived[i] ^ 0;
                curr = start;
            }
            curr.first ^= derived[i];
            curr.second ^= derived[i]; 
        }
        return start.first == curr.first || start.second == curr.second;
    }

    //--------------------------#2661-------------------------------------------//
    // std::vector<int> arr{8,2,4,9,3,5,7,10,1,6};
    // std::vector<std::vector<int>> mat{
    //     {8,2,9,10,4},
    //     {1,7,6,3,5}
    // };
    // sh::print(solution.firstCompleteIndex(arr, mat));
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        std::unordered_map<int, int> check(n * m);
        for(size_t i(0); i != n + m; ++i){
            check[i] =  i < n ?  m : n;    
        }
        std::unordered_map<int, std::pair<int, int>> matrix(n * m);
        for(size_t i(0); i != n; ++i){
            for(size_t j(0); j != m; ++j){
                matrix[mat[i][j]] = {i, j};
            }
        }
        
        size_t i(0);
        for(; i != arr.size(); ++i){
            if(!--check[matrix[arr[i]].first] || !--check[matrix[arr[i]].second + n])
                return i;
        }
        return -1;
    }

    //--------------------------#2017-------------------------------------------//
    // std::vector<std::vector<int>> grid{
    //     {2, 5, 4},
    //     {1, 5, 1}
    // };
    // sh::print(solution.gridGame(grid));
    long long gridGame(std::vector<std::vector<int>>& grid) {
        long long top = std::accumulate(begin(grid[0]), end(grid[0]), 0);
        long long bottom(0), res(LLONG_MAX);
        for(size_t i(0); i != grid[0].size(); ++i){
            top -= grid[0][i];
            res = min(res, max(top, bottom));
            bottom += grid[1][i];
        }
        return res;
    }
};

int main(){
    Solution solution;   
    Timer timer("DailyTasksLeetcode.cpp");

   
}