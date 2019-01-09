struct Node
{
    char data;
    Node *next;

    Node()
    {
        data = ' ';
        next = nullptr;
    }

    Node(char value)
    {
        data = value;
        next = nullptr;
    }

    void insertValue(char value)
    {
        Node *element = new Node(value);
        Node *last = this;
        while(last->next != nullptr)
        {
            last = last->next;
        }
        last->next = element;
    }

    Node *deleteNode(Node *root, char value)
    {
        Node *n = root;
        if (n->data == value)
        {
            return n->next;
        }

        while(n->next != nullptr)
        {
            if(n->next->data == value)
            {
                n->next = n->next->next;
                return root;
            }
            n = n->next;
        }
        return root;
    }




};