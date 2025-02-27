#include "ForLeetcode.h"
#include "show.h"
#include "timer.h"

class Solution
{
public:
    //--------------------------#2----------------------------------------------//
    // // --2
    // ListNode l1(9, (new ListNode(9, (new ListNode(9,(new ListNode(9,(new ListNode(9,(new ListNode(9,(new ListNode(9,(new ListNode(9)))))))))))))));
    // ListNode l2(9, new ListNode(9, new ListNode(9,(new ListNode(9)))));
    // sh::showList(&l1);
    // sh::showList(&l2);
    // solution.addTwoNumbers_2(&l1, &l2);
    ListNode *addTwoNumbers_2(ListNode *l1, ListNode *l2)
    {
        /*ListNode* ans = new ListNode();
        ListNode* head = ans;
        ListNode* prev;
        int transfer(0);
        while (l1 != nullptr or l2 != nullptr or transfer != 0)
        {
            ans->next = new ListNode();
            if(l1 == nullptr and l2 == nullptr and transfer != 0){
                ans->val = transfer--;

            }else if(l1 != nullptr and l2 != nullptr){
                ans->val = (l1->val + l2->val + transfer) % 10 ;
                transfer = (l1->val + l2->val + transfer) / 10;

                l1 = l1->next;
                l2 = l2->next;
            }else if(l1 != nullptr and l2 == nullptr){
                ans->val = (l1->val + transfer) % 10;
                transfer = (l1->val + transfer) / 10;

                l1 = l1->next;
            }else if(l1 == nullptr and l2 != nullptr){
                ans->val = (l2->val + transfer) % 10;
                transfer = (l2->val + transfer) / 10;

                l2 = l2->next;
            }
            prev = ans;
            ans = ans->next;
        }
        prev->next = nullptr;
        prev = nullptr;
        ans  = nullptr;
        return head;*/
        int sum = 0;
        ListNode *l3 = nullptr;
        ListNode **node = &l3;
        while (l1 != NULL || l2 != NULL || sum > 0)
        {
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            (*node) = new ListNode(sum % 10);
            sum /= 10;
            node = &((*node)->next);
        }
        return l3;
    }

    //--------------------------#3----------------------------------------------//
    // --3
    // std::cout << solution.lengthOfLongestSubstring_3("pwwkew") << std::endl;
    int lengthOfLongestSubstring_3(std::string s)
    {
        // std::map<char, int> chars;
        // int len(0), i(0);
        // int curr_len(0);
        // for(const auto &a: s){
        //     if(!chars.contains(a)){
        //         chars.insert(std::pair<char,int>(a, i++));
        //         curr_len++;
        //         if(len < curr_len)
        //             len = curr_len;
        //         continue;
        //     }
        //     curr_len = 0;
        //     for(auto entry: chars){
        //         if(entry.first != a){
        //             chars.erase(a);
        //             continue;
        //         }
        //         break;
        //     }
        //     //chars[a] = i++;
        //     chars.insert(std::pair<char,int>(a, i++));
        // }
        // return chars.size();
        int left = 0;
        int maxLength = 0;
        std::unordered_set<char> charSet;

        for (int right = 0; right < s.length(); right++)
        {
            while (charSet.contains(s[right]))
            {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }

    //--------------------------#5----------------------------------------------//
    // // --5
    // std::string str = "gccghj";
    // std::cout << solution.longestPalindrome_5(str) << std::endl;
    std::string longestPalindrome_5(std::string s)
    {
        /*int n = s.size();
        std::vector<std::vector<bool>> m(n,std::vector<bool>(n));
        int l(0), r(0);

        // init
        for(int i(0); i < n - 1; i++){
            m[i][i] = true;
            if(s[i] == s[i+1]){
                m[i][i+1] = true;
                l = i;
                r = i+1;
            }
        }
        m[n-1][n-1] = true;

        // solution
        for (int len(2); len < n; len++){
            for (int i(0); i < n - len ; i++){
                if(m[i+1][i + len - 1] && (s[i] == s[i+len])){
                    m[i][i + len] = true;
                    l = i;
                    r = i + len;
                }
            }
        }
        return s.substr(l,r - l + 1);*/
        std::string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            std::string odd = expand_5(i, i, s);
            if (odd.size() > ans.size())
            {
                ans = odd;
            }

            std::string even = expand_5(i, i + 1, s);
            if (even.size() > ans.size())
            {
                ans = even;
            }
        }

        return ans;
    }

    //--------------------------#7----------------------------------------------//
    // // --7
    // std::cout << solution.reverse_7(96463243) << std::endl;
    int reverse_7(int x)
    {
        int ans(0), i(0);
        while (x != 0)
        {
            if (ans >= INT_MAX / 10)
                return 0;
            ans *= 10;
            ans += (x % 10);
            x /= 10;
            i++;
        }
        return ans;
    }

    //--------------------------#9----------------------------------------------//
    // // --9
    // std::cout << std::boolalpha << solution.isPalindrome_9(12321) << std::endl;
    bool isPalindrome_9(int x)
    {
        std::string str = std::to_string(x);
        int l(0), r(str.size() - 1);
        while (l < r)
        {
            if (str[l] == str[r])
            {
                l++;
                r--;
                continue;
            }
            return false;
        }
        return true;
    }

    //--------------------------#11---------------------------------------------//
    // // --11
    // std::vector<int> vec{1,1,1,1,8,1,1,1,1,1,1,1,1,1};
    // std::cout << solution.maxArea_11(vec) << std::endl;
    int maxArea_11(std::vector<int> &h)
    {
        int l(0), r(h.size() - 1), maxArea(0), curr_h;
        while (l < r)
        {
            curr_h = std::min(h[l], h[r]);
            maxArea = std::max(maxArea, curr_h * (r - l));
            h[l] > h[r] ? r-- : h[l] < h[r] ? l++
                                            : r--,
                l++;
        }
        return maxArea;
    }

    //--------------------------#8----------------------------------------------//
    // // --8
    // std::cout << solution.myAtoi_8("1337c0d3") << std::endl;
    int myAtoi_8(std::string s)
    {
        int ans(0);

        std::string number;
        std::smatch res;
        const std::regex reg_valid(R"((^\s*)([-+]?[0-9]+))");

        if (std::regex_search(s, res, reg_valid))
        {
            number = res[2];
            int start;
            int sign;
            if (number[0] == '-')
            {
                sign = -1;
                start = 1;
            }
            else if (number[0] == '+')
            {
                sign = 1;
                start = 1;
            }
            else
            {
                sign = 1;
                start = 0;
            }
            for (int i(start); i < number.size(); i++)
            {
                int pop = (number[i] - 48);
                if ((ans > INT_MAX / 10) or ((ans == INT_MAX / 10) and ((sign == 1 and pop > 7) or (sign == -1 and pop > 8))))
                {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                ans = ans * 10 + pop;
            }
            ans *= sign;
        }
        return ans;
    }

    //--------------------------#6----------------------------------------------//
    // // --6
    // std::cout << solution.convert_6("PAYPALISHIRING", 4) << std::endl;
    std::string convert_6(std::string s, int numRows)
    {
        std::string ans;
        ans.reserve(s.size() - 1);
        if (numRows == 1)
            return s;

        int step(0);
        bool rotation(true);
        for (int i(0); i < numRows; i++)
        {
            for (int j(i); j < s.size();)
            {
                ans += (s[j]);
                rotation = (rotation ? false : true);
                step = (!rotation ? ((numRows - 1) - (i % (numRows - 1))) * 2 : ((numRows - 1) - ((numRows - i - 1) % (numRows - 1))) * 2);
                j += step;
            }
            rotation = true;
        }
        return ans;
    }

    //--------------------------#15---------------------------------------------//
    // std::vector<int> vec{-3,4,8,1,-4,7,5,3};
    // solution.threeSum_15(vec);
    std::vector<std::vector<int>> threeSum_15(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());

        int l, r;
        for (int i(0); i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            l = i + 1;
            r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (nums[l] == nums[l - 1] && l < r)
                    {
                        l++;
                    }
                    continue;
                }
                if (sum > 0)
                    r--;
                if (sum < 0)
                    l++;
            }
        }
        return ans;
    }

    //--------------------------#4----------------------------------------------//
    // // --4
    // std::vector<int> a{};
    // std::vector<int> b{1};
    // std::cout << solution.findMedianSortedArrays_4(a, b) << std::endl;
    double findMedianSortedArrays_4(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        int l(0), r(0);
        int curr = INT_MIN, prev;
        int len = (nums1.size() + nums2.size()) / 2 + 1;
        for (int i(0); i < len; i++)
        {
            if (l < nums1.size() && r < nums2.size())
            {
                if (nums1[l] > nums2[r])
                {
                    prev = curr;
                    curr = nums2[r];
                    r++;
                    continue;
                }
                if (nums1[l] <= nums2[r])
                {
                    prev = curr;
                    curr = nums1[l];
                    l++;
                }
            }
            else if (l < nums1.size())
            {
                prev = curr;
                curr = nums1[l];
                l++;
            }
            else if (r < nums2.size())
            {
                prev = curr;
                curr = nums2[r];
                r++;
            }
        }
        if ((nums1.size() + nums2.size()) % 2 == 1)
            return curr;
        return (curr + prev) / 2.;
    }

    //--------------------------#17---------------------------------------------//
    // // --17
    // std::vector<std::string> str = solution.letterCombinations_17("23");
    // for (auto &i : str)
    //     std::cout << i << ", ";
    std::vector<std::string> letterCombinations_17(std::string digits)
    {
        std::vector<std::string> ans;
        std::vector<std::string> vec_str;
        int start;
        std::string temp("");
        if (digits.size() == 0)
            return {};

        for (const auto &d : digits)
        {
            start = 'a' + (d - '2') * 3;
            if (d == '8' || d == '9')
                start++;
            temp.push_back(start);
            temp.push_back(start + 1);
            temp.push_back(start + 2);
            if ((d == '7') || (d == '9'))
                temp.push_back(start + 3);

            vec_str.push_back(temp);
            temp.clear();
        }
        if (digits.size() == 1)
        {
            for (const auto &t : vec_str[0])
                ans.push_back({t});
            return ans;
        }

        int j(0);
        solve_17(ans, vec_str, temp, j);
        return ans;
    }

    //--------------------------#19---------------------------------------------//
    // // --19
    // ListNode* l1 = new ListNode(1, (new ListNode(2, (new ListNode(3,(new ListNode(4,(new ListNode(5,(new ListNode(6,(new ListNode(7,(new ListNode(8)))))))))))))));
    // sh::showList(l1);
    // l1 = solution.removeNthFromEnd_19(l1, 8);
    // l1 = solution.removeNthFromEnd_19(l1, 6);
    // sh::showList(l1);
    ListNode *removeNthFromEnd_19(ListNode *head, int n)
    {
        ListNode *h = head;
        ListNode *prev = h;
        ListNode *next_node = h;
        ListNode *to_del;

        int i(0);
        while (h != nullptr)
        {
            if (i <= n)
            {
                i++;
                h = h->next;
                continue;
            }
            prev = prev->next;
            h = h->next;
            i++;
        }
        if (i == n)
        {
            to_del = head;
            head = head->next;
            to_del->next = nullptr;
            delete to_del;

            return head;
        }

        next_node = prev->next->next;
        to_del = prev->next;
        prev->next = next_node;

        to_del->next = nullptr;
        delete to_del;

        return head;
    }

    //--------------------------#24---------------------------------------------//
    // // --24
    // ListNode* l1 = new ListNode(1, (new ListNode(2, (new ListNode(3,(new ListNode(4,(new ListNode(5,(new ListNode(6,(new ListNode(7,(new ListNode(8)))))))))))))));
    // ListNode* l2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    // sh::showList(l2);
    // l2 = solution.swapPairs_24(l2);
    // sh::showList(l2);
    // sh::showList(l1);
    // l1 = solution.swapPairs_24(l1);
    // sh::showList(l1);
    ListNode *swapPairs_24(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *next_pair;
        ListNode *first = head;
        ListNode *second = head->next;
        head = second;

        while (second != nullptr)
        {
            next_pair = second->next;

            second->next = first;
            first->next = (next_pair == nullptr ? nullptr : next_pair->next == nullptr ? next_pair
                                                                                       : next_pair->next);

            first = next_pair;
            second = next_pair != nullptr ? next_pair->next : nullptr;
        }
        return head;
    }

    //--------------------------#23---------------------------------------------//
    // // -- 23
    // ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    // ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    // ListNode* l3 = new ListNode(2, new ListNode(6));
    // sh::showList(l1);
    // sh::showList(l2);
    // sh::showList(l3);
    // std::vector<ListNode*> list = {l1, l2, l3};
    // ListNode* l4 = solution.mergeKLists_23(list);
    // sh::showList(l4);
    ListNode *mergeKLists_23(std::vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return {};
        if (lists.size() == 1)
            return lists[0];

        ListNode *ans = new ListNode(-999);
        ListNode *curr_el = ans;
        int j(0);

        while (true)
        {
            ListNode *next_el = lists[0];
            j = 0;
            for (const auto &t : lists)
            {
                if (t != nullptr)
                {
                    next_el = t;
                    break;
                }
                j++;
            }
            if (next_el == nullptr)
                break;

            for (int i(1); i < lists.size(); i++)
            {
                if (lists[i] == nullptr)
                    continue;
                if (next_el->val > lists[i]->val)
                {
                    next_el = lists[i];
                    j = i;
                }
            }
            curr_el->next = next_el;
            curr_el = curr_el->next;
            lists[j] = lists[j]->next;
        }
        return ans->next;
    }

    //--------------------------#31---------------------------------------------//
    // // --31
    // std::vector<int> vec{2,3,1,3,3};
    // sh::showContainer(vec);
    // solution.nextPermutation_31(vec);
    // sh::showContainer(vec);
    void nextPermutation_31(std::vector<int> &nums)
    {
        int l = nums.size() - 2, r = nums.size() - 1;
        int i(0);
        for (; i < nums.size() - 1; i++)
        {
            if (nums[r] > nums[l])
            {
                if (i == 0)
                {
                    swap(nums, r, l);
                    return;
                }
                break;
            }
            if (nums[r] <= nums[l])
            {
                l--;
                r--;
            }
        }
        if (i == nums.size() - 1)
        {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        int to_swap = r; // min
        for (int j(r); j < nums.size(); j++)
        {
            if ((nums[j] <= nums[to_swap]) and nums[j] > nums[l])
                to_swap = j;
        }
        swap(nums, l, to_swap);
        l++;
        std::reverse(nums.begin() + l, nums.end());
    }

    //--------------------------#34---------------------------------------------//
    // --34
    // std::vector<int> vec{1,2};
    // sh::showContainer(vec);
    // sh::showContainer(solution.searchRange_34(vec,2));
    std::vector<int> searchRange_34(std::vector<int> &nums, int target)
    {
        return {binarySearch_l(nums, target), binarySearch_r(nums, target)};
    }

    //--------------------------#33---------------------------------------------//
    // --33
    // std::vector<int> vec{4,5,6,7,0,1,2};
    // sh::showContainer(vec);
    // std::cout << solution.search_33(vec,0);
    int search_33(std::vector<int> &nums, int target)
    {
        int gap = binarySearchGap(nums);
        if (gap == -1)
            return binarySearch(nums, target);

        int v1 = binarySearchRange(nums, target, 0, gap - 1);
        int v2 = binarySearchRange(nums, target, gap, nums.size() - 1);
        return std::max(v1, v2);
    }

    //--------------------------#36---------------------------------------------//
    // // --36
    // std::vector<std::vector<char>> board =
    // {{'.','.','4', '.','.','.', '6','3','.'},
    // {'.','.','.', '.','.','.', '.','.','.'},
    // {'5','.','.', '.','.','.', '.','9','.'},
    // {'.','.','.', '5','6','.', '.','.','.'},
    // {'4','.','3', '.','.','.', '.','.','1'},
    // {'.','.','.', '7','.','.', '.','.','.'},
    // {'.','.','.', '5','.','.', '.','.','.'},
    // {'.','.','.', '.','.','.', '.','.','.'},
    // {'.','.','.', '.','.','.', '.','.','.'}};
    // std::cout <<  std::boolalpha << solution.isValidSudoku_36(board);
    bool isValidSudoku_36(std::vector<std::vector<char>> &board)
    {
        bool row = rowValid(board);
        bool col = collValid(board);
        bool sq = squareValid(board);
        if (row && col && sq)
            return true;
        return false;
    }

    //--------------------------#38---------------------------------------------//
    // --38
    // std::cout << solution.countAndSay_38(5) << std::endl;
    std::string countAndSay_38(int n)
    {
        return RLE(n);
    }
    std::string RLE(int n)
    {
        if (n == 1)
            return "1";
        if (n == 2)
            return "11";

        std::string curr = RLE(n - 1);
        std::string ans("");
        ans.reserve(curr.size());
        int count(1);
        char h = curr[0];
        for (int i(1); i < curr.size(); i++)
        {
            if (h != curr[i])
            {
                ans += std::to_string(count) + h;
                count = 1;
                h = curr[i];
            }
            else
            {
                count++;
            }

            if (i == curr.size() - 1)
            {
                ans += std::to_string(count) + h;
            }
        }
        return ans;
    }

    //--------------------------#41---------------------------------------------//
    // std::vector<int> vec{1,1};
    // sh::showContainer(vec);
    // std::cout << solution.firstMissingPositive_41(vec) << std::endl;
    int firstMissingPositive_41(std::vector<int> &nums)
    {
        int index;
        for (int i(0); i < nums.size(); i++)
        {
            index = nums[i] - 1;
            if (index >= 0 and index < nums.size() and index != i and nums[index] != nums[i])
            {
                swap(nums, index, i);
                i--;
            }
        }
        for (int i(0); i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }

    //--------------------------#45---------------------------------------------//
    // std::vector<int> nums{1,1,1,1};
    // std::cout << solution.jump_45(nums) << std::endl;
    int jump_45(std::vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;

        int steps(0);
        int i(0);

        while (i != nums.size() - 1)
        {
            int curr_step(i + 1); // index
            int max(1 + nums[i + 1]);
            int j(i + 1);
            for (; j < i + nums[i] + 1; j++)
            {
                if (j > (nums.size() - 1))
                    break;

                if (j == nums.size() - 1)
                    return ++steps;

                if (j - i + nums[j] > max)
                {
                    max = j - i + nums[j];
                    curr_step = j;
                }
            }
            steps++;
            i = curr_step;
        }
        return steps;
    }

    //--------------------------#14---------------------------------------------//
    // std::vector<std::string> vec{"abab","aba",""};
    // std::cout << solution.longestCommonPrefix_14(vec) << std::endl;
    std::string longestCommonPrefix_14(std::vector<std::string> &strs)
    {
        if (strs.size() == 0)
            return {};

        std::string res(strs[0]);
        for (int i(1); i < strs.size(); i++)
        {
            int size = (strs[0].size() < strs[i].size() ? strs[0].size() : strs[i].size());
            if (size == 0)
                return {};
            for (int j(0); j < size; j++)
            {
                if (res[j] == strs[i][j])
                {
                    if (j == size - 1 and res.size() > j)
                    {
                        res.erase(res.begin() + j + 1, res.end());
                    }
                    continue;
                }
                res.erase(res.begin() + j, res.end());
                break;
            }
        }
        return res;
    }

    //--------------------------#42---------------------------------------------//
    // //[0,1,0,2,1,0,1,3,2,1,2,1]
    // std::vector<int> vec{9,8,9,5,8,8,8,0,4};
    // sh::showContainer(vec);
    // std::cout << solution.trap_42(vec) << std::endl;
    int trap_42(std::vector<int> &height)
    {
        if (height.size() < 3)
            return {};

        std::vector<int> peaks;
        int max(0);
        for (int i(0); i < height.size(); i++)
        {
            // begin
            if (i == 0)
            {
                if (height[i] > height[i + 1])
                {
                    peaks.push_back(i);
                    max = (height[max] >= height[i] ? max : i);
                    continue;
                }
                if (height[i] == height[i + 1])
                {
                    int st(i);
                    while (i != height.size() - 1 and height[i] == height[i + 1])
                    {
                        i++;
                    }
                    if (i == height.size() - 1)
                    {
                        return {};
                    }
                    if (height[i] > height[i + 1])
                    {
                        peaks.push_back(i);
                        max = (height[max] >= height[i] ? max : i);
                        i++;
                    }
                    continue;
                }
                continue;
            }

            // end
            if (i == height.size() - 1 and height[i] > height[i - 1])
            {
                peaks.push_back(i);
                max = (height[max] >= height[i] ? max : i);
                continue;
            }

            // middle
            if (height[i] > height[i - 1] and height[i] > height[i + 1])
            {
                peaks.push_back(i);
                max = (height[max] >= height[i] ? max : i);
                continue;
            }
            if (height[i] > height[i - 1] and height[i] == height[i + 1])
            {
                int st(i);
                while (i != height.size() - 1 and height[i] == height[i + 1])
                {
                    i++;
                }
                if (i == height.size() - 1)
                {
                    peaks.push_back(st);
                    max = (height[max] >= height[i] ? max : i);
                    continue;
                }
                if (height[i] > height[i + 1])
                {
                    peaks.push_back(st);
                    peaks.push_back(i);
                    max = (height[max] >= height[i] ? max : i);
                    i++;
                }
            }
        }
        if (peaks.size() <= 1)
            return {};

        // optimization
        std::vector<int> opt_peaks;
        opt_peaks.push_back(peaks[0]);
        int sec_p(0);
        for (int i(1); i < peaks.size(); i++)
        {
            if (peaks[i] > max)
                break;
            if (height[peaks[i]] < height[peaks[sec_p]] and height[peaks[i]] < height[max])
                continue;
            if (height[peaks[i]] >= height[peaks[sec_p]])
            {
                opt_peaks.push_back(peaks[i]);
                sec_p = i;
            }
        }
        std::vector<int> temp;
        sec_p = peaks.size() - 1;
        if (peaks[sec_p] != max)
            temp.push_back(peaks[sec_p]);
        for (int i(peaks.size() - 2); i >= 0; i--)
        {
            if (peaks[i] <= max)
                break;
            if (height[peaks[i]] < height[peaks[sec_p]] and height[peaks[i]] < height[max])
                continue;
            if (height[peaks[i]] >= height[peaks[sec_p]])
            {
                temp.push_back(peaks[i]);
                sec_p = i;
            }
        }
        std::reverse(temp.begin(), temp.end());
        opt_peaks.insert(opt_peaks.end(), temp.begin(), temp.end());

        // count water
        int res{};
        for (int i(0); i < opt_peaks.size() - 1; i++)
        {
            res += countWater_42(height, opt_peaks[i], opt_peaks[i + 1]);
        }
        return res;
    }

    //--------------------------#21---------------------------------------------//
    // ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    // sh::showList(l1);
    // ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    // sh::showList(l2);
    // solution.mergeTwoLists(l1, l2);
    // sh::showList(l1);
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode();
        ListNode *head = dummy;
        while (list1 != nullptr or list2 != nullptr)
        {
            if (list1 == nullptr)
            {
                head->next = list2;
                list2 = list2->next;
                head = head->next;
                continue;
            }
            if (list2 == nullptr)
            {
                head->next = list1;
                list1 = list1->next;
                head = head->next;
                continue;
            }
            if (list1->val >= list2->val)
            {
                head->next = list2;
                list2 = list2->next;
                head = head->next;
                continue;
            }
            head->next = list1;
            list1 = list1->next;
            head = head->next;
        }
        return dummy->next;
    }

    //--------------------------#27---------------------------------------------//
    // std::vector<int> vec{3,2,2,3};
    // solution.removeElement(vec, 3);
    int removeElement(std::vector<int> &nums, int val)
    {
        int count(0);
        for (int i(0); i < nums.size() - count; i++)
        {
            if (nums[i] == val)
            {
                count++;
                std::swap(nums[i], nums[nums.size() - count]);
                i--;
            }
        }
        nums.erase(nums.end() - count, nums.end());
        return nums.size();
    }

    //--------------------------#49---------------------------------------------//
    // std::vector<std::string> strs{"eat","tea","tan","ate","nat","bat"};
    // sh::showContainer(strs);
    // sh::showVecVec(solution.groupAnagrams(strs));
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        if (strs.size() == 0)
            return {};
        if (strs.size() == 1)
            return {{strs[0]}};

        std::unordered_map<std::string, std::vector<std::string>> mp;
        for (auto x : strs)
        {
            std::string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }

        std::vector<std::vector<std::string>> ans;
        for (auto x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }

    //--------------------------#26---------------------------------------------//
    // std::vector<int> vec{1};
    // sh::showContainer(vec);
    // std::cout << solution.removeDuplicates_26(vec) << std::endl;
    // sh::showContainer(vec);
    int removeDuplicates_26(std::vector<int> &nums)
    {
        int prev(nums[0]);
        auto end = std::remove_if(nums.begin() + 1, nums.end(), [&prev](int a)
                                  {
            if(a == prev)
                return true;
            prev = a;
            return false; });
        nums.erase(end, nums.end());
        return nums.size();
    }

    //--------------------------#28---------------------------------------------//
    int strStr_28(std::string haystack, std::string needle)
    {
        int i = haystack.find(needle);
        return (i == std::string::npos ? -1 : i);
    }

    //--------------------------#35---------------------------------------------//
    // std::vector<int> vec{1,3,4,5,6};
    // sh::showContainer(vec);
    // std::cout << solution.searchInsert_35(vec, -1);
    int searchInsert_35(std::vector<int> &nums, int target)
    {
        int l(0), r(nums.size() - 1), mid;
        while (l <= r)
        {
            mid = (r + l) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
            {
                if (mid == 0 or nums[mid - 1] < target)
                    return mid;
                r = mid - 1;
                continue;
            }
            if (nums[mid] < target)
            {
                if (mid == nums.size() - 1 or nums[mid + 1] > target)
                    return mid + 1;
                l = mid + 1;
            }
        }
        return -1;
    }

    //--------------------------#48---------------------------------------------//
    // std::vector<std::vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    // sh::showVecVec(matrix);
    // solution.rotate_48(matrix);
    // sh::showVecVec(matrix);
    void rotate_48(std::vector<std::vector<int>> &matrix)
    {
        if (matrix.size() == 1)
            return;

        for (int i(0); i < matrix.size(); i++)
        {
            for (int j(i + 1); j < matrix.size(); j++)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
            std::reverse(std::begin(matrix[i]), std::end(matrix[i]));
        }
    }

    //--------------------------#46---------------------------------------------//
    // std::vector<int> vec{1,2,3};
    // sh::showContainer(vec);
    // sh::showVecVec(solution.permute_46(vec));
    std::vector<std::vector<int>> permute_46(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
    void backtrack(std::vector<int> &nums, int start, std::vector<std::vector<int>> &res)
    {
        if (start == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            swap(nums, start, i);
            backtrack(nums, start + 1, res);
            swap(nums, start, i);
        }
    }

    //--------------------------#53---------------------------------------------//
    // std::vector<int> vec{-2,1,-3,4,-1,2,1,-5,4}; //1-> 3->
    // std::cout << solution.maxSubArray(vec) << std::endl;
    int maxSubArray(std::vector<int> &nums)
    {
        int res = nums[0];
        int total = 0;

        for (int n : nums)
        {
            if (total < 0)
            {
                total = 0;
            }

            total += n;
            res = std::max(res, total);
        }

        return res;
    }

    //--------------------------#54---------------------------------------------//
    // std::vector<std::vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    // sh::showContainer(solution.spiralOrder(matrix));
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> res;
        res.resize(matrix.size() * matrix[0].size());
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                res[getSpiralPlace(i, j, matrix[i].size(), matrix.size())] = matrix[i][j];
            }
        }
        return res;
    }

    //--------------------------#55---------------------------------------------//
    // std::vector<int> vec{3,2,1,0,4};
    // std::cout<< std::boolalpha << solution.canJump(vec) << std::endl;
    bool canJump(std::vector<int> &nums)
    {
        // --1
        int minjump(0);
        for (int i(nums.size() - 2); i >= 0; i--)
        {
            if (nums[i] >= ++minjump)
                minjump = 0;
        }
        return minjump == 0;

        // // --2
        // return checkJump(nums, 0);
    }
    bool checkJump(std::vector<int> &nums, int start)
    {
        if (start == nums.size() - 1)
            return true;

        for (int i(start + 1); i <= start + nums[start]; i++)
        {
            if (checkJump(nums, i))
                return true;
        }
        return false;
    }

    //--------------------------#56---------------------------------------------//
    // std::vector<std::vector<int>> matrix{{1,3},{2,6},{8,10}, {15,18}}; // {1,3},{2,6},{8,10}, {15,18} {4,5},{1,4},{0,1}
    // sh::showVecVec(matrix);
    // sh::showVecVec(solution.merge_56(matrix));
    std::vector<std::vector<int>> merge_56(std::vector<std::vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;
        for (auto interval : intervals)
        {
            if (merged.empty() || merged.back()[1] < interval[0])
                merged.push_back(interval);
            else
                merged.back()[1] = std::max(merged.back()[1], interval[1]);
        }
        return merged;
    }
    bool isMerge(int l1, int r1, int l2, int r2)
    {
        if (l1 <= l2 and r1 >= r2)
            return true;
        if (l2 <= l1 and r2 >= r1)
            return true;
        if ((l1 <= l2 and l2 <= r1) or (l1 <= r2 and r2 <= r1))
            return true;
        return false;
    }

    //--------------------------#57---------------------------------------------//
    // std::vector<std::vector<int>> intervals{{1, 5}};
    // std::vector<int> a{2,3};
    // sh::showVecVec(solution.insert_57(intervals , a));
    std::vector<std::vector<int>> insert_57(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval)
    {
        std::vector<std::vector<int>> res;
        if (intervals.size() == 0)
            return {newInterval};

        int l = newInterval[0], r = newInterval[1], f(1);
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][1] < newInterval[0])
            {
                res.push_back(intervals[i]);
                continue;
            }
            if (intervals[i][0] > newInterval[1])
            {
                if (f-- == 1)
                    res.push_back({l, r});
                res.push_back(intervals[i]);
                continue;
            }
            l = std::min(l, intervals[i][0]);
            r = std::max(r, intervals[i][1]);
            if (i == intervals.size() - 1)
            {
                res.push_back({l, r});
                f--;
            }
        }
        if (f == 1)
            res.push_back({l, r});
        return res;
    }

    //--------------------------#58---------------------------------------------//
    // std::string s("   fly me   to   the moon  ");
    // std::cout << solution.lengthOfLastWord_58(s);
    int lengthOfLastWord_58(std::string s)
    {
        std::smatch res;
        std::regex_search(s, res, std::regex{R"((\w*)\s*$)"});
        return res[1].length();
    }

    //--------------------------#59---------------------------------------------//
    // sh::showVecVec(solution.generateMatrix_59(4));
    std::vector<std::vector<int>> generateMatrix_59(int n)
    {
        std::vector<std::vector<int>> res;
        res.reserve(n);
        for (int i(0); i < n; i++)
        {
            std::vector<int> tmp;
            tmp.reserve(n);
            for (int j(0); j < n; j++)
            {
                tmp.push_back(getSpiralPlace(i, j, n, n) + 1);
            }
            res.push_back(tmp);
        }
        return res;
    }

    //--------------------------#61---------------------------------------------//
    // ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    // sh::showList(l1);
    // l1 = solution.rotateRight_61(l1, 2);
    // sh::showList(l1);
    ListNode *rotateRight_61(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;

        int n = getListLength(head);
        k = k % n;
        ListNode *h = head;
        ListNode *new_end;
        while (h->next != nullptr)
        {
            if (k == 0)
            {
                new_end = head;
                k--;
                continue;
            }
            if (k < 0)
            {
                h = h->next;
                new_end = new_end->next;
                continue;
            }
            h = h->next;
            k--;
        }
        h->next = head;
        head = new_end->next;
        new_end->next = nullptr;
        return head;
    }
    int getListLength(ListNode *head)
    {
        int i(0);
        while (head != nullptr)
        {
            head = head->next;
            i++;
        }
        return i;
    }

    //--------------------------#66---------------------------------------------//
    // std::vector<int> vec{4,3,2,1};
    // sh::showContainer(vec);
    // sh::showContainer(solution.plusOne(vec));
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        std::vector<int> res;
        res.reserve(digits.size());
        int j = 1;
        for (int i(digits.size() - 1); i >= 0; i--)
        {
            if (digits[i] + j == 10)
            {
                res.push_back(0);
                if (i == 0)
                    res.push_back(1);
                continue;
            }
            res.push_back(digits[i] + j);
            j = 0;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    //--------------------------#62---------------------------------------------//
    // sh::print(solution.uniquePaths(3,7));
    int uniquePaths(int m, int n)
    {
        // --easy
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];

        // --better
        // vector<int> pre(n, 1), cur(n, 1);
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         cur[j] = pre[j] + cur[j - 1];
        //     }
        //     swap(pre, cur);
        // }
        // return pre[n - 1];

        // --The best
        // std::vector<int> cur(n, 1);
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         cur[j] += cur[j - 1];
        //     }
        // }
        // return cur[n - 1];
    }

    //--------------------------#10---------------------------------------------//
    // std::cout << std::boolalpha << solution.isMatch("aaa","ab*a*c*a") << std::endl;
    bool isMatch(std::string s, std::string p)
    {
        int n = s.length(), m = p.length();
        bool dp[n + 1][m + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }

        return dp[n][m];

        // char r_char(p[0]);
        // int count(0);
        // int i(0), j(0);
        // bool flag(false);
        // for (; i < p.size(); i++){
        //     if(p[i] == r_char){
        //         count++;
        //         if(i == p.size() - 1 and isValid(s, j, r_char, count, flag)){
        //             i++;
        //             break;
        //         }
        //     }
        //     if(p[i] != r_char){
        //         if(!isValid(s, j, r_char, count, flag))
        //             return false;
        //         r_char = p[i];
        //         count = 1;
        //         if(i == p.size() - 1 and !isValid(s, j, r_char, count, flag))
        //             return false;
        //     }
        //     if(p[i + 1] == '*'){
        //         count = -1;
        //         i++;
        //         if (r_char == '.'){
        //             flag = true;
        //             r_char = p[i + 1];
        //             count = 0;
        //             if(i == p.size() - 1)
        //                 return true;
        //             continue;
        //         }
        //         if(!isValid(s, j, r_char, count, flag))
        //             return false;
        //         if(i != p.size() - 1){
        //             r_char = p[i + 1];
        //             count = 0;
        //         }
        //         if(i == p.size() - 1){
        //             i++;
        //             break;
        //         }
        //     }

        // }
        // if(i == p.size() and j == s.size())
        //     return true;
        // return false;
    }
    bool isValid(std::string &s, int &j, char r_char, int count, bool flag)
    {
        int steps;
        if (flag)
        {
            for (int i(s.size() - 1); i >= j; i--)
            {
                if (isValid(s, i, r_char, count, false))
                {
                    j = i;
                    return true;
                }
            }
            return false;
        }
        else
        {
            int steps = (count == -1 ? s.size() : j + count);
            if (j >= s.size() || steps > s.size())
            {
                return false;
            }
            int i(j);
            for (; i < steps; i++)
            {
                if (r_char == '.')
                    continue;
                if (s[i] != r_char and count == -1)
                {
                    j = i;
                    return true;
                }
                if (s[i] != r_char and count != -1)
                {
                    return false;
                }
            }
            j = i;
        }
        return true;
    }

    //--------------------------#67---------------------------------------------//
    // sh::print(solution.addBinary_67("1010","1011"));
    std::string addBinary_67(std::string a, std::string b)
    {
        std::string res;
        int size = std::max(a.size(), b.size());
        res.reserve(size + 1);
        char mark('0');
        for (int i = 0; i < size; i++)
        {
            if (i < a.size() and i < b.size())
            {
                if (a[a.size() - 1 - i] == '0' and b[b.size() - 1 - i] == '0')
                {
                    res += (mark == '1' ? '1' : '0');
                    mark = '0';
                }
                else if (a[a.size() - 1 - i] == '1' and b[b.size() - 1 - i] == '1')
                {
                    res += mark == '1' ? '1' : '0';
                    mark = '1';
                }
                else if (mark == '1')
                {
                    res += '0';
                    mark = '1';
                }
                else
                {
                    res += '1';
                }
            }
            else if (i >= a.size())
            {
                if (b[b.size() - 1 - i] == '1')
                {
                    res += mark == '1' ? '0' : '1';
                }
                if (b[b.size() - 1 - i] == '0')
                {
                    res += mark == '1' ? '1' : '0';
                    mark = '0';
                }
            }
            else if (i >= b.size())
            {
                if (a[a.size() - 1 - i] == '1')
                {
                    res += mark == '1' ? '0' : '1';
                }
                if (a[a.size() - 1 - i] == '0')
                {
                    res += mark == '1' ? '1' : '0';
                    mark = '0';
                }
            }
        }
        if (mark != '0')
            res += '1';
        std::reverse(res.begin(), res.end());
        return res;
    }

    //--------------------------#71---------------------------------------------//
    // std::string str1 = "/.";
    // std::string str2 = "/..home";
    // std::string str3 = "/home/user/Documents/../Pictures";
    // std::string str4 = "/.../a/../b/c/../d/./";
    // sh::print(solution.simplifyPath_71(str2));
    // sh::print(solution.simplifyPath_71(str1));
    std::string simplifyPath_71(std::string path)
    {
        if (path.length() == 1)
            return path;

        std::string opt_path;
        for (int i = 0; i < path.length(); i++)
        {
            if (i == path.length() - 1 and path[i] == '/')
                continue;

            if (path[i] == '/')
            {
                while (path[i + 1] == '/')
                    i++;
                if (opt_path.size() != 1)
                    opt_path.push_back(path[i]);
                continue;
            }

            if (path[i] == '.')
            {
                int count(1);
                std::string tmp(".");
                while (path[i + 1] == '.')
                {
                    i++;
                    count++;
                    tmp.push_back(path[i]);
                }
                if (count >= 3)
                {
                    opt_path.append(tmp);
                    continue;
                }
                if (i == path.size() - 1 or path[i + 1] == '/')
                {
                    if (count == 1)
                    {
                        if (opt_path.length() > 1)
                            opt_path.pop_back();
                        continue;
                    }
                    if (count == 2)
                    {
                        int to_del;
                        int j(opt_path.size() - 1);
                        while (count != 0 and j > 0)
                        {
                            if (opt_path[j--] == '/')
                                count--;
                        }
                        opt_path.erase(opt_path.begin() + j + 1, opt_path.end());
                    }
                }
                else
                {
                    i++;
                    while (i != path.length() and path[i] != '/')
                        tmp.push_back(path[i++]);
                    opt_path.append(tmp);
                    i--;
                }
                continue;
            }

            std::string tmp;
            while (i != path.length() and path[i] != '/')
            {
                tmp.push_back(path[i++]);
            }
            opt_path.append(tmp);
            i--;
        }
        if (opt_path[opt_path.length() - 1] == '/')
            opt_path.erase(opt_path.end() - 1);
        return opt_path;
    }

    //--------------------------#70---------------------------------------------//
    // solution.climbStairs_70(4);
    int climbStairs_70(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int n1 = 2;
        int n2 = 1;
        for (int i = 0; i < n - 2; i++)
        {
            n1 += n2;
            n2 = n1 - n2;
        }

        return n1;
    }

    //--------------------------#20---------------------------------------------//
    bool isValid_20(std::string s)
    {
        std::stack<char> br;
        size_t i(0);
        for (; i < s.size(); i++)
        {
            if (s[i] == '[' or s[i] == '(' or s[i] == '{')
            {
                br.push(s[i]);
                continue;
            }

            if (!br.empty() and ((s[i] == ']' and br.top() == '[') or (s[i] == '}' and br.top() == '{') or (s[i] == ')' and br.top() == '(')))
            {
                br.pop();
            }
            else
            {
                return false;
            }
        }
        if (br.empty() and i == s.size())
            return true;
        else
            return false;
    }

    //--------------------------#50---------------------------------------------//
    // sh::print(solution.myPow(2, -6));
    double myPow(double x, int n)
    {
        double res = 1;
        while (n)
        {
            if (n % 2)
            {
                res = (n > 0 ? res * x : res / x);
            }
            x = x * x;
            n /= 2;
        }
        return res;
    }

    //--------------------------#82---------------------------------------------//
    // ListNode* l1 = new ListNode(1, (new ListNode(1, (new ListNode(3,(new ListNode(3,(new ListNode(5,(new ListNode(6,(new ListNode(7,(new ListNode(8)))))))))))))));
    // sh::showList(l1);
    // l1 = solution.deleteDuplicates_82(l1);
    // sh::showList(l1);
    ListNode *deleteDuplicates_82(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *prev = new ListNode(0, head);
        ListNode *curr = head;
        ListNode *res = prev;

        while (curr != nullptr)
        {
            if (curr->next != nullptr and curr->val == curr->next->val)
            {
                while (curr->next != nullptr and curr->val == curr->next->val)
                {
                    curr = curr->next;
                }
                prev->next = curr->next;
                curr = curr->next;
                continue;
            }
            curr = curr->next;
            prev = prev->next;
        }

        return res->next;
    }

    //--------------------------#83---------------------------------------------//
    // ListNode* l1 = new ListNode(1, (new ListNode(1, (new ListNode(3,(new ListNode(3,(new ListNode(5,(new ListNode(6)))))))))));
    // sh::showList(l1);
    // l1 = solution.deleteDuplicates_83(l1);
    // sh::showList(l1);
    ListNode *deleteDuplicates_83(ListNode *head)
    {
        ListNode *curr = head;

        ListNode *duplicate;
        while (curr != nullptr)
        {
            if (curr->next != nullptr and curr->val == curr->next->val)
            {
                duplicate = curr->next;
                curr->next = duplicate->next;
                delete duplicate;
                continue;
            }
            curr = curr->next;
        }
        return head;
    }

    //--------------------------#81---------------------------------------------//
    // std::vector<int> vec{1,1};
    // sh::showContainer(vec);
    // std::cout << std::boolalpha << solution.search_81(vec,0);
    bool search_81(std::vector<int> &nums, int target)
    {
        int second = binarySearchDeepGap(nums, 0, nums.size() - 1);
        int ans;
        if (second == -1)
        {
            ans = binarySearchRange(nums, target, 0, nums.size() - 1);
        }
        else if (target >= nums[second] and target <= nums[nums.size() - 1])
        {
            ans = binarySearchRange(nums, target, second, nums.size() - 1);
        }
        else
        {
            ans = binarySearchRange(nums, target, 0, second - 1);
        }
        return ans == -1 ? false : true;
    }

    //--------------------------#75---------------------------------------------//
    // std::vector<int> vec{2,0,2,1,1,0};
    // sh::showContainer(vec);
    // solution.sortColors_75(vec);
    // sh::showContainer(vec);
    void sortColors_75(std::vector<int> &nums)
    {
        std::vector<int> ans(nums.size(), 1);

        int l(0), r(nums.size() - 1);
        for (size_t i(0); i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                ans[l++] = 0;
                continue;
            }
            if (nums[i] == 2)
            {
                ans[r--] = 2;
                continue;
            }
        }
        std::copy(ans.begin(), ans.end(), nums.begin());

        // int low = 0, mid = 0, high = nums.size()-1;
        // while(mid <= high){
        //     if(nums[mid] == 0){
        //         std::swap(nums[low], nums[mid]);
        //         low++;
        //         mid++;
        //     }
        //     else if(nums[mid] == 1){
        //         mid++;
        //     }
        //     else{
        //         std::swap(nums[mid], nums[high]);
        //         high--;
        //     }
        // }
    }

    //--------------------------#80---------------------------------------------//
    // std::vector<int> vec{1,1,1,1};
    // sh::showContainer(vec);
    // solution.removeDuplicates_80(vec);
    // sh::showContainer(vec);
    int removeDuplicates_80(std::vector<int> &nums)
    {
        int prev(nums[0]), k(1);
        auto end = std::remove_if(nums.begin() + 1, nums.end(), [&prev, &k](int a)
                                  {
            if(a == prev){
                k++;
                if(k > 2){
                    return true;
                } else {
                    return false;
                }
            }
            prev = a; 
            k = 1;    
            return false; });
        nums.erase(end, nums.end());
        return nums.size();

        // int i = 0;
        // for (int n : nums)
        //     if (i < 2 || n > nums[i-2])
        //         nums[i++] = n;
        // return i;
    }

    //--------------------------#73---------------------------------------------//
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        std::unordered_set<int> r;
        std::unordered_set<int> c;

        for (size_t i(0); i != matrix.size(); ++i)
        {
            for (size_t j(0); j != matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        for (auto it = std::begin(r); it != std::end(r); ++it)
        {
            resetRow(matrix, *it);
        }
        for (auto it = std::begin(c); it != std::end(c); ++it)
        {
            resetColumn(matrix, *it);
        }
    }

    //--------------------------#3042-------------------------------------------//
    int countPrefixSuffixPairs(std::vector<std::string> &words)
    {
        int res(0);
        for (size_t i(0); i < words.size() - 1; ++i)
        {
            for (size_t j(i + 1); j < words.size(); ++j)
            {
                if (words[i].size() <= words[j].size() and isPrefixAndSuffix(words[i], words[j]))
                    res++;
            }
        }
        return res;
    }

    //--------------------------#86---------------------------------------------//
    // ListNode* l1 = new ListNode(1, (new ListNode(4, (new ListNode(3,(new ListNode(2,(new ListNode(5,(new ListNode(2)))))))))));
    // sh::showList(l1);
    // l1 = solution.partition_86(l1,3);
    // sh::showList(l1);
    ListNode *partition_86(ListNode *head, int x)
    {
        ListNode *l_st = new ListNode;
        ListNode *l = l_st;
        ListNode *r_st = new ListNode;
        ListNode *r = r_st;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                l->next = head;
                l = l->next;
            }
            else
            {
                r->next = head;
                r = r->next;
            }
            head = head->next;
        }
        l->next = r_st->next;
        r->next = nullptr;
        return l_st->next;
    }

    //--------------------------#94---------------------------------------------//
    std::vector<int> inorderTraversal_94(TreeNode *root)
    {
        std::vector<int> res;
        inorderTree_94(root, res);
        return res;
    }
    void inorderTree_94(TreeNode *root, std::vector<int> &res)
    {
        if (root == nullptr)
        {
            res.push_back(INT_MIN);
            return;
        }

        inorderTree_94(root->left, res);
        res.push_back(root->val);
        inorderTree_94(root->right, res);
    }

    //--------------------------#100--------------------------------------------//
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        std::vector<int> res_p, res_q;
        inorderTree_94(p, res_p);
        inorderTree_94(q, res_q);
        if (res_p.size() != res_q.size())
            return false;
        for (size_t i(0); i != res_p.size(); ++i)
        {
            if (res_p[i] != res_q[i])
                return false;
        }
        return true;
    }

    //--------------------------#98---------------------------------------------//
    bool isValidBST_98(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        std::pair<int, int> p{root->val, root->val};
        return isValid_98(root, p);
    }
    bool isValid_98(TreeNode *root, std::pair<int, int> &interval)
    {
        if (root == nullptr)
        {
        }
        return true;
        if (root->left == nullptr and root->right == nullptr)
        {
            interval = {root->val, root->val};
            return true;
        }
        bool res;
        int l;
        if (root->left != nullptr)
        {
            res = isValid_98(root->left, interval);
            if (res == false || root->val <= interval.second)
                return false;
            l = interval.first;
        }
        else
        {
            l = root->val;
        }

        if (root->right != nullptr)
        {
            res = isValid_98(root->right, interval);
            if (res == false || root->val >= interval.first)
                return false;
        }
        else
        {
            interval.second = root->val;
        }
        interval.first = l;

        return true;
    }

    //--------------------------#2185-------------------------------------------//
    int prefixCount(std::vector<std::string> &words, std::string pref)
    {
        int k(0);
        for (size_t i(0); i != words.size(); ++i)
        {
            if (words[i].starts_with(pref))
                ++k;
        }
        return k;
    }

    //--------------------------#97---------------------------------------------//
    bool isInterleave(std::string s1, std::string s2, std::string s3)
    {
        if (s3.length() != s1.length() + s2.length())
            return false;

        bool table[s1.length() + 1][s2.length() + 1];

        for (int i = 0; i < s1.length() + 1; i++)
            for (int j = 0; j < s2.length() + 1; j++)
            {
                if (i == 0 && j == 0)
                    table[i][j] = true;
                else if (i == 0)
                    table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                else if (j == 0)
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                else
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }

        return table[s1.length()][s2.length()];
    }

    //--------------------------#96---------------------------------------------//
    // sh::print(solution.numTrees(2));
    // sh::print(solution.numTrees(3));
    // sh::print(solution.numTrees(4));
    // sh::print(solution.numTrees(5));
    // sh::print(solution.numTrees(6));
    int numTrees(int n)
    {
        std::vector<int> res;
        res.resize(n + 1, 0);
        res[0] = 1;

        for (size_t i(1); i != n + 1; ++i)
        {
            combinations_96(i, res);
        }
        return res[n];
    }

    //--------------------------#92---------------------------------------------//
    // ListNode* l1 = new ListNode(3, (new ListNode(5)));
    // sh::showList(l1);
    // l1 = solution.reverseBetween_92(l1, 2, 2);
    // sh::showList(l1);
    ListNode *reverseBetween_92(ListNode *head, int left, int right)
    {
        int count(1);
        ListNode *prev_st = new ListNode;
        ListNode *st;
        ListNode *end;
        ListNode *after_end = nullptr;
        ListNode *curr = head;
        prev_st->next = curr;
        bool f(true);

        while (curr != nullptr && count <= right)
        {
            if (count == left)
            {
                st = curr;
                f = false;
            }

            if (count == right)
            {
                end = curr;
            }

            curr = curr->next;
            ++count;
            if (f)
                prev_st = prev_st->next;
        }
        if (end != nullptr)
            after_end = end->next;

        // развернуть список между st and end
        if (right != left)
        {
            prev_st->next = end;
            ListNode *next_el;
            ListNode *next_node = after_end;
            curr = st;
            count = right - left + 1;
            while (count--)
            {
                next_el = curr->next;
                curr->next = next_node;
                next_node = curr;
                curr = next_el;
            }
        }

        if (left == 1)
            head = prev_st->next;
        return head;
    }

    //--------------------------#1408-------------------------------------------//
    // --KMP
    // std::vector<std::string> words{"leetcode","et","code"};
    // sh::showContainer(words);
    // sh::showContainer(solution.stringMatching_1408(words));
    std::vector<std::string> stringMatching_1408(std::vector<std::string> &words)
    {
        std::vector<std::string> ans;
        bool add(false);
        for (size_t i(0); i != words.size(); ++i)
        {
            std::string curr = words[i];
            for (size_t j(0); j != words.size(); ++j)
            {
                if (curr.size() > words[j].size() || j == i)
                    continue;
                for (size_t k(0); k + curr.size() <= words[j].size(); ++k)
                {
                    if (curr == words[j].substr(k, curr.size()))
                    {
                        add = true;
                        break;
                    }
                }
                if (add)
                    break;
            }
            if (add)
                ans.push_back(curr);
            add = false;
        }
        return ans;
    }

    //--------------------------#88---------------------------------------------//
    // std::vector<int> nums1{2,0};
    // std::vector<int> nums2{1};
    // sh::showContainer(nums1);
    // sh::showContainer(nums2);
    // solution.merge_88(nums1,1,nums2,1);
    // sh::showContainer(nums1);
    void merge_88(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        int i{m + n - 1};
        --m;
        --n;
        while (n >= 0)
        {
            if (n < 0 || (m >= 0 and nums1[m] > nums2[n]))
            {
                std::swap(nums1[m--], nums1[i]);
            }
            else
            {
                std::swap(nums2[n--], nums1[i]);
            }
        }
    }

    //--------------------------#84---------------------------------------------//
    int largestRectangleArea_84(std::vector<int> &heights)
    {
        // int ans(0);
        // for(size_t i(0); i != heights.size(); ++i){
        //     int l(i - 1), r(i + 1);
        //     int s(heights[i]);
        //     while ((l >= 0 and heights[i] <= heights[l]) or (r < heights.size() and heights[i] <= heights[r]))
        //     {
        //         if(r < heights.size() and heights[i] <= heights[r]){
        //             s += heights[i];
        //             ++r;
        //         }
        //         if(l >= 0 and heights[i] <= heights[l]){
        //             s += heights[i];
        //             --l;
        //         }
        //     }
        //     ans = std::max(ans, s);
        // }
        // return ans;
        int n = heights.size();
        std::vector<int> nsr(n, 0);
        std::vector<int> nsl(n, 0);

        std::stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[i] <= heights[s.top()])
            {
                s.pop();
            }
            if (s.empty())
                nsr[i] = n;
            else
                nsr[i] = s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[i] <= heights[s.top()])
            {
                s.pop();
            }
            if (s.empty())
                nsl[i] = -1;
            else
                nsl[i] = s.top();
            s.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = std::max(ans, heights[i] * (nsr[i] - nsl[i] - 1));
        }
        return ans;
    }

    //--------------------------#916--------------------------------------------//
    // std::vector<std::string> words1{"amazon","apple","facebook","google","leetcode"};
    // std::vector<std::string> words2{"e","oo"};
    // sh::showContainer(solution.wordSubsets_916(words1, words2));
    std::vector<std::string> wordSubsets_916(std::vector<std::string> &words1, std::vector<std::string> &words2)
    {
        std::unordered_map<char, int> key;
        std::unordered_map<char, int> tmp;
        std::vector<std::string> ans;
        for (size_t i(0); i != words2.size(); ++i)
        {
            std::string curr_str = words2[i];
            for (size_t j(0); j != curr_str.size(); ++j)
            {
                ++tmp[curr_str[j]];
            }

            for (auto it = std::begin(tmp); it != std::end(tmp); ++it)
            {
                if (key[it->first] < it->second)
                {
                    key[it->first] = it->second;
                }
            }
            tmp.clear();
        }

        for (size_t i(0); i != words1.size(); ++i)
        {
            std::string curr_str = words1[i];
            for (size_t j(0); j != curr_str.size(); ++j)
            {
                ++tmp[curr_str[j]];
            }

            bool add(true);
            for (auto it = std::begin(key); it != std::end(key); ++it)
            {
                if (tmp[it->first] < it->second)
                {
                    add = false;
                    break;
                }
            }
            if (add)
            {
                ans.push_back(curr_str);
            }
            tmp.clear();
        }
        return ans;
    }

    //--------------------------#1769-------------------------------------------//
    // std::string s("001011");
    // sh::showContainer(solution.minOperations_1769(s));
    std::vector<int> minOperations_1769(std::string boxes)
    {
        // std::vector<int> balls;
        // for(size_t i(0); i != boxes.size(); ++i){
        //     if(boxes[i] == '1'){
        //         balls.push_back(i);
        //     }
        // }
        // std::vector<int> ans;
        // ans.reserve(boxes.size());
        // for(size_t i(0); i != boxes.size(); ++i){
        //     int path(0);
        //     for(size_t j(0); j != balls.size(); ++j){
        //         path += std::abs(balls[j] - static_cast<int>(i));
        //     }
        //     ans.push_back(path);
        // }
        // return ans;
        int n = boxes.size();
        std::vector<int> answer(n, 0);

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;
        for (int i = 0; i < n; i++)
        {
            // Left pass
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }
        return answer;
    }

    //--------------------------#13---------------------------------------------//
    // sh::print(solution.romanToInt_13("MCMXCIV"));
    // sh::print(solution.romanToInt_13("LVIII"));
    int romanToInt_13(std::string s)
    {
        int ans(0);
        for (size_t i(0); i != s.size(); ++i)
        {
            switch (s[i])
            {
            case 'I':
                if (i < s.size() and (s[i + 1] == 'V' or s[i + 1] == 'X'))
                {
                    if (s[i + 1] == 'V')
                        ans += 4;
                    else
                        ans += 9;
                    ++i;
                }
                else
                {
                    ++ans;
                }
                break;
            case 'V':
                ans += 5;
                break;
            case 'X':
                if (i < s.size() and (s[i + 1] == 'L' or s[i + 1] == 'C'))
                {
                    if (s[i + 1] == 'L')
                        ans += 40;
                    else
                        ans += 90;
                    ++i;
                }
                else
                {
                    ans += 10;
                }
                break;
            case 'L':
                ans += 50;
                break;
            case 'C':
                if (i < s.size() and (s[i + 1] == 'D' or s[i + 1] == 'M'))
                {
                    if (s[i + 1] == 'D')
                        ans += 400;
                    else
                        ans += 900;
                    ++i;
                }
                else
                {
                    ans += 100;
                }
                break;
            case 'D':
                ans += 500;
                break;
            case 'M':
                ans += 1000;
                break;
            default:
                break;
            }
        }

        return ans;
    }

    //--------------------------#90---------------------------------------------//
    // std::vector<int> nums{1, 2, 2, 3};
    // sh::showVecVec(solution.subsetsWithDup_90(nums));
    std::vector<std::vector<int>> subsetsWithDup_90(std::vector<int> &nums)
    {
        // std::vector<std::vector<int>> ans;
        // std::set<int> check;
        // std::vector<int> tmp;
        // ans.push_back({});
        // for(size_t i(0); i != nums.size(); ++i){
        //     GetAllVariants_90(i, nums, ans, check, tmp);
        //     check.insert(nums[i]);
        // }
        // return ans;
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        sort(nums.begin(), nums.end());
        helper_90(nums, ans, curr, 0);
        return ans;
    }

    //--------------------------#79---------------------------------------------//
    // std::vector<std::vector<char>> board = {
    //     {'A','B','C','L'},
    //     {'L','F','C','S'},
    //     {'A','D','E','L'},
    // };
    // std::string word("SE");
    // sh::showVecVec(board);
    // std::cout << std::boolalpha << solution.exist_79(board, word) << std::endl;
    bool exist_79(std::vector<std::vector<char>> &board, std::string word)
    {
        int n = board.size();    // Number of rows in the board
        int m = board[0].size(); // Number of columns in the board

        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false)); // Array to keep track of visited cells

        // Convert the word into a character array
        std::vector<char> wordChar(word.begin(), word.end());

        // Quick check: If the length of the word exceeds the total number of cells on the board, it can't exist
        if (wordChar.size() > n * m)
            return false;

        std::vector<int> counts(256, 0); // Array to store counts of each character

        // Count the occurrence of each character on the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                counts[board[i][j]]++;
            }
        }

        // Adjust the order of characters in the wordChar array based on their frequency counts to optimize search
        int len = wordChar.size();
        for (int i = 0; i < len / 2; i++)
        {
            if (counts[wordChar[i]] > counts[wordChar[len - 1 - i]])
            {
                for (int j = 0; j < len / 2; j++)
                {
                    char temp = wordChar[j];
                    wordChar[j] = wordChar[len - 1 - j];
                    wordChar[len - 1 - j] = temp;
                }
                break;
            }
        }

        // Decrease counts of characters in the word from the board
        for (char c : wordChar)
        {
            if (--counts[c] < 0)
                return false; // If there are more occurrences of a character in the word than on the board, return false
        }

        // Iterate through each cell in the board and start searching for the word
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visit_79(board, wordChar, 0, i, j, n, m, visited))
                    return true; // If the word is found starting from this cell, return true
            }
        }
        return false;
    }

    //--------------------------#78---------------------------------------------//
    // std::vector<int> nums{1, 2, 3};
    // sh::showVecVec(solution.subsets_78(nums));
    std::vector<std::vector<int>> subsets_78(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        curr.reserve(nums.size());
        helper_78(ans, nums, curr, 0);
        return ans;
    }
    void helper_78(std::vector<std::vector<int>> &ans, std::vector<int> &nums, std::vector<int> curr, int ind)
    {
        ans.push_back(curr);
        for (size_t i(ind); i != nums.size(); ++i)
        {
            curr.push_back(nums[i]);
            helper_78(ans, nums, curr, i + 1);
            curr.pop_back();
        }
    }

    //--------------------------#77---------------------------------------------//
    // sh::showVecVec(solution.combine_77(4,3));
    std::vector<std::vector<int>> combine_77(int n, int k)
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;

        helper_combine_77(ans, curr, n, k, 1);
        return ans;
    }

    //--------------------------#39---------------------------------------------//
    // std::vector<int> candidates{2,3,5};
    // sh::showVecVec(solution.combinationSum_39(candidates, 8));
    std::vector<std::vector<int>> combinationSum_39(std::vector<int> &candidates, int target)
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        help__39(candidates, curr, target, ans, 0);
        return ans;
    }
    void help__39(std::vector<int> &candidates, std::vector<int> &curr, int target, std::vector<std::vector<int>> &ans, int ind)
    {
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }
        if (ind == candidates.size())
            return;

        for (size_t i(ind); i != candidates.size(); ++i)
        {
            if (target - candidates[i] < 0)
                continue;
            curr.push_back(candidates[i]);
            help__39(candidates, curr, target - candidates[i], ans, i);
            curr.pop_back();
        }
    }

    //--------------------------#40---------------------------------------------//
    // std::vector<int> candidates{1,1,1,2,5,6,7};
    // sh::showVecVec(solution.combinationSum2_40(candidates, 8));
    std::vector<std::vector<int>> combinationSum2_40(std::vector<int> &candidates, int target)
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        std::sort(std::begin(candidates), std::end(candidates));
        help__40(candidates, curr, target, ans, 0);
        return ans;
    }
    void help__40(std::vector<int> &candidates, std::vector<int> &curr, int target, std::vector<std::vector<int>> &ans, int ind)
    {
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }
        if (ind == candidates.size())
            return;

        for (size_t i(ind); i != candidates.size(); ++i)
        {
            if (target - candidates[i] < 0)
                continue;
            if (i > ind and candidates[i] == candidates[i - 1])
                continue;

            curr.push_back(candidates[i]);
            help__40(candidates, curr, target - candidates[i], ans, i + 1);
            curr.pop_back();
        }
    }

    //--------------------------#216---------------------------------------------//
    // sh::showVecVec(solution.combinationSum3_216(3, 9));
    std::vector<std::vector<int>> combinationSum3_216(int k, int n)
    {
        std::vector<int> nums(9);
        for (size_t i(0); i != 9; ++i)
        {
            nums[i] = i + 1;
        }
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        help__216(nums, curr, k, n, ans, 0);
        return ans;
    }
    void help__216(std::vector<int> &candidates, std::vector<int> &curr, int k, int target, std::vector<std::vector<int>> &ans, int ind)
    {
        if (target == 0 and curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }
        if (ind == candidates.size() or curr.size() >= k)
            return;

        for (size_t i(ind); i != candidates.size(); ++i)
        {
            if (target - candidates[i] < 0)
                continue;
            curr.push_back(candidates[i]);
            help__216(candidates, curr, k, target - candidates[i], ans, i + 1);
            if (!curr.empty())
                curr.pop_back();
        }
    }

    //--------------------------#16---------------------------------------------//
    // std::vector<int> nums{-1,2,1,-4};
    // sh::print(solution.threeSumClosest(nums, 1));
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closest_sum = INT_MAX / 2; // A large value but not overflow

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int current_sum = nums[i] + nums[left] + nums[right];
                if (abs(current_sum - target) < abs(closest_sum - target))
                {
                    closest_sum = current_sum;
                }
                if (current_sum < target)
                {
                    ++left;
                }
                else if (current_sum > target)
                {
                    --right;
                }
                else
                {
                    return current_sum;
                }
            }
        }

        return closest_sum;
    }

    //--------------------------#437--------------------------------------------//
    //         10
    //        /  \
    //       5   -3
    //     /  \    \
    //    3    2    11
    //   / \    \
    //  3  -2    1
    // TreeNode* root = new TreeNode(10,
    //     new TreeNode(5,
    //         new TreeNode(3,
    //             new TreeNode(3),
    //             new TreeNode(-2)),
    //         new TreeNode(2,
    //             nullptr,
    //             new TreeNode(1))
    //     ),
    //     new TreeNode(-3,
    //         nullptr,
    //         new TreeNode(11))
    // );
    // sh::print(solution.pathSum_437(root, 8));
    int pathSum_437(TreeNode *root, int targetSum)
    {
        std::vector<long> partial_sum;
        return help_437(root, targetSum, partial_sum);
    }
    int help_437(TreeNode *root, int targetSum, std::vector<long> &partial_sum)
    {
        if (root == nullptr)
            return 0;

        int count(0);
        partial_sum.push_back(root->val);
        for (size_t i(0); i != partial_sum.size(); ++i)
        {
            if (i != partial_sum.size() - 1)
                partial_sum[i] += root->val;

            if (targetSum - partial_sum[i] == 0)
                ++count;
        }

        int l = help_437(root->left, targetSum, partial_sum);
        int r = help_437(root->right, targetSum, partial_sum);
        partial_sum.pop_back();
        for (size_t i(0); i != partial_sum.size(); ++i)
        {
            partial_sum[i] -= root->val;
        }
        return count + l + r;
    }

    //--------------------------#18---------------------------------------------//
    // std::vector<int> nums{2,2,2,2,2};
    // sh::showVecVec(solution.fourSum_18(nums, 8));
    std::vector<std::vector<int>> fourSum_18(std::vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return {};

        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        curr.reserve(4);
        std::sort(nums.begin(), nums.end());
        GenerateRes_18(nums, target, res, curr, 0);
        return res;
    }
    void GenerateRes_18(std::vector<int> &nums, int target, std::vector<std::vector<int>> &res, std::vector<int> &curr, int ind)
    {
        if (curr.size() == 2)
        {
            int l(ind), r(nums.size() - 1);
            while (l < r)
            {
                int t = nums[l] + nums[r];
                if (t == target)
                {
                    curr.push_back(nums[l++]);
                    curr.push_back(nums[r--]);
                    res.push_back(curr);
                    curr.pop_back();
                    curr.pop_back();
                    while (l < r and nums[l] == nums[l - 1])
                        ++l;
                    while (l < r and nums[r] == nums[r + 1])
                        --r;
                }
                else if (t > target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        else
        {
            for (size_t i(ind); i < nums.size(); ++i)
            {
                if (i > 0 and i > ind and nums[i] == nums[i - 1])
                    continue;
                curr.push_back(nums[i]);
                GenerateRes_18(nums, target - nums[i], res, curr, i + 1);
                curr.pop_back();
            }
        }
    }

    //--------------------------#12---------------------------------------------//
    std::string intToRoman_12(int num)
    {
        std::string res;
        std::vector<std::pair<int, std::string>> nums{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        for (int i(0); i < nums.size(); i++)
        {
            while (num >= nums[i].first)
            {
                res += nums[i].second;
                num -= nums[i].first;
            }
        }
        return res;
    }

    //--------------------------#22---------------------------------------------//
    // sh::showContainer(solution.generateParenthesis_22(2));
    std::vector<std::string> generateParenthesis_22(int n)
    {
        char brackets[2]{'(', ')'};
        std::vector<std::string> res;
        std::string curr;
        GenerateParenthesisHelp(n * 2, res, curr, 0, brackets);
        return res;
    }
    void GenerateParenthesisHelp(int n, std::vector<std::string> &res, std::string &curr, int opened, char brackets[])
    {
        if (n == 0 and opened == 0)
        {
            res.push_back(curr);
        }

        for (size_t i(0); i < 2; ++i)
        {
            if (i == 0 and opened < n)
            {
                curr.push_back(brackets[i]);
                GenerateParenthesisHelp(n - 1, res, curr, opened + 1, brackets);
                curr.pop_back();
            }
            if (i == 1 and opened != 0)
            {
                curr.push_back(brackets[i]);
                GenerateParenthesisHelp(n - 1, res, curr, opened - 1, brackets);
                curr.pop_back();
            }
        }
    }

    //--------------------------#25---------------------------------------------//
    // ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6))))));
    // sh::showList(l1);
    // l1 = solution.reverseKGroup_25(l1, 3);
    // sh::showList(l1);
    ListNode *reverseKGroup_25(ListNode *head, int k)
    {
        int n(1);
        ListNode dummy;
        ListNode *dum_ptr = &dummy;

        ListNode *startKGroup = head;
        ListNode *curr = head;
        ListNode *prev_end = dum_ptr;
        while (curr)
        {
            if (n == k)
            {
                ListNode *next = curr->next;
                curr->next = nullptr;

                ListNode *endKGroup = startKGroup;
                startKGroup = ReverseListNode_25(startKGroup);

                prev_end->next = startKGroup;
                prev_end = endKGroup;

                endKGroup->next = next;
                curr = next;
                startKGroup = next;

                n = 1;
            }
            else
            {
                curr = curr->next;
                n++;
            }
        }
        return dum_ptr->next;
    }
    ListNode *ReverseListNode_25(ListNode *node)
    {
        if (!node and !node->next)
            return node;

        ListNode *curr = node;
        ListNode *next = curr->next;
        ListNode *prev = nullptr;
        while (curr)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr)
                next = curr->next;
        }
        return prev;
    }

    //--------------------------#32---------------------------------------------//
    // sh::print(solution.longestValidParentheses_32(")()"));
    int longestValidParentheses_32(std::string s)
    {
        std::stack<int> st;
        st.push(-1);
        int res(0);
        for (size_t i(0); i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (!st.empty())
                {
                    res = std::max(res, (int)i - st.top());
                }
                else
                {
                    st.push(i);
                }
            }
        }
        return res;
    }

    //--------------------------#99---------------------------------------------//
    void recoverTree_99(TreeNode *root)
    {
        std::vector<TreeNode *> nodes;
        InOrderDFS(root, nodes);
        int l(0), r(nodes.size() - 1);
        while (nodes[l]->val < nodes[l + 1]->val)
            l++;
        while (nodes[r]->val > nodes[r - 1]->val)
            r--;
        std::swap(nodes[l]->val, nodes[r]->val);
    }
    void InOrderDFS(TreeNode *root, std::vector<TreeNode *> &nodes)
    {
        if (!root)
            return;

        InOrderDFS(root->left, nodes);
        nodes.push_back(root);
        InOrderDFS(root->right, nodes);
    }

    //================================================================================================================================================
private:
    bool isPalindrom_5(const std::string &str, int start, int end)
    {
        int l = start, r = end;
        while (l <= r)
        {
            if (str[l] != str[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    std::string expand_5(int i, int j, std::string s)
    {
        int left = i;
        int right = j;

        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }
    void solve_17(std::vector<std::string> &ans, std::vector<std::string> &vec_str, std::string temp, int j)
    {
        if (j >= vec_str.size())
        {
            ans.push_back(temp);
            // j--;
            return;
        }
        for (int i(0); i < vec_str[j].size(); i++)
        {
            temp.push_back(vec_str[j][i]);
            solve_17(ans, vec_str, temp, j + 1);
            temp.pop_back();
        }
    }
    void swap(std::vector<int> &nums, int i, int j)
    {
        if (i == j)
            return;
        nums[i] += nums[j];
        nums[j] = nums[i] - nums[j];
        nums[i] -= nums[j];
    }

    // --34 --81
    int binarySearch(std::vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = (r + l) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > target)
            {
                r = mid - 1;
            }
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
        }
        return -1;
    }
    int binarySearch_r(std::vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid, i = -1;
        while (l <= r)
        {
            mid = (r + l) / 2;
            if (nums[mid] == target)
            {
                if (nums[mid + 1] == target)
                {
                    l = mid + 1;
                    i = mid;
                    continue;
                }
                return mid;
            }
            if (nums[mid] > target)
            {
                r = mid - 1;
            }
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
        }
        return i;
    }
    int binarySearch_l(std::vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid, i;
        while (l <= r)
        {
            mid = (r + l) / 2;
            if (nums[mid] == target)
            {
                if (nums[mid - 1] == target)
                {
                    r = mid - 1;
                    i = mid;
                    continue;
                }
                return mid;
            }
            if (nums[mid] > target)
            {
                r = mid - 1;
            }
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
        }
        return -1;
    }

    // --33 --81
    // return start index of second array
    int binarySearchGap(std::vector<int> &nums)
    {
        if (nums.size() == (0 || 1))
            return -1;

        int l = 0, r = nums.size() - 1, mid;
        while (l < r)
        {
            mid = std::ceil((r + l) / 2.);
            if (nums[mid] < nums[mid - 1])
            {
                return mid;
            }
            if (nums[mid] > nums[l])
            {
                l = mid;
            }
            if (nums[mid] < nums[r])
            {
                r = mid;
            }
        }
        return -1;
    }
    int binarySearchRange(std::vector<int> &nums, int target, int left, int rigth)
    {
        int l = left, r = rigth, mid;
        while (l <= r)
        {
            mid = (r + l) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > target)
            {
                r = mid - 1;
            }
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
        }
        return -1;
    }
    int binarySearchDeepGap(std::vector<int> &nums, int left, int rigth)
    {
        if (nums.size() == (0 || 1))
            return -1;

        int l = left, r = rigth, mid, res;
        if (l != 0 and nums[l] < nums[l - 1])
            return l;
        if (r != nums.size() - 1 and nums[r] > nums[r + 1])
            return r + 1;
        while (l < r)
        {
            mid = std::ceil((r + l) / 2.);

            if (l != 0 and nums[l] < nums[l - 1])
                return l;
            if (r != nums.size() - 1 and nums[r] > nums[r + 1])
                return r + 1;

            if (nums[mid] < nums[mid - 1])
            {
                return mid;
            }
            else if (nums[mid] > nums[l])
            {
                l = mid;
            }
            else if (nums[mid] < nums[r])
            {
                r = mid;
            }
            else
            {
                res = binarySearchDeepGap(nums, l, mid - 1);
                if (res != -1)
                    return res;

                return mid + 1 < r ? binarySearchDeepGap(nums, mid + 1, r) : binarySearchDeepGap(nums, mid, r);
            }
        }
        return -1;
    }

    // --36
    bool rowValid(std::vector<std::vector<char>> &board)
    {
        std::unordered_set<char> check;
        for (const auto &row : board)
        {
            for (const auto &t : row)
            {
                if (t == '.')
                    continue;

                if (check.contains(t))
                    return false;

                check.insert(t);
            }
            check.clear();
        }
        return true;
    }
    bool collValid(std::vector<std::vector<char>> &board)
    {
        std::unordered_set<char> check;
        for (int i(0); i < board.size(); i++)
        {
            for (int j(0); j < board[i].size(); j++)
            {
                if (board[j][i] == '.')
                    continue;

                if (check.contains(board[j][i]))
                    return false;

                check.insert(board[j][i]);
            }
            check.clear();
        }
        return true;
    }
    bool squareValid(std::vector<std::vector<char>> &board)
    {
        std::unordered_set<char> check;
        int size = 3;
        for (int i_gl(0); i_gl < board.size() / size; i_gl++)
        {
            for (int j_gl(0); j_gl < board.size() / size; j_gl++)
            {
                for (int i(i_gl); i < size; i++)
                {
                    for (int j(j_gl); j < size; j++)
                    {
                        if (board[i][j] == '.')
                            continue;

                        if (check.contains(board[i][j]))
                            return false;

                        check.insert(board[i][j]);
                    }
                }
                check.clear();
            }
        }
        return true;
    }

    int countWater_42(std::vector<int> &h, int l, int r)
    {
        int peak = std::min(h[l], h[r]);
        int sum{};
        for (int i(l + 1); i < r; i++)
            sum += (peak <= h[i] ? 0 : peak - h[i]);
        return sum;
    }

    // --49
    bool isAnagramm(std::string &root, std::string &word)
    {
        if (root.size() != word.size())
            return false;

        std::unordered_map<char, int> check;
        for (int i = 0; i < root.size(); i++)
        {
            if (check.contains(root[i]))
            {
                check[root[i]]++;
            }
            else
            {
                check[root[i]] = 1;
            }

            if (check.contains(word[i]))
            {
                check[word[i]]--;
            }
            else
            {
                check[word[i]] = -1;
            }
        }
        for (const auto &t : check)
        {
            if (t.second != 0)
                return false;
        }
        return true;
    }
    bool isAnagramm(std::unordered_map<char, int> check, std::string &word)
    {
        if (check.size() != word.size())
            return false;

        for (int i = 0; i < check.size(); i++)
        {
            if (check.contains(word[i]))
            {
                check[word[i]]--;
            }
            else
            {
                return false;
            }
        }
        for (const auto &t : check)
        {
            if (t.second != 0)
                return false;
        }
        return true;
    }
    void addInCheck(std::vector<std::unordered_map<char, int>> &check, std::string &root)
    {
        std::unordered_map<char, int> ch;
        for (int i = 0; i < root.size(); i++)
        {
            if (ch.contains(root[i]))
            {
                ch[root[i]]++;
            }
            else
            {
                ch[root[i]] = 1;
            }
        }
        check.push_back(ch);
    }

    // --54 --59
    int getSpiralPlace(const int &i, const int &j, int n, int m)
    {
        if (i == 0)
            return j;
        if (j == n - 1)
            return j + i;
        if (i == m - 1)
            return i + 2 * (n - 1) - j;
        if (j == 0)
            return 2 * (n - 1) + 2 * (m - 1) - i;
        return 2 * (n - 1) + 2 * (m - 1) + getSpiralPlace(i - 1, j - 1, n - 2, m - 2);
    }

    // --73
    void resetRow(std::vector<std::vector<int>> &matrix, int row)
    {
        for (size_t i(0); i != matrix[row].size(); ++i)
        {
            matrix[row][i] = 0;
        }
    }
    void resetColumn(std::vector<std::vector<int>> &matrix, int col)
    {
        for (size_t i(0); i != matrix.size(); ++i)
        {
            matrix[i][col] = 0;
        }
    }

    // --3042
    bool isPrefixAndSuffix(const std::string &str1, const std::string &str2)
    {
        return (str2.starts_with(str1) && str2.ends_with(str1));
    }

    // --96
    void combinations_96(int k, std::vector<int> &res)
    {
        if (k == 1)
        {
            res[k] = 1;
            return;
        }

        for (size_t i(1); i <= k; ++i)
        {
            res[k] += res[k - i] * res[i - 1];
        }
    }

    // --90 (for 2 diffrent solutions)
    void GetAllVariants_90(int k, std::vector<int> &nums, std::vector<std::vector<int>> &ans, std::set<int> check, std::vector<int> tmp)
    {
        if (check.contains(nums[k]))
            return;
        tmp.push_back(nums[k]);
        ans.push_back(tmp);
        for (size_t i(1); i + k != nums.size(); ++i)
        {
            GetAllVariants_90(k + i, nums, ans, check, tmp);
            check.insert(nums[k + i]);
        }
    }
    void helper_90(std::vector<int> &nums, std::vector<std::vector<int>> &ans, std::vector<int> &curr, int idx)
    {
        ans.push_back(curr); // we include current susbet into final ans
        for (int i = idx; i < nums.size(); i++)
        { // check for all possibilites
            if (i > idx && nums[i] == nums[i - 1])
                continue;            // if duplicate then we continue
            curr.push_back(nums[i]); // we include nums[i] in current subset
            helper_90(nums, ans, curr, i + 1);
            curr.pop_back(); // to get subset without nums[i]
        }
    }

    // --79
    bool visit_79(std::vector<std::vector<char>> &board, std::vector<char> &word, int start, int x, int y,
                  int n, int m, std::vector<std::vector<bool>> &visited)
    {
        // Base case: If all characters in the word are found, return true
        if (start == word.size())
            return true;

        // Check for out-of-bounds, already visited cells, and character mismatch
        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y])
            return false;

        // If the current character in the word does not match the character on the board, return false
        if (word[start] != board[x][y])
            return false;

        visited[x][y] = true; // Mark the current cell as visited

        bool found = visit_79(board, word, start + 1, x + 1, y, n, m, visited) || visit_79(board, word, start + 1, x - 1, y, n, m, visited) || visit_79(board, word, start + 1, x, y + 1, n, m, visited) || visit_79(board, word, start + 1, x, y - 1, n, m, visited);

        visited[x][y] = false;
        return found;
    }

    // --77
    void helper_combine_77(std::vector<std::vector<int>> &ans, std::vector<int> &curr, int &n, int &k, int ind)
    {
        if (!curr.empty() and curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }

        for (size_t i(ind); i != n + 1; ++i)
        {
            curr.push_back(i);
            helper_combine_77(ans, curr, n, k, i + 1);
            curr.pop_back();
        }
    }
};

//==========================================================================//

int main()
{
    Solution solution;
    Timer timer("LeetCode_100.cpp");

    TreeNode *root = new TreeNode(1,
                                  new TreeNode(3,
                                               nullptr,
                                               new TreeNode(2)),
                                  nullptr);
    solution.recoverTree_99(root);
}