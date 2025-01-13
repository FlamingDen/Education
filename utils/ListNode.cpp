#include "ListNode.h"

//==============================================================================
ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int x) : val(x), next(nullptr) {}
ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {}

static int getListLength(ListNode* head){
    int i(0);
    while (head != nullptr)
    {
        head = head->next;
        i++;
    }
    return i;
}

void sh::showList(ListNode* l){
    while (l != nullptr){
        std::cout << l-> val << " -> ";
        l = l->next; 
    }
    std::cout << "nullptr" <<  std::endl;
}
