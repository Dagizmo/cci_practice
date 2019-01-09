#include "../node.h"
#include <iostream>

using namespace std;

void removeDuplicates(Node<char> *root)
{
    Node<char> *check = root;
    while(check->next != nullptr)
    {
        Node<char> *runner = check;
        while(runner->next != nullptr)
        {
            if(runner->next->data == check->data)
            {
                runner->next = runner->next->next;
            }
            else
            {
                runner = runner->next;
            }
        }
        if (check->next != nullptr)
        {
            check = check->next;
        }
    }
}

void printNodes(Node<char> *root)
{
    Node<char> *runner = root;
    while(runner->next != nullptr)
    {
        cout << runner->data << " ";
        runner = runner->next;
    }
    cout << runner->data << " " << endl;
}

int main()
{
    Node<char> *word = new Node<char>('a');
    word->insertValue('e');
    word->insertValue('l');
    word->insertValue('e');
    word->insertValue('a');
    word->insertValue('l');
    word->insertValue('l');
    word->insertValue('o');
    word->insertValue('o');
    word->insertValue('l');
    word->insertValue('x');

    printNodes(word);
    removeDuplicates(word);
    printNodes(word);
}
