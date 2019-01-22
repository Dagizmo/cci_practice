#include "listnode.h"

ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
    
    if (l == nullptr)
    {
        return nullptr;
    }
    if (n == 0)
    {
        return l;
    }
    
    ListNode<int> * start = l;
    ListNode<int> * endRunner = l;
    ListNode<int> * startRunner = l;
    
    for (int i = 0; i < n - 1; ++i)
    {
        endRunner=endRunner->next;
    }
    
    while(endRunner->next != nullptr)
    {
        startRunner = startRunner->next;
        endRunner = endRunner->next;
    }
    
    endRunner->next = start;
    
    ListNode<int> *otherRunner = start;
    
    while(otherRunner->next != startRunner)
    {
        otherRunner = otherRunner->next;
    }
    
    otherRunner->next = nullptr;
    
    return startRunner;
}
