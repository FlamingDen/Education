#include "ListNode.h"

#include <iostream>

//==============================================================================
ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int x) : val(x), next(nullptr) {}
ListNode::ListNode(int x, ListNode* next) : val(x), next(next) {}

static int getListLength(ListNode* head)
{
    int i(0);
    while (head != nullptr)
    {
        head = head->next;
        i++;
    }
    return i;
}

void sh::showList(ListNode* l)
{
    while (l != nullptr) {
        std::cout << l->val << " -> ";
        l = l->next;
    }
    std::cout << "nullptr" << std::endl;
}

void util::deleteList(ListNode* l)
{
    ListNode* tmp;
    while (l) {
        tmp = l->next;
        delete l;
        l = tmp;
    }
}

ListNode* util::reverseListRecursive(ListNode* l)
{
    if (!l)
        return nullptr;
    if (!l->next)
        return l;
    ListNode* reverse_list = reverseListRecursive(l->next);
    l->next->next = l;
    l->next = nullptr;
    return reverse_list;

}

ListNode* util::reverseListIterable(ListNode* l)
{
    if (!l)
        return nullptr;
    if (!l->next)
        return l;
    ListNode* prev = nullptr;
    ListNode* curr = l;
    
    while (curr) {
        ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}
