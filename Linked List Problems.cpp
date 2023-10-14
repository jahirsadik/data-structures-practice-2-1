// Recursive program to check if a given linked list is palindrome
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct node {
    char data;
    struct node* next;
};

// Initial parameters to this function are &head and head
bool isPalindromeUtil(struct node** left, struct node* right)
{
    /* stop recursion when right becomes NULL */
    if (right == NULL)
        return true;

    /* If sub-list is not palindrome then no need to
       check for current left and right, return false */
    bool isp = isPalindromeUtil(left, right->next);
    if (isp == false)
        return false;

    /* Check values at current left and right */
    bool isp1 = (right->data == (*left)->data);

    /* Move left to next node */
    *left = (*left)->next;

    return isp1;
}

// A wrapper over isPalindromeUtil()
bool isPalindrome(struct node* head)
{
    isPalindromeUtil(&head, head);
}

/* Push a node to linked list. Note that this function
  changes the head */
void push(struct node** head_ref, char new_data)
{
    /* allocate node */
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to pochar to the new node */
    (*head_ref) = new_node;
}

// A utility function to print a given linked list
void printList(struct node* ptr)
{
    while (ptr != NULL) {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    char str[] = "abacaba";
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        push(&head, str[i]);
        printList(head);
        isPalindrome(head) ? printf("Is Palindrome\n\n") : printf("Not Palindrome\n\n");
    }

    return 0;
}










// C program to sort Linked List
// using Bubble Sort
// by swapping nodes

#include <stdio.h>
#include <stdlib.h>

/* structure for a node */
struct Node {
	int data;
	struct Node* next;
} Node;

/*Function to swap the nodes */
struct Node* swap(struct Node* ptr1, struct Node* ptr2)
{
	struct Node* tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return ptr2;
}

/* Function to sort the list */
int bubbleSort(struct Node** head, int count)
{
	struct Node** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++) {

		h = head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++) {

			struct Node* p1 = *h;
			struct Node* p2 = p1->next;

			if (p1->data > p2->data) {

				/* update the link after swapping */
				*h = swap(p1, p2);
				swapped = 1;
			}

			h = &(*h)->next;
		}

		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
}

/* Function to print the list */
void printList(struct Node* n)
{
	while (n != NULL) {
		printf("%d -> ", n->data);
		n = n->next;
	}
	printf("\n");
}

/* Function to insert a struct Node
at the beginning of a linked list */
void insertAtTheBegin(struct Node** start_ref, int data)
{
	struct Node* ptr1
		= (struct Node*)malloc(sizeof(struct Node));

	ptr1->data = data;
	ptr1->next = *start_ref;
	*start_ref = ptr1;
}

// Driver Code
int main()
{
	int arr[] = { 78, 20, 10, 32, 1, 5 };
	int list_size, i;

	/* start with empty linked list */
	struct Node* start = NULL;
	list_size = sizeof(arr) / sizeof(arr[0]);

	/* Create linked list from the array arr[] */
	for (i = 0; i < list_size; i++)
		insertAtTheBegin(&start, arr[i]);

	/* print list before sorting */
	printf("Linked list before sorting\n");
	printList(start);

	/* sort the linked list */
	bubbleSort(&start, list_size);

	/* print list after sorting */
	printf("Linked list after sorting\n");
	printList(start);

	return 0;
}













// C++ code for linked list merged sort
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

/* function prototypes */
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
					Node** frontRef, Node** backRef);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(Node** headRef)
{
	Node* head = *headRef;
	Node* a;
	Node* b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
	and return the two lists using the reference parameters.
	If the length is odd, the extra node should go in the front list.
	Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node* source,
					Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	Node* res = NULL;
	Node* a = NULL;

	/* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	/* Sort the above created Linked List */
	MergeSort(&a);

	cout << "Sorted Linked List is: \n";
	printList(a);

	return 0;
}

// This is code is contributed by rathbhupendra









// C++ implementation to count pairs from both linked
// lists whose sum is equal to a given value
#include <bits/stdc++.h>
using namespace std;

/* A Linked list node */
struct Node
{
int data;
struct Node* next;
};

// function to insert a node at the
// beginning of the linked list
void push(struct Node** head_ref, int new_data)
{
/* allocate node */
struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

/* put in the data */
new_node->data = new_data;

/* link the old list to the new node */
new_node->next = (*head_ref);

/* move the head to point to the new node */
(*head_ref) = new_node;
}

// function to count all pairs from both the linked lists
// whose sum is equal to a given value
int countPairs(struct Node* head1, struct Node* head2, int x)
{
	int count = 0;

	struct Node *p1, *p2;

	// traverse the 1st linked list
	for (p1 = head1; p1 != NULL; p1 = p1->next)

		// for each node of 1st list
		// traverse the 2nd list

		for (p2 = head2; p2 != NULL; p2 = p2->next)

			// if sum of pair is equal to 'x'
			// increment count
			if ((p1->data + p2->data) == x)
				count++;

	// required count of pairs
	return count;
}

// Driver program to test above
int main()
{
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;

	// create linked list1 3->1->5->7
	push(&head1, 7);
	push(&head1, 5);
	push(&head1, 1);
	push(&head1, 3);

	// create linked list2 8->2->5->3
	push(&head2, 3);
	push(&head2, 5);
	push(&head2, 2);
	push(&head2, 8);

	int x = 10;

	cout << "Count = "
		<< countPairs(head1, head2, x);
	return 0;
}













// C++ program for Quick Sort on Singly Linled List
#include <iostream>
#include <cstdio>
using namespace std;

/* a node of the singly linked list */
struct Node
{
	int data;
	struct Node *next;
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = new Node;

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

// Returns the last node of the list
struct Node *getTail(struct Node *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}

// Partitions the list taking the last element as the pivot
struct Node *partition(struct Node *head, struct Node *end,
					struct Node **newHead, struct Node **newEnd)
{
	struct Node *pivot = end;
	struct Node *prev = NULL, *cur = head, *tail = pivot;

	// During partition, both the head and end of the list might change
	// which is updated in the newHead and newEnd variables
	while (cur != pivot)
	{
		if (cur->data < pivot->data)
		{
			// First node that has a value less than the pivot - becomes
			// the new head
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}
		else // If cur node is greater than pivot
		{
			// Move cur node to next of tail, and change tail
			if (prev)
				prev->next = cur->next;
			struct Node *tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}

	// If the pivot data is the smallest element in the current list,
	// pivot becomes the head
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	// Update newEnd to the current last node
	(*newEnd) = tail;

	// Return the pivot node
	return pivot;
}


//here the sorting happens exclusive of the end node
struct Node *quickSortRecur(struct Node *head, struct Node *end)
{
	// base condition
	if (!head || head == end)
		return head;

	Node *newHead = NULL, *newEnd = NULL;

	// Partition the list, newHead and newEnd will be updated
	// by the partition function
	struct Node *pivot = partition(head, end, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur for
	// the left part.
	if (newHead != pivot)
	{
		// Set the node before the pivot node as NULL
		struct Node *tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;

		// Recur for the list before pivot
		newHead = quickSortRecur(newHead, tmp);

		// Change next of last node of the left half to pivot
		tmp = getTail(newHead);
		tmp->next = pivot;
	}

	// Recur for the list after the pivot element
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}

// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(struct Node **headRef)
{
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef));
	return;
}

// Driver program to test above functions
int main()
{
	struct Node *a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);

	cout << "Linked List before sorting \n";
	printList(a);

	quickSort(&a);

	cout << "Linked List after sorting \n";
	printList(a);

	return 0;
}


















// Function to insert a new node at the
// end of linked list using recursion.
Node* insertEnd(Node* head, int data)
{
    // If linked list is empty, create a
    // new node (Assuming newNode() allocates
    // a new node with given data)
    if (head == NULL)
         return newNode(data);

    // If we have not reached end, keep traversing
    // recursively.
    else
        head->next = insertEnd(head->next, data);
    return head;
}



















void traverse(Node* head)
{
    if (head == NULL)
       return;

    // If head is not NULL, print current node
    // and recur for remaining list
    cout << head->data << " ";

    traverse(head->next);
}















// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

// Function to return the intersection point
// of the two linked lists head1 and head2
int getIntesectionNode(Node* head1, Node* head2)
{
	Node* current1 = head1;
	Node* current2 = head2;

	// If one of the head is NULL
	if (!current1 or !current2)
		return -1;

	// Continue until we find intersection node
	while (current1 and current2
		and current1 != current2) {
		current1 = current1->next;
		current2 = current2->next;

		// If we get intersection node
		if (current1 == current2)
			return current1->data;

		// If one of them reaches end
		if (!current1)
			current1 = head2;
		if (!current2)
			current2 = head1;
	}

	return current1->data;
}

// Driver code
int main()
{
	/*
		Create two linked lists

		1st 3->6->9->15->30
		2nd 10->15->30

		15 is the intersection point
	*/

	Node* newNode;

	// Addition of new nodes
	Node* head1 = new Node();
	head1->data = 10;

	Node* head2 = new Node();
	head2->data = 3;

	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;

	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	cout << getIntesectionNode(head1, head2);

	return 0;
}















// C++ implementation to modify the contents of
// the linked list
#include <bits/stdc++.h>
using namespace std;

/* Linked list node */
struct Node
{
	int data;
	struct Node* next;
};

/* function prototype for printing the list */
void printList(struct Node*);

/* Function to insert a node at the beginning of
the linked list */
void push(struct Node **head_ref, int new_data)
{
/* allocate node */
struct Node* new_node =
			(struct Node*) malloc(sizeof(struct Node));

/* put in the data */
new_node->data = new_data;

/* link the old list at the end of the new node */
new_node->next = *head_ref;

/* move the head to point to the new node */
*head_ref = new_node;
}

/* Split the nodes of the given list
into front and back halves,
and return the two lists
using the reference parameters.
Uses the fast/slow pointer strategy. */
void frontAndBackSplit(struct Node *head,
			struct Node **front_ref, struct Node **back_ref)
{
	Node *slow, *fast;

	slow = head;
	fast = head->next;

	/* Advance 'fast' two nodes, and
	advance 'slow' one node */
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list,
		so split it in two at that point. */
	*front_ref = head;
	*back_ref = slow->next;
	slow->next = NULL;
}

/* Function to reverse the linked list */
void reverseList(struct Node **head_ref)
{
	struct Node *current, *prev, *next;
	current = *head_ref;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

// perfrom the required subtraction operation on
// the 1st half of the linked list
void modifyTheContentsOf1stHalf(struct Node *front,
								struct Node *back)
{
	// traversing both the lists simultaneously
	while (back != NULL)
	{
		// subtraction operation and node data
		// modification
		front->data = front->data - back->data;

		front = front->next;
		back = back->next;
	}
}

// function to concatenate the 2nd(back) list at the end of
// the 1st(front) list and returns the head of the new list
struct Node* concatFrontAndBackList(struct Node *front,
									struct Node *back)
{
	struct Node *head = front;

	while (front->next != NULL)
		front = front->next;

	front->next = back;

	return head;
}

// function to modify the contents of the linked list
struct Node* modifyTheList(struct Node *head)
{
	// if list is empty or contains only single node
	if (!head || head->next == NULL)
		return head;

	struct Node *front, *back;

	// split the list into two halves
	// front and back lists
	frontAndBackSplit(head, &front, &back);

	// reverse the 2nd(back) list
	reverseList(&back);

	// modify the contents of 1st half
	modifyTheContentsOf1stHalf(front, back);

	// agains reverse the 2nd(back) list
	reverseList(&back);

	// concatenating the 2nd list back to the
	// end of the 1st list
	head = concatFrontAndBackList(front, back);

	// pointer to the modified list
	return head;
}

// function to print the linked list
void printList(struct Node *head)
{
	if (!head)
		return;

	while (head->next != NULL)
	{
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << head->data << endl;
}

// Driver program to test above
int main()
{
	struct Node *head = NULL;

	// creating the linked list
	push(&head, 10);
	push(&head, 7);
	push(&head, 12);
	push(&head, 8);
	push(&head, 9);
	push(&head, 2);

	// modify the linked list
	head = modifyTheList(head);

	// print the modified linked list
	cout << "Modified List:" << endl;
	printList(head);
	return 0;
}















// C++ implementation of the approach
#include<bits/stdc++.h>
using namespace std;

class LinkedList
{
	public:

	// Linked list Node
	class Node
	{
		public:
		int data;
		Node* next;
		Node(int d)
		{
			data = d;
			next = NULL;
		}
	};

	// Head of list
	Node* head;

	// Function to delete the nth node from
	// the end of the given linked list
	Node* deleteNode(int key)
	{

		// First pointer will point to
		// the head of the linked list
		Node *first = head;

		// Second pointer will poin to the
		// Nth node from the beginning
		Node *second = head;
		for (int i = 0; i < key; i++)
		{

			// If count of nodes in the given
			// linked list is <= N
			if (second->next == NULL)
			{

				// If count = N i.e.
				// delete the head node
				if (i == key - 1)
					head = head->next;
				return head;
			}
			second = second->next;
		}

		// Increment both the pointers by one until
		// second pointer reaches the end
		while (second->next != NULL)
		{
			first = first->next;
			second = second->next;
		}

		// First must be pointing to the
		// Nth node from the end by now
		// So, delete the node first is pointing to
		first->next = first->next->next;
		return head;
	}

	// Function to insert a new Node
	// at front of the list
	Node* push(int new_data)
	{
		Node* new_node = new Node(new_data);
		new_node->next = head;
		head = new_node;
		return head;
	}

	// Function to print the linked list
	void printList()
	{
		Node* tnode = head;
		while (tnode != NULL)
		{
			cout << (tnode->data) << ( " ");
			tnode = tnode->next;
		}
	}
};

// Driver code
int main()
{
	LinkedList* llist = new LinkedList();

	llist->head = llist->push(7);
	llist->head = llist->push(1);
	llist->head = llist->push(3);
	llist->head = llist->push(2);

	cout << ("Created Linked list is:\n");
	llist->printList();

	int N = 1;
	llist->head = llist->deleteNode(N);

	cout << ("\nLinked List after Deletion is:\n");
	llist->printList();
}

// This code is contributed by Arnab Kundu





















/* C++ Program to remove duplicates from a sorted linked list */
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
};

/* The function removes duplicates from a sorted list */
void removeDuplicates(Node* head)
{
	/* Pointer to traverse the linked list */
	Node* current = head;

	/* Pointer to store the next pointer of a node to be deleted*/
	Node* next_next;

	/* do nothing if the list is empty */
	if (current == NULL)
	return;

	/* Traverse the list till last node */
	while (current->next != NULL)
	{
	/* Compare current node with next node */
	if (current->data == current->next->data)
	{
		/* The sequence of steps is important*/
		next_next = current->next->next;
		free(current->next);
		current->next = next_next;
	}
	else /* This is tricky: only advance if no deletion */
	{
		current = current->next;
	}
	}
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Let us create a sorted linked list to test the functions
	Created linked list will be 11->11->11->13->13->20 */
	push(&head, 20);
	push(&head, 13);
	push(&head, 13);
	push(&head, 11);
	push(&head, 11);
	push(&head, 11);

	cout<<"Linked list before duplicate removal ";
	printList(head);

	/* Remove duplicates from linked list */
	removeDuplicates(head);

	cout<<"\nLinked list after duplicate removal ";
	printList(head);

	return 0;
}

// This code is contributed by rathbhupendra





















// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the linked list
struct Node {
	int data;
	Node* next;
};

// Function to create a new node
Node* create_Node(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

// Function to print the linked list
void print(Node* head)
{

	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// Function to add one to a number
// represented as linked list
Node* addOne(Node* head)
{

	// To store the last node in the linked
	// list which is not equal to 9
	Node* last = NULL;
	Node* cur = head;

	// Iterate till the last node
	while (cur->next != NULL) {

		if (cur->data != 9) {
			last = cur;
		}
		cur = cur->next;
	}

	// If last node is not equal to 9
	// add 1 to it and return the head
	if (cur->data != 9) {
		cur->data++;
		return head;
	}

	// If list is of the type 9 -> 9 -> 9 ...
	if (last == NULL) {
		last = new Node();
		last->data = 0;
		last->next = head;
		head = last;
	}

	// For cases when the righmost node which
	// is not equal to 9 is not the last
	// node in the linked list
	last->data++;
	last = last->next;

	while (last != NULL) {
		last->data = 0;
		last = last->next;
	}

	return head;
}

// Driver code
int main()
{
	Node* head = create_Node(1);
	head->next = create_Node(2);
	head->next->next = create_Node(9);
	head->next->next->next = create_Node(9);

	cout << "Original list is : ";
	print(head);

	head = addOne(head);

	cout << "Resultant list is : ";
	print(head);

	return 0;
}


















// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Link list node
struct node {
	int data;
	struct node* next;
};

// Function to insert a node at
// the head of the linked list
void push(node** head_ref, int new_data)
{
	/* Allocate node */
	node* new_node = new node();

	/* Put in the data */
	new_node->data = new_data;

	/* Link the old list off the new node */
	new_node->next = (*head_ref);

	/* Move the head to point to the new node */
	(*head_ref) = new_node;
}

// Function to print the linked list
void printList(node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

/* Function to reverse the linked list in groups of
size k and return the pointer to the new head node. */
struct node* reverse(struct node* head, int k)
{

	if (head == NULL)
		return head;

	// Create deque to store the address
	// of the nodes of the linked list
	deque<node*> q;

	// Store head pointer in current to
	// traverse the linked list
	node* current = head;
	int i;

	// Iterate through the entire linked
	// list by moving the current
	while (current != NULL) {
		i = 1;

		// Store addresses of the k
		// nodes in the deque
		while (i <= k) {
			if (current == NULL)
				break;
			q.push_back(current);
			current = current->next;
			i++;
		}

		/* pop first and the last value from
		the deque and swap the data values at
		those addresses
		Do this till there exist an address in
		the deque or deque is not empty*/
		while (!q.empty()) {
			node* front = q.front();
			node* last = q.back();
			swap(front->data, last->data);

			// pop from the front if
			// the deque is not empty
			if (!q.empty())
				q.pop_front();

			// pop from the back if
			// the deque is not empty
			if (!q.empty())
				q.pop_back();
		}
	}
	return head;
}

// Driver code
int main()
{

	// Start with the empty list
	node* head = NULL;

	// Created Linked list is
	// 1->2->3->4->5->6->7->8->9->10
	push(&head, 10);
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	int k = 2;

	// Get the new head after reversing the
	// linked list in groups of size k
	head = reverse(head, k);
	printList(head);

	return 0;
}
