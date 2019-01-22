#include "listnode.h"

bool isListPalindrome(ListNode<int> * l) {
    ListNode<int> *invert = nullptr;
    ListNode<int> *runner = l;
    
    
    while(runner != nullptr)
    {
        ListNode<int> *element = new ListNode<int>(runner->value);
        if (invert == nullptr)
        {
            invert = element;
            invert->next = nullptr;
        }
        else
        {
            element->next = invert;
            invert = element;
        }
        runner = runner->next;
    }
    ListNode<int> *invRunner = invert;
    
    invRunner = invert;
    runner = l;
    while (runner != nullptr)
    {
        if (runner->value != invRunner->value)
        {
            return false;
        }
        runner = runner->next;
        invRunner = invRunner->next;
    }
    
    return true;
}
