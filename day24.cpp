#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int value) : data(value), next(nullptr) {}
};

void insertAtHead(node *&head, node *&tail, int value)
{
    if (head == NULL)
    {
        node *newNode = new node(value);
        head = newNode;
        tail = newNode;
        return;
    }
    node *newNode = new node(value);
    newNode->next = head;
    head = newNode;
}

void countNode(node *&head)
{

    // Code here
    int count = 1;
    node *temp = head;
    while (temp->next != nullptr)
    {
        count++;
        temp = temp->next;
    }
    std::cout << count;
}

void traverse(node *head, node *tail)
{
    if (!head)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != nullptr);

    cout << endl
         << "Head: " << head->data << endl
         << "Tail: " << tail->data << endl;
}
void insertAtAnyPosition(node *&head, node *&tail, int pos, int d)
{
    if (pos == 0)
    {
        insertAtHead(head, tail, d);
        return;
    }
    int count = 1;
    node *temp = head;
    while (count < pos)
    {

        temp = temp->next;
        count++;
    }

    // at this point we will know where the temp is and where we need to insert
    // code for handling insertion at last node
    node *newNode = new node(d);
    if (temp->next == nullptr)
    {
        tail = newNode;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
// node *middleNode(node *head, node *&tail, int x)
// {
//     // Code Here
//     // find the middle of the linked list
//     // finding count
//     node *temp = head;
//     int count = 0;
//     while (temp != nullptr)
//     {
//         temp = temp->next;
//         count++;
//     }
//     // find where to insert
//     cout << "Count : " << count << endl;
//     int ans = count / 2;
//     // insert value in linked list
//     node *newNode = new node(x);

//     insertAtAnyPosition(head, tail, ans, x);

//     return nullptr;
// }
node *middleNode(node *&head, int x)
{
    node *temp1 = head;
    int count1 = 0;
    while (temp1 != nullptr)
    {
        temp1 = temp1->next;
        count1++;
    }
    int ans = count1 / 2;
    // insert value in linked list
    node *newNode = new node(x);

    int count2 = 1;
    node *temp2 = head;
    while (count2 < ans)
    {

        temp2 = temp2->next;
        count2++;
    }
    newNode->next = temp2->next;
    temp2->next = newNode;
    return head;
}

bool isLengthEven(node *&head)
{
    // Code here
    node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {

        count++;
        temp = temp->next;
    }
    if (count % 2 == 0)
    {

        return true;
    }
    else
    {
        return false;
    }
}
// detecting a loop in a linked list
int main()
{

    node *head = nullptr;
    node *tail = nullptr;

    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);
    insertAtHead(head,tail,5);
    insertAtHead(head,tail,6);
    insertAtHead(head,tail,7);

    traverse(head, tail);
    // cout << endl
    //      << "countNode: " << endl;
    // countNode(head);

    return 0;
}