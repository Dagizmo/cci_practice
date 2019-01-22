#include "listnode.h"
#include <iostream>

using namespace std;

ListNode<int> *padding(ListNode<int> *node, int pad)
{
        ListNode<int> *root = node;
        for (int i = 0; i < pad; ++i)
        {
                ListNode<int> *holder = new ListNode<int>(0);
                holder->next = root;
                root = holder;
        }
        
        return root;
}

int sum(ListNode<int> *a, ListNode<int> *b, ListNode<int> *c)
{
        int carry = 0;
        if (a != nullptr)
        {
                cout << b->value << endl;
                c->next = new ListNode<int>(0);
                carry = sum(a->next, b->next, c->next);
        }
        else if ( a == nullptr)
        {
                return 3;
        }
        
        if (carry == 3)
        {
                c->next = nullptr;
                carry = 0;
        }
        
        c->value = a->value + b->value + carry; 
        
        cout << c->value;
        if (c->value > 9999)
        {
                c->value -= 10000;
                return 1;
        }
        return 0;
}

ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
        
        int aSize = 0;
        int bSize = 0;
        
        if (a == nullptr && b == nullptr)
        {
                return nullptr;
        }
        
        
        ListNode<int> *runner = a;
        while (runner != nullptr)
        {
                aSize++;
                //cout << runner->value << " "; 
                runner = runner->next;
        }
        cout << endl;
        runner = b;
        while (runner != nullptr)
        {
                bSize++;
                runner = runner->next;
        }
        
        
        cout << aSize << endl;
        cout << bSize << endl ;
        cout << "============= " << endl;
        //cout << "a : " << aSize << '   b :'  << bSize << endl;
        
        
        if (aSize < bSize)
        {
                a = padding(a,bSize - aSize);
        }
        else if (bSize < aSize)
        {
                b = padding(b, aSize - bSize);
        }
        
        
        ListNode<int> *result = new ListNode<int>(0);
        
        int carry = sum(a,b,result);
        
        if (carry > 0)
        {
                ListNode<int> *holder = new ListNode<int>(carry);
                holder->next = result;
                result = holder;
        }
        
        return result;
}