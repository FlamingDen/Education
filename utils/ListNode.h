#pragma once

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode();
    ListNode(int x); 
    ListNode(int x, ListNode *next); 
};

namespace sh{
    void showList(ListNode* l);
}