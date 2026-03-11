#include "ForLeetcode.h"
#include "show.h"
#include "TimeGuard.hpp"

using namespace std;



class Solution {
    std::vector<std::pair<int, int>> SHIFTS{
        {-1, 0}, // top
        {1, 0},  // bottom
        {0, -1}, // left
        {0, 1}   // right
    };

public:
    // ---#503---
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        vector<int> res(nums.size(), 0);
        stack<int> st;

        // find max
        int max(nums[0]);
        int ind_max(0);
        for (size_t i(1); i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                ind_max = i;
            }
        }

        st.push(max);
        res[ind_max] = -1;
        for (size_t i(0), j(ind_max); i < nums.size(); i++, j--) {
            int curr = nums[j];
            while (curr >= st.top() and st.size() > 1) {
                st.pop();
            }
            if (curr == st.top()) {
                res[j] = -1;
            }
            else if (curr < st.top()) {
                res[j] = st.top();
                st.push(curr);
            }
            

            if (j == 0)
                j = nums.size();
        }

        return res;
    }

    // ---#508---
    // TreeNode* root = new TreeNode(5, new TreeNode(2), new TreeNode(-5));
    // sh::ShowContainer(solution.findFrequentTreeSum(root));
    vector<int> findFrequentTreeSum(TreeNode* root) {
        std::vector<int> res;
        std::unordered_map<int, int> mp;
        findFrequentTreeSumHelp(root, mp);

        std::vector<pair<int, int>> tmp(mp.begin(), mp.end());
        std::sort(tmp.begin(), tmp.end(), [](const auto& p1, const auto& p2){
            return p1.second > p2.second;
        });

        res.push_back(tmp[0].first);
        int count(tmp[0].second);
        for(size_t i(1); i < tmp.size() and tmp[i].second == count; i++) {
            res.push_back(tmp[i].first);
        }
        return res;
    }
    static 
    int findFrequentTreeSumHelp(TreeNode* node, std::unordered_map<int, int>& res){
        if(!node)
            return 0;

        int left_sum = findFrequentTreeSumHelp(node->left, res);
        int right_sum = findFrequentTreeSumHelp(node->right, res);
        int sum = node->val + left_sum + right_sum;
        res[sum]++;
        return sum;
    }
};

int main()
{
    Solution solution;
    TimeGuard timer("LeetCode_700.cpp");

    TreeNode* root = new TreeNode(5, new TreeNode(2), new TreeNode(-5));
    sh::ShowContainer(solution.findFrequentTreeSum(root));
}