#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        this->data = val;
        next = NULL;
    }
};

class LinkedList
{
    node *head;

public:
    LinkedList()
    {
        this->head = NULL;
    }
    LinkedList(node *head)
    {
        this->head = head;
    }
    node *gethead();
    void setHead(node *head);
    void displayList();
    void insertAtTail(int val);
    void insertAtHead(int val);
    node *deleteByRank(int n);
    node *deleteByValue(int n);
    node *reverseList(node *head);
    node *findHalf();
    node *reverseKNodesList(node *head, int k);
    void makeCycle(int where);
    bool detectCycle();
    void removeCycle();
};

void LinkedList::setHead(node *head)
{
    this->head = head;
}

node *LinkedList::gethead()
{
    return head;
}

void LinkedList::insertAtTail(int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

void LinkedList::insertAtHead(int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void LinkedList::displayList()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *LinkedList::reverseList(node *head)
{
    if (head == NULL)
        return head;
    node *previous = NULL;
    node *current = head;
    node *next = head->next;

    while (next != NULL)
    {
        current->next = previous;
        previous = current;
        current = next;
        next = next->next;
    }
    current->next = previous;
    return current;
}

node *LinkedList::findHalf()
{
    node *slow = head;
    node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    return slow->next;
}

node *LinkedList::reverseKNodesList(node *head, int k)
{
    if (head == NULL || k <= 0)
        return head;

    node *previous = NULL;
    node *current = head;
    node *next;
    int i = 0;
    while (i < k && current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        i++;
    }
    if (next != NULL)
        head->next = reverseKNodesList(next, k);

    return previous;
}

void LinkedList::makeCycle(int where)
{
    node *traverse = head;
    node *connectTo;
    int count = 1;
    while (traverse->next != NULL)
    {
        if (count == where)
            connectTo = traverse;

        traverse = traverse->next;
        count++;
    }

    traverse->next = connectTo;
}

bool LinkedList::detectCycle()
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {

        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

void LinkedList::removeCycle()
{
    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

node *LinkedList::deleteByRank(int n)
{
    if (head == NULL)
        return head;
    if (n == 1)
    {
        node *temp = head->next;
        free(head);
        return temp;
    }

    node *current = head->next;
    node *previous = head;
    int i = 2;
    while (i < n && current->next != NULL)
    {
        previous = current;
        current = current->next;
        i++;
    }

    if (i == n)
        previous->next = current->next;

    free(current);
    return head;
}

node *LinkedList::deleteByValue(int n)
{
    if (head == NULL)
        return head;
    if (head->data == n)
    {
        node *temp = head->next;
        free(head);
        return temp;
    }
    node *current = head->next;
    node *previous = head;

    while (current->next != NULL)
    {
        if (current->data == n)
        {
            previous->next = current->next;
            break;
        }
        previous = current;
        current = current->next;
    }

    free(current);
    return head;
}

LinkedList mergeTwoLinkedList(LinkedList l1, LinkedList l2)
{
    if (l1.gethead() == NULL)
    {
        return LinkedList(l2.gethead());
    }
    if (l2.gethead() == NULL)
        return LinkedList(l1.gethead());

    LinkedList result;
    if (l1.gethead()->data < l2.gethead()->data)
    {
        result = LinkedList(l1.gethead());
        result.gethead()->next = mergeTwoLinkedList(LinkedList(l1.gethead()->next), LinkedList(l2.gethead())).gethead();
    }
    else
    {
        result = LinkedList(l2.gethead());
        result.gethead()->next = mergeTwoLinkedList(LinkedList(l1.gethead()), LinkedList(l2.gethead()->next)).gethead();
    }
    result.displayList();
    return result;
}

void evenAfterOdd(LinkedList l){
    node * odd = l.gethead();
    node * evenStart= odd->next;
    node * even = evenStart;

    while(odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd= odd->next;
        even ->next= odd->next;
        even = even->next;
    }
    if(odd->next != NULL)
      even->next = NULL;
   
   odd->next =evenStart;
}

int main()
{
    LinkedList l1;

    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.insertAtTail(5);
    l1.insertAtTail(6);
    l1.insertAtTail(7);

    LinkedList l2;
    l2.insertAtTail(4);
    l2.insertAtTail(5);
    l2.insertAtTail(6);
    l2.insertAtTail(7);

l1.displayList();      
evenAfterOdd(l1);
l1.displayList();      
    return 0;
}