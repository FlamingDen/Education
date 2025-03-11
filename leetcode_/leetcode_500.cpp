#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

#include <forward_list>

using namespace std;

class Solution
{
public:
    //--------------------------#401--------------------------------------------//
    // sh::showContainer(solution.readBinaryWatch_401(4));
    vector<string> readBinaryWatch_401(int n) {
        if (n > 8)
            return {};

        vector<string> res;
        for (size_t i(0); i <= n; ++i)
        {
            int min = i;
            int h = n - i;
            if (min >= 6 or h >= 4)
                continue;

            vector<int> min_arr = GetMinutes(min);
            vector<int> h_arr = GetHours(h);
            for (size_t j(0); j < h_arr.size(); ++j)
            {
                if (min_arr.empty())
                {
                    res.push_back(std::to_string(h_arr[j]) + ":00");
                }
                else
                {
                    for (size_t k(0); k < min_arr.size(); ++k)
                    {
                        string str_min = std::to_string(min_arr[k]);
                        if (str_min.size() < 2)
                            str_min = '0' + str_min;
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
    vector<int> GetHours(int n) {
        if (n == 0)
            return { 0 };
        std::vector<int> nums{ 8, 4, 2, 1 };
        vector<int> res;
        GetHoursHelp(nums, res, n, 0, 0);
        return res;
    }
    void GetHoursHelp(const std::vector<int>& nums, vector<int>& res, int n, int curr, int ind) {
        if (n == 0 and curr < 12)
        {
            res.push_back(curr);
            return;
        }

        for (size_t i(ind); i < nums.size(); ++i)
        {
            GetHoursHelp(nums, res, n - 1, curr + nums[i], i + 1);
        }
    }
    vector<int> GetMinutes(int n) {
        if (n == 0)
        {
            return {};
        }

        std::vector<int> nums{ 32, 16, 8, 4, 2, 1 };
        vector<int> res;
        GetMinutesHelp(nums, res, n, 0, 0);
        return res;
    }
    void GetMinutesHelp(const std::vector<int>& nums, vector<int>& res, int n, int curr, int ind) {
        if (n == 0 and curr <= 59)
        {
            res.push_back(curr);
            return;
        }

        for (size_t i(ind); i < nums.size(); ++i)
        {
            GetMinutesHelp(nums, res, n - 1, curr + nums[i], i + 1);
        }
    }

    //--------------------------#404--------------------------------------------//
    int sumOfLeftLeaves_404(TreeNode* root) {
        return GetSumOfLeftLeaves(root, false);
    }
    int GetSumOfLeftLeaves(TreeNode* root, bool left) {
        if (!root)
            return 0;

        if (!root->left and !root->right and left)
        {
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
            [](const vector<int>& v1, const vector<int>& v2)
            {
                return std::tie(v2[0], v1[1]) < std::tie(v1[0], v2[1]);
            });
        for (auto& man : people)
        {
            res.insert(res.begin() + man[1], man);
        }
        return res;
    }

    //--------------------------#409--------------------------------------------//
    // sh::print(solution.longestPalindrome_409("nadetheearth"));
    int longestPalindrome_409(string s) {
        map<char, int> m;
        for (size_t i(0); i < s.size(); ++i)
        {
            m[s[i]]++;
        }
        int full_part(0), additional(0);
        bool odd(false);
        for (auto it = std::begin(m); it != std::end(m); ++it)
        {
            if (it->second % 2 == 0)
            {
                full_part += it->second;
            }
            else
            {
                full_part += it->second - 1;
                odd = true;
            }
        }
        return full_part + odd;
    }

    //--------------------------#412--------------------------------------------//
    // sh::showContainer(solution.fizzBuzz_412(3));
    vector<string> fizzBuzz_412(int n) {
        vector<string> res(n);
        for (size_t i(1); i <= n; ++i)
        {
            res[i - 1] = SetFizzBuzz(i);
        }
        return res;
    }
    string SetFizzBuzz(int i) {
        if (i % 15 == 0)
            return "FizzBuzz";
        if (i % 3 == 0)
            return "Fizz";
        if (i % 5 == 0)
            return "Buzz";
        return to_string(i);
    }

    //--------------------------#413--------------------------------------------//
    // std::vector<int> nums{ 1,2,3,8,9,10 };
    // sh::print(solution.numberOfArithmeticSlices_413(nums));
    int numberOfArithmeticSlices_413(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        int res(0), k(2), start(0);
        int diff = nums[1] - nums[0];
        for (size_t i(2); i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == diff) {
                ++k;
                if (k >= 3)
                    res += (i - start - 1);
            }
            else {
                diff = nums[i] - nums[i - 1];
                k = 2;
                start = i - 1;
            }
        }
        return res;
    }

    //--------------------------#414--------------------------------------------//
    // vector<int> nums{2,2,3,2};
    // sh::print(solution.thirdMax_414(nums));
    int thirdMax_414(vector<int>& nums) {
        sort(begin(nums), end(nums));
        if (nums.size() < 3)
            return nums.back();

        for (size_t i(nums.size() - 2), j(1); i + 1 > 0; --i) {
            if (nums[i] != nums[i + 1]) {
                ++j;
                if (j == 3)
                    return nums[i];
            }
        }
        return nums.back();
    }

    //--------------------------#415--------------------------------------------//
    // sh::print(solution.addStrings_415("11", "123"));
    string addStrings_415(string num1, string num2) {
        string res;
        int p1(num1.size() - 1), p2(num2.size() - 1);
        int remn(0);
        while (p1 >= 0 or p2 >= 0 or remn) {
            if (p1 >= 0 and p2 >= 0) {
                int a = num1[p1] - '0';
                int b = num2[p2] - '0';
                int curr = (a + b + remn) % 10;
                remn = (a + b + remn) / 10;
                res.push_back(curr + '0');
            }
            else if (p1 >= 0) {
                int a = num1[p1] - '0';
                int curr = (a + remn) % 10;
                remn = (a + remn) / 10;
                res.push_back(curr + '0');
            }
            else if (p2 >= 0) {
                int a = num2[p2] - '0';
                int curr = (a + remn) % 10;
                remn = (a + remn) / 10;
                res.push_back(curr + '0');
            }
            else {
                res.push_back(remn + '0');
                remn = 0;
            }
            p1--;
            p2--;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    //--------------------------#416--------------------------------------------//
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(begin(nums), end(nums), 0);
        if (sum & 1 == 1) {
            return false;
        }
        int goal = sum / 2;
        std::vector<int> dp(goal + 1);
        dp[0] = true;
        for (size_t i(0); i < nums.size(); ++i) {
            for (size_t j(goal); j + 1 > nums[i]; j--) {
                dp[j] = (dp[j] or dp[j - nums[i]]);
            }
            if (dp[goal])
                break;
        }
        return dp[goal];
    }

    //--------------------------#417--------------------------------------------//
    // vector<vector<int>> heights{
    //     {1,2,2,3,5},
    //     {3,2,3,4,4},
    //     {2,4,5,3,1},
    //     {6,7,1,4,5},
    //     {5,1,1,2,4}
    // };
    // sh::showVecVec(solution.pacificAtlantic_417(heights));
    vector<vector<int>> pacificAtlantic_417(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac(n, std::vector<bool>(m));
        vector<vector<bool>> atl(n, std::vector<bool>(m));


        for (int i = 0; i < n; i++) {

            dfs(heights, pac, i, 0, -1, -1); // first col
            dfs(heights, atl, i, m-1, -1, -1); // last col
        }

        for (int j = 0; j < m; j++) {

            dfs(heights, pac, 0, j, -1, -1); // first row 
            dfs(heights, atl, n - 1, j, -1, -1); // last row
        }

        for (int i(0); i < n; i++) {
            for (int j(0); j < m; j++) {
                if (pac[i][j] and atl[i][j])
                    res.push_back({ i, j });
            }
        }

        return res;
    }
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j, int oi, int oj) {

        if (i < 0 || i >= h.size() || j < 0 || j >= h[0].size() || vis[i][j])
            return;
        if (oi >= 0 && oj >= 0 && h[i][j] < h[oi][oj]) 
            return; 

        vis[i][j] = true;
        dfs(h, vis, i - 1, j, i, j);
        dfs(h, vis, i + 1, j, i, j);
        dfs(h, vis, i, j - 1, i, j);
        dfs(h, vis, i, j + 1, i, j);
    }
};

int main() {
    Solution solution;
    Timer timer("LeetCode_500.cpp");


    
}