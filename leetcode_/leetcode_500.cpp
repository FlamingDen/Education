#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

#include <forward_list>

using namespace std;

class Solution {
public:
    //--------------------------#401--------------------------------------------//
    // sh::showContainer(solution.readBinaryWatch_401(4));
    vector<string> readBinaryWatch_401(int n) {
        if(n > 8)
            return {};

        vector<string> res;
        for(size_t i(0); i <= n; ++i){
            int min = i;
            int h = n - i;
            if(min >= 6 or h >= 4)
                continue;

            vector<int> min_arr = GetMinutes(min);
            vector<int> h_arr = GetHours(h);
            for(size_t j(0); j < h_arr.size(); ++j){
                if(min_arr.empty()){
                    res.push_back(std::to_string(h_arr[j]) + ":00");
                } else {
                    for(size_t k(0); k < min_arr.size(); ++k){
                        string str_min = std::to_string(min_arr[k]);
                        if(str_min.size() < 2)
                            str_min = '0'+ str_min;
                        res.push_back(std::to_string(h_arr[j]) + ":" + str_min);
                    } 
                }
                
            }

        } 
        return res;
        // --2 solution
        // vector<string> rs;
        // for (int h = 0; h < 12; h++)
        //     for (int m = 0; m < 60; m++)
        //         if (bitset<10>(h << 6 | m).count() == num)
        //             rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
        // return rs;
    }
    vector<int> GetHours(int n){
        if(n == 0)
            return {0};
        std::vector<int> nums{8,4,2,1};
        vector<int> res;
        GetHoursHelp(nums, res, n, 0, 0);
        return res;
    }
    void GetHoursHelp(const std::vector<int>& nums,  vector<int>& res, int n, int curr, int ind){
        if(n == 0 and curr < 12){
            res.push_back(curr);
            return;
        }

        for(size_t i(ind); i < nums.size(); ++i){
            GetHoursHelp(nums, res, n - 1, curr + nums[i], i + 1);
        }
    }
    vector<int> GetMinutes(int n){
        if(n == 0){
            return {};
        }
        
        std::vector<int> nums{32,16,8,4,2,1};
        vector<int> res;
        GetMinutesHelp(nums, res, n, 0, 0);
        return res;
    }
    void GetMinutesHelp(const std::vector<int>& nums,  vector<int>& res, int n, int curr, int ind){
        if(n == 0 and curr <= 59){
            res.push_back(curr);
            return;
        }

        for(size_t i(ind); i < nums.size(); ++i){
            GetMinutesHelp(nums, res, n - 1, curr + nums[i], i + 1);
        }
    }

    //--------------------------#404--------------------------------------------//
    int sumOfLeftLeaves(TreeNode* root) {
        return GetSumOfLeftLeaves(root, false);
    }
    int GetSumOfLeftLeaves(TreeNode* root, bool left){
        if(!root)
            return 0;
        
        if(!root->left and !root->right and left){
            return root->val;
        }
        int a = GetSumOfLeftLeaves(root->left, true);
        int b = GetSumOfLeftLeaves(root->right, false);
        return a + b;
    }

    //--------------------------#406--------------------------------------------//
    // vector<vector<int>> people{
    //     {7,0},
    //     {4,4},
    //     {7,1},
    //     {5,0},
    //     {6,1},
    //     {5,2}
    // };
    // sh::showVecVec(solution.reconstructQueue_406(people));
    vector<vector<int>> reconstructQueue_406(vector<vector<int>>& people) {
        vector<vector<int>> res;
        res.reserve(people.size());
        std::sort(
            people.begin(), 
            people.end(),
            [](const vector<int>& v1, const vector<int>& v2){
                return std::tie(v2[0],v1[1]) < std::tie(v1[0], v2[1]);
            }
        );
        for (auto& man : people){
            res.insert(res.begin() + man[1], man);
        }
        return res;
    }
};

int main() {
    Solution solution;   
    Timer timer("LeetCode_500.cpp");

    
    
    
}