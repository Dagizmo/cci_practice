#include "../node.h"
#include <iostream>

using namespace std;

Node<int> *sum(Node<int>* a, Node<int>* b)
{
    Node<int> *result = new Node<int>(-1);
    int carry = 0;
    Node<int> *runnerA = a;
    Node<int> *runnerB = b;

    while(runnerA != nullptr && runnerB != nullptr)
    {
        int sum = 0;
        if (runnerA != nullptr && runnerB != nullptr)
        {
            sum = runnerA->data + runnerB->data + carry;
            runnerA = runnerA->next;
            runnerB = runnerB->next;
        }
        else if (runnerA != nullptr && runnerB == nullptr)
        {
            sum = runnerA->data + carry;
            runnerA = runnerA->next;
        }
        else if (runnerB != nullptr && runnerA == nullptr)
        {
            sum = runnerB->data + carry;
            runnerB = runnerB->next;
        }
        if (sum >= 10)
        {
            sum -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        if (result->data == -1)
        {
            result->data = sum;
        }
        else
        {
            result->insertValue(sum);
        }
        
    }

    if (carry == 1)
    {
        result->insertValue(carry);
    }

    return result;
}


void printNodes(Node<int> *root)
{
    Node<int> *runner = root;
    while(runner->next != nullptr)
    {
        cout << runner->data << " ";
        runner = runner->next;
    }
    cout << runner->data << " " << endl;
}

int main()
{
    Node<int> *a = new Node<int>(7);
    a->insertValue(1);
    a->insertValue(6);

    Node<int> *b = new Node<int>(5);
    b->insertValue(9);
    b->insertValue(3);


    printNodes(a);
    cout << endl;
    printNodes(b);
    cout << endl;
    Node<int> *result = sum(a,b);
    printNodes(result);
    system("pause");
    return 0;
}