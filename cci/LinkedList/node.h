
template <typename T>
struct Node
{
    T data;
    Node *next;

    Node()
    {
        data = ' ';
        next = nullptr;
    }

    Node(T value)
    {
        data = value;
        next = nullptr;
    }

    void insertValue(T value)
    {
        Node *element = new Node(value);
        Node *last = this;
        while(last->next != nullptr)
        {
            last = last->next;
        }
        last->next = element;
    }

    Node *deleteNode(Node *root, T value)
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