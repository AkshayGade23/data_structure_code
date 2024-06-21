#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
struct node // self referential structure
{
    int data;
    struct node *l_address;
    struct node *r_address;
};

struct node *head, *temp, *pre, *next, *p;

void new_node();
void iae();
void iam();
void iab();

void dae();
void dab();
void dam();

void display();

void main()
{
    int ch;
    head = NULL;
    temp = NULL;
    pre = NULL;
    next = NULL;
    p = NULL;

    while (1)
    {
        printf("\n*****Doubly Linked List operations ****");
        printf("\n1. Insert At beginning");
        printf("\n2. Insert at Middle");
        printf("\n3. Insertion at End");
        printf("\n4. Delete from begining");
        printf("\n5. Delete from Middle");
        printf("\n6. Deletion from End");
        printf("\n7. Display");
        printf("\n8. Exit");

        printf("\nEnter your Choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            new_node();
            iab();
            break;
        case 2:
            new_node();
            iam();
            break;
        case 3:
            new_node();
            iae();
            break;
        case 4:
            dab();
            break;
        case 5:
            dam();
            break;
        case 6:
            dae();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("\nWrong choice");
        }
        printf("\n--------------------");
    }
}
void new_node()
{
    int ele;
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter elementt\n");
    scanf("%d", &ele);

    p->data = ele;
    p->l_address = NULL;
    p->r_address = NULL;
}
void iae()
{
    if (head == NULL) // LL is not present
    {
        head = p;
    }
    else // LL is present
    {
        temp = head;
        while (temp->r_address != NULL) // traversing
        {
            temp = temp->r_address;
        }
        temp->r_address = p;
        p->l_address = temp;
    }
}
void display()
{
    if (head == NULL)
    {
        printf("\nLinked list is not present");
    }
    else
    {
        temp = head;
        printf("\nLinked List contains\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->r_address;
        }
    }
}
void dae()
{
    temp = head;
    pre = head;
    temp = temp->r_address;
    while (temp->r_address != NULL)
    {
        pre = temp;
        temp = temp->r_address;
    }
    printf("\n%d is deleted", temp->data);
    free(temp);
    pre->r_address = NULL;
}
void dab()
{
    temp = head;
    head = head->r_address;
    printf("\n%d is deleted", temp->data);
    free(temp);
}
void iam()
{
    int search, counter = 0;
    printf("Enter elemnt after which you want to insert new element\n");
    scanf("%d", &search);

    temp = head;
    pre = head;
    temp = temp->r_address;
    while (temp != NULL)
    {
        if (pre->data == search)
        {
            counter++;
            pre->r_address = p;
            p->l_address = pre;
            p->r_address = temp;
            temp->l_address = p;
            break;
        }
        else
        {
            pre = temp;
            temp = temp->r_address;
        }
    }
    if (counter == 0)
    {
        printf("\nSearching elemnt Not Found");
    }
}
void dam()
{
    int search, counter = 0;
    struct node *temp1;
    printf("\nEnter element that u want to delete\n");
    scanf("%d", &search);

    temp = head;
    pre = head;
    temp = temp->r_address;
    while (temp != NULL)
    {
        if (temp->data == search)
        {
            counter++;
            temp1 = temp;
            temp = temp->r_address;

            printf("\n%d is deleted", temp1->data);
            free(temp1);

            pre->r_address = temp;
            temp->l_address = pre;
            break;
        }
        else
        {
            pre = temp;
            temp = temp->r_address;
        }
    }
    if (counter == 0)
    {
        printf("\nSearching elemnt Not Found");
    }
}
void iab()
{
    if (head == NULL) // LL is Not present
    {
        head = p;
    }
    else // LL is Present
    {
        p->r_address = head;
        head->l_address = p;
        head = p;
    }
}