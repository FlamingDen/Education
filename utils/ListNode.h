#pragma once

struct ListNode {
    int val;
    ListNode* next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode* next);
};

namespace sh {
    void showList(ListNode* l);
}

namespace util {
    void deleteList(ListNode* l);

    ListNode* reverseListRecursive(ListNode* l);

    ListNode* reverseListIterable(ListNode* l);
}
