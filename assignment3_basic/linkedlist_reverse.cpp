/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

//###INSERT CODE HERE -
void insert_node(SinglyLinkedList *A,int x)
{
    SinglyLinkedListNode *newnode = new SinglyLinkedListNode(x);
    if(A->head == NULL)
    {
        A->head = newnode;
        A->tail = newnode;
    }
    else
    {
        A->tail->next = newnode;
        A->tail = newnode;
    }
}
void printLinkedList(SinglyLinkedList *A)
{
    SinglyLinkedListNode *newnode = A->head;
    while(newnode != NULL)
    {
        cout << newnode->data << " ";
        newnode = newnode->next;
    }
}
SinglyLinkedListNode* reverseLinkedList(SinglyLinkedList *A)
{
    SinglyLinkedListNode* current = A->head;
    SinglyLinkedListNode* prev = NULL;
    SinglyLinkedListNode* next_node = NULL;
    while(current != NULL)
    {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    A->head = prev;
    return A->head;
}
int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
