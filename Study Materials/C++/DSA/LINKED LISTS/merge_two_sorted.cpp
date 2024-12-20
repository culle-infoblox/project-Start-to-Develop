// merge two sorted linked lists
// in-place.
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

// Function to create newNode in a linkedlist=
Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
    cout<<endl;
}

// Merges two given lists in-place. This function
// mainly compares head nodes and calls mergeUtil()
Node* merge(Node* h1, Node* h2)
{
	if (!h1)
		return h2;
	if (!h2)
		return h1;
	// start with the linked list
	// whose head data is the least
	if (h1->data < h2->data) {
		h1->next = merge(h1->next, h2);
		return h1; 
	}
	else {
		h2->next = merge(h1, h2->next);
		return h2;
	}
}

int main()
{
	Node* head1 = newNode(1);
	head1->next = newNode(3);
	head1->next->next = newNode(5);
// 1 3 5 
    printList(head1);
	Node* head2 = NULL;
	// head2->next = newNode(7);
	// head2->next->next = newNode(8);
    printList(head2);
	Node* mergedhead = merge(head1, head2);
	printList(mergedhead);
	return 0;
}

