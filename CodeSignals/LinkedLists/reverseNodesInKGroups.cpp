#include "listnode.h"

ListNode<int> *append(ListNode<int> *root, const int value)
{
    //root = new ListNode<int>(value);
    // cout << value << " ";
    if (root == nullptr)
    {
        root = new ListNode<int>(value);
        return root;
    }
    
    ListNode<int> *runner = root;
    while(runner->next != nullptr)
    {
        runner = runner->next;
    }
    
    runner->next = new ListNode<int>(value);
    
    
    return root;
}

ListNode<int> *reverse(ListNode<int> *start, int depth)
{
    if (start == nullptr)
    {
        return nullptr;
    }
    
    if (start->next == nullptr || depth == 0)
    {
        return start;
    }
    
    ListNode<int> *tail = reverse(start->next, --depth);
    
    start->next->next = start;
    
    start->next = nullptr;
    
    return tail;
}

ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
    if ( l == nullptr)
    {
        return nullptr;
    }
    
    if (k <= 1)
    {
        return l;
    }
    
   // ListNode<int> *result = nullptr;
   // result = reverse(l,k- 1);

    
    ListNode<int> *startGroup = nullptr;
    ListNode<int> *endGroup = nullptr;
    ListNode<int> *result = nullptr;
    ListNode<int> *runner = l;
    int kCount = 0;
    
    while(runner != nullptr)
    {
        if (startGroup == nullptr)
        {
            startGroup = runner;    
        }
        kCount++;
        //cout << runner->value <<  " " ;
        if (kCount == k)
        {
            endGroup = runner->next;
            ListNode<int> *tempresult = reverse(startGroup, k - 1);
            for (int i = 0; i < k; ++i)
            {
                result = append(result, tempresult->value);
                tempresult = tempresult->next;
            }
            startGroup = nullptr;
            runner = endGroup;
            kCount = 0;
        }
        else
        {
            runner = runner->next;
        }
        
    }
    

    while(endGroup != nullptr)
    {
        result = append(result, endGroup->value);
        endGroup = endGroup->next;
    }
    
    
    return result;
}
