﻿#include "ForLeetcode.h"
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
            dfs(heights, atl, i, m - 1, -1, -1); // last col
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

    //--------------------------#419--------------------------------------------//
    // vector<vector<char>> board{
    //     {'X','.','.','X'},
    //     {'.','X','.','X'},
    //     {'.','X','.','X'}
    // };
    // sh::print(solution.countBattleships(board));
    int countBattleships_419(vector<vector<char>>& board) {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size()));
        int res(0);
        for (size_t i(0); i < board.size(); i++) {
            for (size_t j(0); j < board[0].size(); j++) {
                if (board[i][j] == 'X' and vis[i][j] == false) {
                    res++;
                    ShipDFS(board, vis, { i, j });
                }
                vis[i][j] = true;
            }
        }
        return res;
    }
    void ShipDFS(vector<vector<char>>& board, vector<vector<bool>>& vis, std::pair<int, int> point) {
        auto [x, y] = point;
        vis[x][y] = true;
        for (size_t i(0); i < SHIFTS.size(); i++) {
            int xx = x + SHIFTS[i].first;
            int yy = y + SHIFTS[i].second;
            if (xx < 0 or xx >= board.size() or yy < 0 or yy >= board[0].size()) {
                continue;
            }
            if (vis[xx][yy] == false and board[xx][yy] == 'X') {
                ShipDFS(board, vis, { xx, yy });
            }
            vis[xx][yy] = true;
        }
    }

    //--------------------------#430--------------------------------------------//
    // Node *n = new Node(1, nullptr, new Node(2, nullptr, new Node(3, nullptr, nullptr, nullptr), new Node(99, nullptr, nullptr, nullptr)), nullptr);
    // flatten_430(n);
    /*
    Node* flatten_430(Node* head) {
        Node *curr = head;
        while (curr){
            if(curr->child){
                Node *st = flatten_430(curr->child);
                Node *cont = curr->next;

                curr->child = nullptr;
                curr->next = st;
                st->prev = curr;

                while (st->next){
                    st = st->next;
                }

                if(cont){
                    st->next = cont;
                    cont->prev = st;
                }


                curr = cont;
                continue;
            }
            curr = curr->next;
        }
        return head;
    }
    */

    //--------------------------#441--------------------------------------------//
    int arrangeCoins_441(int n) {
        int res(0);
        int coins(1);
        while (n >= coins) {
            n -= coins++;
            res++;
        }
        return res;
    }

    //--------------------------#442--------------------------------------------//
    // vector<int> nums{ 2,1 };
    // sh::ShowContainer(solution.findDuplicates_442(nums));
    vector<int> findDuplicates_442(vector<int>& nums) {
        vector<int>ans;
        for (int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);
            if (nums[x - 1] < 0)
                ans.push_back(x);

            nums[x - 1] *= -1;
        }
        return ans;
    }

    //--------------------------#443--------------------------------------------//
    // vector<char> chars{'a','b','c'};
    // sh::Print(solution.compress(chars));
    int compress(vector<char>& chars) {
        int r(0), len(0);
        char curr_ch(chars[0]);
        for (size_t i(0); i < chars.size(); i++) {
            if (chars[i] == curr_ch)
                len++;
            else {
                chars[r++] = curr_ch;
                if (len > 1) {
                    string len_str = std::to_string(len);
                    for (size_t i(0); i < len_str.size(); i++) {
                        chars[r++] = len_str[i];
                    }
                }

                len = 1;
                curr_ch = chars[i];
            }


            if (i == size(chars) - 1) {
                chars[r++] = curr_ch;
                if (len > 1) {
                    string len_str = std::to_string(len);
                    for (size_t i(0); i < len_str.size(); i++) {
                        chars[r++] = len_str[i];
                    }
                }
            }
        }
        chars.erase(chars.begin() + r, chars.end());
        return chars.size();
    }

    //--------------------------#448--------------------------------------------//
    // vector<int> nums{4,3,2,7,8,2,3,1};
    // sh::ShowContainer(solution.findDisappearedNumbers_448(nums));
    vector<int> findDisappearedNumbers_448(vector<int>& nums) {
        vector<int> res;
        for (size_t i(0); i < nums.size(); i++) {
            int ind = std::abs(nums[i]) - 1;
            if (nums[ind] > 0)
                nums[ind] *= -1;
        }
        for (size_t i(0); i < nums.size(); i++) {
            if (nums[i] > 0)
                res.push_back(i + 1);
        }
        return res;
    }

    //--------------------------#450--------------------------------------------//
    // TreeNode* root = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, nullptr, new TreeNode(7)));
    // sh::showTree(root);
    // sh::showTree(solution.deleteNode_450(root, 3));
    TreeNode* deleteNode_450(TreeNode* root, int key) {
        TreeNode dum(0, root, nullptr);
        TreeNode* dummy = &dum;

        auto parent = FindNodeToDel(dummy, key);
        if (!parent)
            return root;
        auto el = parent->left and parent->left->val == key ? parent->left : parent->right;


        auto lPart = el->left;
        auto rPart = el->right;
        if (!rPart and !lPart) {
            if (parent->left == el) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        else if (!lPart) {
            *el = *rPart;
        }
        else if (!rPart) {
            *el = *lPart;
        }
        else {
            auto curr = rPart;
            while (curr->left)
                curr = curr->left;

            curr->left = lPart;
            *el = *rPart;
        }
        return dummy->left;
    }
    TreeNode* FindNodeToDel(TreeNode* root, int key) {
        if (!root or (!root->left and !root->right))
            return nullptr;

        auto a = FindNodeToDel(root->left, key);
        if (root->left and root->left->val == key)
            return root;
        if (root->right and root->right->val == key)
            return root;
        auto b = FindNodeToDel(root->right, key);

        return a ? a : b ? b : nullptr;
    }

    //--------------------------#451--------------------------------------------//
    string frequencySort_451(string s) {
        string res;
        unordered_map<char, int> m;
        for (size_t i(0); i < s.size(); i++) {
            m[s[i]]++;
        }
        vector<pair<char, int>> chars(begin(m), end(m));
        sort(begin(chars), end(chars), [](const auto& p1, const auto& p2) {
            return p1.second > p2.second;
            });

        res.reserve(s.size());
        for (size_t i(0); i < chars.size(); i++) {
            auto [el, amt] = chars[i];
            while (amt--) {
                res.push_back(el);
            }
        }

        return res;
    }

    //--------------------------#452--------------------------------------------//
    // vector<vector<int>> points{
    //     {3,9},
    //     {7,12},
    //     {3,8},
    //     {6,8},
    //     {9,10},
    //     {0,9},
    //     {3,9},
    //     {0,6},
    //     {2,8}
    // };
    // sh::Print(solution.findMinArrowShots_452(points));
    int findMinArrowShots_452(vector<vector<int>>& points) {
        std::sort(begin(points), end(points), [](const auto& v1, const auto& v2) {
            return v1[0] < v2[0];
            });
        int res(1);
        auto prev = points[0];
        for (size_t i(1); i < points.size(); i++) {
            if (points[i][0] > prev[1]) {
                res++;
                prev = points[i];
            }
            else {
                prev[0] = std::max(prev[0], points[i][0]);
                prev[1] = std::min(prev[1], points[i][1]);
            }
        }
        return res;
    }

    //--------------------------#453--------------------------------------------//
    int minMoves_453(vector<int>& nums) {
        int min = *std::min_element(begin(nums), end(nums));
        int sum = std::accumulate(begin(nums), end(nums), 0);
        return sum - nums.size() * min;
    }

    //--------------------------#455--------------------------------------------//
    int findContentChildren_455(vector<int>& g, vector<int>& s) {
        int pg(0), ps(0);
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int res(0);
        while (pg != g.size() and ps != s.size()) {
            if (s[ps++] >= g[pg]) {
                res++;
                pg++;
            }
        }
        return res;
    }

    //--------------------------#456--------------------------------------------//
    // vector<int> nums{3,5,0,3,4};
    // sh::Print(solution.find132pattern(nums));
    bool find132pattern_456(vector<int>& nums) {
        vector<int> arr(begin(nums), end(nums));
        for (size_t i(1); i < nums.size(); i++) {
            arr[i] = min(nums[i - 1], arr[i - 1]);
        }

        for (size_t i(nums.size() - 1), top = nums.size(); i + 1 > 0; i--) {
            if (nums[i] <= arr[i])
                continue;
            while (top < nums.size() and arr[top] <= arr[i]) {
                top++;
            }
            if (top < nums.size() && nums[i] > arr[top])
                return true;
            arr[--top] = nums[i];
        }
        return false;
    }

    //--------------------------#457--------------------------------------------//
    bool circularArrayLoop_457(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0;i < n;i++) {
            int slow = i;
            int fast = next(nums, i);
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(nums, fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(nums, slow)) 
                        return true;
                    break;
                }
                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));
            }
        }
        return false;
    }
    int next(vector<int>& nums, int i) {
        int n = nums.size();
        return (((i + nums[i]) % n) + n) % n;
    }

    //--------------------------#459--------------------------------------------//
    bool repeatedSubstringPattern(string s) {
        string concatenated = s + s;
        return concatenated.substr(1, concatenated.length() - 2).find(s) != string::npos;
    }

    //--------------------------#461--------------------------------------------//
    int hammingDistance(int x, int y) {
        // int res(0);
        // for(size_t i(0); i < 32; i++) {
        //     if(((x >> i) & 1) == ((y >> i) & 1))
        //         res++;
        // }
        // return res;

        bitset<32> res(x ^ y);
        return res.count();
    }

    //--------------------------#462--------------------------------------------//
    // vector<int> nums{1,2,3};
    // sh::Print(solution.minMoves2(nums));
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); //Fixing ths median element
        int median = nums[n/2];
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;
    }
};

int main() {
    Solution solution;
    TimeGuard timer("LeetCode_500.cpp");

    


}