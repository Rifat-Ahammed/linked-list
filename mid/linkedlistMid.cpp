
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    // constructor creation
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};
void Insert_at_tail(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void Insert_at_head(Node *&head, int val)
{
    // new node creation;
    Node *newNode = new Node(val);

    // update of newNode->next;
    newNode->next = head;

    // update of head
    head = newNode;
}
void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->next != NULL)
        {
            cout << " ";
        }
        n = n->next;
    }
    cout << endl;
}
int length(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
int find_mid(Node *&head)
{
    if (head == NULL)
    {
        return -1;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}
int main()
{
    Node *head = NULL;

    int n, pos, mid;

    cout << "Choice: 1 - Insert_at_head " << endl
         << "Choice: 2 - Insert_at_tail " << endl
         << "Choice: 3 - Find Linked list Mid(slow and fast) " << endl
         << "Choice: 4 - Exit" << endl;
    int choice;
    cout << "Next Choice: ";
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter a value: ";
            cin >> n;
            Insert_at_head(head, n);
            break;

        case 2:
            cout << "Enter a value: ";
            cin >> n;
            Insert_at_tail(head, n);
            break;
        case 3:
            mid = find_mid(head);
            if (mid == -1)
            {
                cout << "This linked list is empty" << endl;
            }
            else
            {
                cout << "Mid is value is: " << mid << endl;
            }
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << "\nLinked List: ";
    display(head);
    cout << "Length of Linked List: " << length(head) << endl;

    return 0;
}
