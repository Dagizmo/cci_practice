#include "listnode.h"

ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
    
    if (l == nullptr)
    {
        return nullptr;
    }
    
    ListNode<int> *root = l;
    
    while (root != nullptr)
    {
        if (root->value == k)
        {
            root = root->next;
        }
        else
        {
            break;
        }
    }
    

    if (root != nullptr)
    {
        ListNode<int> *runner = root;

        while(runner->next != nullptr)
        {
            if (runner->next->value == k)
            {
                runner->next = runner->next->next;
            }
            else
            {
                runner = runner->next;
            }
        }
    }
    
    
    return root;
}
