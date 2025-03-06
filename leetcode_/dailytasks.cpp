#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

#include <thread>

using namespace std;

//--------------------------#1352-------------------------------------------//
// ProductOfNumbers* obj = new ProductOfNumbers();
// obj->add(7);
// sh::print(obj->getProduct(1));
class ProductOfNumbers
{
    std::vector<int> nums;

public:
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0)
        {
            nums.clear();
        }
        else
        {
            nums.push_back(num * (nums.empty() ? 1 : nums.back()));
        }
    }

    int getProduct(int k) {
        if (k > nums.size())
            return 0;
        if (k == nums.size())
            return nums.back();
        return nums.back() / nums[nums.size() - k - 1];
    }
};

//--------------------------#1261-------------------------------------------//
// TreeNode* root = new TreeNode(-1,
//     new TreeNode(-1,
//         new TreeNode(-1,
//             new TreeNode(-1),
//             new TreeNode(-1)),
//         new TreeNode(-1,
//             nullptr,
//             new TreeNode(-1))
//     ),
//     new TreeNode(-1,
//         nullptr,
//         new TreeNode(-1))
// );
// FindElements* obj = new FindElements(root);
class FindElements
{
    TreeNode* root;
    std::unordered_set<int> values;

    // --Sample
    //         0
    //       /  \
    //      1    2
    //     / \    \
    //    3   4    6
    //   / \   \
    //  7   8   10
    void Restore(TreeNode* node, int parent, bool left) {
        if (!node)
            return;

        node->val = parent * 2 + (left ? 1 : 2);
        values.insert(node->val);
        Restore(node->left, node->val, true);
        Restore(node->right, node->val, false);
    }

public:
    FindElements(TreeNode* root) {
        root->val = 0;
        this->root = root;
        values.insert(0);

        Restore(root->left, root->val, true);
        Restore(root->right, root->val, false);
    }

    bool find(int target) {
        return values.contains(target);
    }
};

class Solution
{
    std::vector<std::pair<int, int>> SHIFTS{
        {-1, 0}, // top
        {1, 0},  // bottom
        {0, -1}, // left
        {0, 1}   // right
    };

public:
    //--------------------------#2657-------------------------------------------//
    // std::vector<int> A{2,3,1};
    // std::vector<int> B{3,1,2};
    // sh::showContainer(solution.findThePrefixCommonArray(A, B));
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        std::vector<int> ans;
        std::unordered_map<int, int> check;

        int tmp(0);
        for (size_t i(0); i != A.size(); ++i)
        {
            if (++check[A[i]] == 2)
                tmp++;
            if (++check[B[i]] == 2)
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
        for (size_t i(31); i + 1 > 0; --i)
        {
            if ((num1 >> i) % 2 == 1)
            {
                if (k != 0)
                    --k;
                else
                    SetBit(ans, i, 0);
            }
        }
        if (k != 0)
        {
            for (size_t i(0); i != 32 and k != 0; ++i)
            {
                int curr = (ans >> i) % 2;
                if (curr == 0)
                {
                    --k;
                    SetBit(ans, i, 1);
                }
            }
        }

        return ans;
    }
    void SetBit(int& num, int shifts, int value) {
        if (value == 1)
        {
            num |= (value << shifts);
        }
        if (value == 0)
        {
            value = ~(1 << shifts);
            num &= value;
        }
    }

    //--------------------------#2425-------------------------------------------//
    int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) {
        int res(0);
        int bitwise2(0);
        for (size_t i(0); i != nums2.size(); ++i)
        {
            bitwise2 ^= nums2[i];
        }
        int n = nums2.size();
        for (size_t i(0); i != nums1.size(); ++i)
        {
            int curr = nums1[i];
            if (n % 2 == 1)
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
        for (size_t i(0); i != derived.size(); ++i)
        {
            if (i == 0)
            {
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
        for (size_t i(0); i != n + m; ++i)
        {
            check[i] = i < n ? m : n;
        }
        std::unordered_map<int, std::pair<int, int>> matrix(n * m);
        for (size_t i(0); i != n; ++i)
        {
            for (size_t j(0); j != m; ++j)
            {
                matrix[mat[i][j]] = { i, j };
            }
        }

        size_t i(0);
        for (; i != arr.size(); ++i)
        {
            if (!--check[matrix[arr[i]].first] || !--check[matrix[arr[i]].second + n])
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
        for (size_t i(0); i != grid[0].size(); ++i)
        {
            top -= grid[0][i];
            res = min(res, max(top, bottom));
            bottom += grid[1][i];
        }
        return res;
    }

    //--------------------------#1765-------------------------------------------//
    // vector<vector<int>> isWater{
    //     {0,1},
    //     {0,0}
    // };
    // sh::showVecVec(solution.highestPeak(isWater));
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> res(isWater.size(), std::vector<int>(isWater[0].size(), INT_MAX));
        std::queue<std::pair<int, int>> q;
        for (size_t i(0); i != isWater.size(); ++i)
        {
            for (size_t j(0); j != isWater[0].size(); ++j)
            {
                if (isWater[i][j] == 1)
                {
                    q.push({ i, j });
                    res[i][j] = 0;
                }
            }
        }

        pair<int, int> curr;
        while (!q.empty())
        {
            curr = q.front();
            q.pop();

            for (size_t i(0); i != SHIFTS.size(); ++i)
            {
                int x = curr.first + SHIFTS[i].first;
                int y = curr.second + SHIFTS[i].second;
                if (!(x < 0 or x >= res.size() or y < 0 or y >= res[0].size()) and res[x][y] > 1 + res[curr.first][curr.second])
                {
                    res[x][y] = 1 + res[curr.first][curr.second];
                    q.push({ x, y });
                }
            }
        }
        return res;
    }

    //--------------------------#1267-------------------------------------------//
    // std::vector<std::vector<int>> grid{
    //     {1,0},
    //     {1,1}
    // };
    // sh::print(solution.countServers(grid));
    int countServers(vector<vector<int>>& grid) {
        std::unordered_map<int, int> check_row(grid.size());
        std::unordered_map<int, int> check_col(grid.size());
        std::vector<std::pair<int, int>> servs;
        int servers(0);
        for (size_t i(0); i != grid.size(); ++i)
        {
            for (size_t j(0); j != grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    check_row[i]++;
                    check_col[j]++;
                    servs.push_back({ i, j });
                }
            }
        }
        for (size_t i(0); i != servs.size(); ++i)
        {
            int x = servs[i].first;
            int y = servs[i].second;
            if (check_row[x] > 1 or check_col[y] > 1)
                ++servers;
        }
        return servers;
    }

    //--------------------------#802--------------------------------------------//
    // std::vector<std::vector<int>> graph{
    //     {1,2},
    //     {2,3},
    //     {5},
    //     {0},
    //     {5},
    //     {},
    //     {}
    // };
    // sh::showContainer(solution.eventualSafeNodes(graph));
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
        std::vector<int> res;
        std::queue<int> q;
        std::vector<std::vector<int>> gr(graph.size());
        std::vector<int> sizes(graph.size(), 0), safe(graph.size());
        for (size_t i(0); i != graph.size(); ++i)
        {
            for (size_t j(0); j != graph[i].size(); ++j)
            {
                gr[graph[i][j]].push_back(i);
            }
            sizes[i] = graph[i].size();
            if (sizes[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            safe[curr] = 1;
            for (const auto& v : gr[curr])
            {
                if (--sizes[v] == 0)
                    q.push(v);
            }
        }
        for (size_t i(0); i != graph.size(); ++i)
        {
            if (safe[i])
                res.push_back(i);
        }
        return res;
    }

    //--------------------------#1462-------------------------------------------//
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        bitset<100> rpath[100] = { 0 };
        vector<char> adj[100];

        char deg[100] = { 0 }; // indegree
        for (auto& e : prerequisites)
        {
            char a = e[0], b = e[1];
            adj[a].push_back(b);
            rpath[b][a] = 1;
            deg[b]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0)
                q.push(i); // deg 0 nodes

        while (!q.empty())
        {
            auto i = q.front();
            q.pop();
            for (int j : adj[i])
            {
                rpath[j] |= rpath[i];
                if (--deg[j] == 0)
                    q.push(j);
            }
        }
        const int m = queries.size();
        vector<bool> ans(m, 0);
        for (int i = 0; i < m; i++)
            ans[i] = rpath[queries[i][1]][queries[i][0]];
        return ans;
    }

    //--------------------------#2658-------------------------------------------//
    // vector<vector<int>> grid{
    //     {0, 6, 0}
    // };
    // sh::print(solution.findMaxFish(grid));
    int findMaxFish(vector<vector<int>>& grid) {
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        int fish(0);
        for (size_t i(0); i != grid.size(); ++i)
        {
            for (size_t j(0); j != grid[0].size(); ++j)
            {
                if (!visited[i][j] and grid[i][j] > 0)
                {
                    fish = std::max(fish, ToFish(grid, visited, { i, j }));
                }
            }
        }
        return fish;
    }
    int ToFish(vector<vector<int>>& grid, std::vector<std::vector<bool>>& visited, std::pair<int, int> start) {
        queue<std::pair<int, int>> q;
        q.push(start);
        int fish(0);

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            visited[x][y] = true;
            fish += grid[x][y];

            for (size_t i(0); i != SHIFTS.size(); ++i)
            {
                int x_ = x + SHIFTS[i].first;
                int y_ = y + SHIFTS[i].second;
                if (x_ >= 0 and x_ < grid.size() and y_ >= 0 and y_ < grid[0].size() and grid[x_][y_] > 0 and !visited[x_][y_])
                {
                    q.push({ x_, y_ });
                    visited[x_][y_] = true;
                }
            }
        }
        return fish;
    }

    //--------------------------#684--------------------------------------------//
    // std::vector<std::vector<int>> v{
    //     {1,2},
    //     {1,3},
    //     {2,3}
    // };
    // sh::showContainer(solution.findRedundantConnection(v));
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        vector<bool> visited(N, false);
        vector<int> parent(N, -1);

        vector<int> adjList[N];
        for (auto edge : edges)
        {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        DFS(0, visited, adjList, parent);

        unordered_map<int, int> cycleNodes;
        int node = cycleStart;
        // Start from the cycleStart node and backtrack to get all the nodes in
        // the cycle. Mark them all in the map.
        do
        {
            cycleNodes[node] = 1;
            node = parent[node];
        } while (node != cycleStart);

        // If both nodes of the edge were marked as cycle nodes then this edge
        // can be removed.
        for (int i = edges.size() - 1; i >= 0; i--)
        {
            if (cycleNodes[edges[i][0] - 1] && cycleNodes[edges[i][1] - 1])
            {
                return edges[i];
            }
        }

        return {};
    }
    int cycleStart = -1;
    void DFS(int src, vector<bool>& visited, vector<int> adjList[], vector<int>& parent) {
        visited[src] = true;

        for (int adj : adjList[src])
        {
            if (!visited[adj])
            {
                parent[adj] = src;
                DFS(adj, visited, adjList, parent);
                // If the node is visited and the parent is different then the
                // node is part of the cycle.
            }
            else if (adj != parent[src] && cycleStart == -1)
            {
                cycleStart = adj;
                parent[adj] = src;
            }
        }
    }

    //--------------------------#3174-------------------------------------------//
    // sh::print(solution.clearDigits("asabc123"));
    std::string clearDigits(std::string s) {
        std::string res;
        int tmp(0);

        for (size_t i(s.size() - 1); i + 1 > 0; --i)
        {
            if (std::isdigit(s[i]))
            {
                tmp++;
            }
            else if (tmp == 0)
            {
                res.push_back(s[i]);
            }
            else
            {
                --tmp;
            }
        }
        std::reverse(std::begin(res), std::end(res));
        return res;
    }

    //--------------------------#1910-------------------------------------------//
    // sh::print(solution.removeOccurrences("daabcbaabcbc", "abc"));
    string removeOccurrences(string s, string part) {
        string x = s;
        int n = s.size(), m = part.size(), i, j;
        for (i = 0, j = 0; i < n; i++)
        {
            x[j++] = s[i];
            if (j >= m && x.substr(j - m, m) == part)
                j -= m;
        }
        return x.substr(0, j);
    }

    //--------------------------#2342-------------------------------------------//
    // std::vector<int> nums{18,43,36,13,7};
    // sh::print(solution.maximumSum(nums));
    int maximumSum(vector<int>& nums) {
        std::map<int, int> m;
        int res(-1);
        for (size_t i(0); i != nums.size(); ++i)
        {
            int digits_sum(0);
            int x(nums[i]);
            while (x)
            {
                digits_sum += x % 10;
                x /= 10;
            }
            auto [exist_el, inserted] = m.insert({ digits_sum, nums[i] });
            if (!inserted)
            {
                if (exist_el->second + nums[i] > res)
                    res = exist_el->second + nums[i];
                if (nums[i] > exist_el->second)
                    exist_el->second = nums[i];
            }
            else
            {
                exist_el->second = nums[i];
            }
        }
        return res;
    }

    //--------------------------#2208-------------------------------------------//
    // std::vector<int> nums{1,1,1};
    // sh::print(solution.halveArray(nums));
    int halveArray(vector<int>& nums) {
        std::priority_queue<double> pq;
        double sum(0);
        for (size_t i(0); i != nums.size(); ++i)
        {
            sum += nums[i];
            pq.push(nums[i]);
        }
        int c(0);
        double target = sum / 2;
        while (sum > target)
        {
            double curr = pq.top() / 2;
            pq.pop();
            sum -= curr;
            pq.push(curr);
            ++c;
        }
        return c;
    }

    //--------------------------#3066-------------------------------------------//
    // std::vector<int> nums{999999999,999999999,999999999};
    // sh::print(solution.minOperations(nums, 1000000000));
    int minOperations(vector<int>& nums, int k) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq(std::begin(nums), std::end(nums));
        int n(0);
        while (pq.top() < k)
        {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();

            pq.push(x * 2 + y);
            ++n;
        }
        return n;
    }

    //--------------------------#1079-------------------------------------------//
    // std::string s("AAB");
    // sh::print(solution.numTilePossibilities(s));
    int numTilePossibilities(string tiles) {
        std::vector<int> charCount(26, 0);
        int sz(0);
        for (char ch : tiles)
        {
            if (++charCount[ch - 'A'] == 1)
                ++sz;
        }
        std::sort(std::begin(charCount), std::end(charCount), std::greater<int>());
        charCount.resize(sz);
        return buildChar(charCount);
    }
    int buildChar(std::vector<int> charCount) {
        int totalCount = 0;
        for (int i = 0; i < charCount.size(); i++)
        {
            if (charCount[i])
            {
                totalCount++;
                charCount[i]--;
                totalCount += buildChar(charCount);
                charCount[i]++;
            }
        }
        return totalCount;
    }

    //--------------------------#2375-------------------------------------------//
    // sh::print(solution.smallestNumber("IIIDIDDD"));
    string smallestNumber(string pattern) {
        std::vector<int> st(pattern.size() + 1);
        string res;
        int ind(0);
        for (size_t i(0); i <= pattern.size(); ++i)
        {
            st[ind++] = i + 1;

            if (i == pattern.size() or pattern[i] == 'I')
            {
                while (ind > 0)
                {
                    res += to_string(st[--ind]);
                }
            }
        }
        return res;
    }

    //--------------------------#1415-------------------------------------------//
    // sh::print(solution.getHappyString(3, 9));
    string getHappyString(int n, int k) {
        std::vector<char> chars{ 'a', 'b', 'c' };
        string curr;
        int res(0);
        GenerateABC(n, k, res, curr, chars, -1);
        return curr;

        // if (k > (3 << (n - 1))) return ""; // Check if k is out of bounds
        // queue<string> q;
        // q.push("");  // Start with an empty string
        // while (k) {
        //     string curr = q.front();
        //     q.pop();
        //     for (char c = 'a'; c <= 'c'; c++) {
        //         if (curr.empty() || curr.back() != c) {
        //             q.push(curr + c);
        //             if (curr.size() + 1 == n) k--;
        //         }
        //         if (k == 0) break;
        //     }
        // }
        // return q.back();
    }
    void GenerateABC(const int n, const int k, int& res, string& curr, const std::vector<char>& chars, int j) {
        if (curr.size() == n)
        {
            ++res;
            return;
        }

        for (size_t i(0); i != chars.size(); ++i)
        {
            if (i == j)
                continue;

            curr.push_back(chars[i]);
            GenerateABC(n, k, res, curr, chars, i);
            if (res == k)
            {
                return;
            }
            curr.pop_back();
        }
    }

    //--------------------------#1980-------------------------------------------//
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        res.reserve(nums[0].size());

        for (size_t i(0); i != nums.size(); ++i)
        {
            res.push_back(nums[i][i] == '0' ? '1' : '0');
        }
        return res;
    }

    //--------------------------#1524-------------------------------------------//
    // vector<int> arr{1,3,5};
    // sh::print(solution.numOfSubarrays(arr));
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1000000007;
        int odd = 0, even = 1;
        int result = 0;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum % 2 == 1)
            {
                result = (result + even) % MOD;
                odd++;
            }
            else
            {
                result = (result + odd) % MOD;
                even++;
            }
        }

        return result;
    }

    //--------------------------#1749-------------------------------------------//
    // vector<int> nums{1,-3,2,3,-4};
    // sh::print(solution.maxAbsoluteSum(nums));
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, minSum = 0, maxSum = 0;
        for (int num : nums)
        {
            sum += num;
            if (sum > maxSum)
                maxSum = sum;
            if (sum < minSum)
                minSum = sum;
        }
        return abs(maxSum - minSum);
    }

    //--------------------------#873--------------------------------------------//
    // vector<int> arr{1,2,3,4,5,6,7};
    // sh::print(solution.lenLongestFibSubseq(arr));
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxLen = 0;
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        unordered_map<int, int> valToIdx;

        for (int curr = 0; curr < arr.size(); curr++)
        {
            valToIdx[arr[curr]] = curr;
            for (int prev = 0; prev < curr; prev++)
            {
                int diff = arr[curr] - arr[prev];
                int prevIdx = (valToIdx.find(diff) != valToIdx.end())
                    ? valToIdx[diff]
                    : -1;

                if (diff < arr[prev] && prevIdx >= 0)
                {
                    dp[prev][curr] = dp[prevIdx][prev] + 1;
                }
                else
                {
                    dp[prev][curr] = 2;
                }

                maxLen = max(maxLen, dp[prev][curr]);
            }
        }

        return maxLen > 2 ? maxLen : 0;
    }

    //--------------------------#2161-------------------------------------------//
    // std::vector<int> nums{9,12,5,10,14,3,10};
    // sh::showContainer(solution.pivotArray(nums, 10));
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        for (int dist{ 2 }; dist < 2 * size(nums); dist <<= 1)
        {
            for (auto b{ begin(nums) }, m{ b }, e{ b }; b < end(nums); b = e)
            {
                m = min(b + dist / 2, end(nums)),
                    e = min(b + dist, end(nums));
                auto l = lower_bound(b, m, pivot);
                auto h = upper_bound(m, e, pivot);
                std::rotate(l, m, h);
            }
        }
        return nums;
    }

    //--------------------------#1780-------------------------------------------//
    bool checkPowersOfThree(int n) {
        while (n > 0)
        {
            if (n % 3 == 2)
            {
                return false;
            }
            n /= 3;
        }
        return true;
    }

    //--------------------------#2579-------------------------------------------//
    long long coloredCells(int n) {
        return 1 + (4 + 4 * (n - 1)) / 2 * (n - 1);
    }

    //--------------------------#2965-------------------------------------------//
    // vector<vector<int>> grid{
    //     {1,3},
    //     {2,2}
    // };
    // sh::showContainer(solution.findMissingAndRepeatedValues(grid));
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> st;
        vector<int> res(2);
        int n = grid.size();
        int sum(0);
        for (auto& row : grid) {
            for (auto& val: row){
                if(st.contains(val)){
                    res[0] = val;
                } else {
                    st.insert(val);
                    sum += val;
                }
            }
        }
        res[1] = ((1. + n * n) / 2 * n * n) -  sum;
        return res;
    }
};

int main() {
    Solution solution;
    Timer timer("DailyTasksLeetcode.cpp");

    
}