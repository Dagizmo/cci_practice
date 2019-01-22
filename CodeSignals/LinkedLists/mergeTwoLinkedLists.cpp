#include "listnode.h"

ListNode<int> *addResult(ListNode<int> *result, int data)
{
    if (result == nullptr)
    {
        result = new ListNode<int>(data);
    }
    else
    {
        ListNode<int>* runner = result;
        while(runner->next != nullptr)
        {
            runner = runner->next;
        }
        runner->next = new ListNode<int>(data);
    }
    
    return result;
}

ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
    ListNode<int>* result = nullptr;
    while(l1 != nullptr || l2 != nullptr)
    {
        if (l1 == nullptr)
        {
            result = addResult(result, l2->value);
            l2 = l2->next;
        }
        else if (l2 == nullptr)
        {
            result = addResult(result, l1->value);
            l1 = l1->next;
        }
        else if (l1->value <= l2->value)
        {
            result = addResult(result, l1->value);
            l1 = l1->next;
        }
        else
        {
            result = addResult(result, l2->value);
            l2 = l2->next;
        }
            
    }
    
    return result;
}
