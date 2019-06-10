#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	Node* next;
};


Node* add(int data);
Node* add(int data, int n);

Node* remove(int n);

Node* reverse(Node* head);


// Helper functions
void print();
void print(Node* p);
void printReverse(Node* p);
int getNoOfNodes();

// test cases
void testAdd();

Node* head = NULL; // empty list
int main() {
	testAdd(); // 0->2->7->4->9->1->3->99->NULL - current state
}

Node* add(int data) {
	// Prepare newNode
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	Node* curr = head;
	// handle the special case when list is empty
	if(curr == NULL) {
		head = newNode;
		return head;
	}

	// iterate to the last element of linkedlist
	while(curr->next != NULL) curr = curr->next;

	// add newNode to the last
	curr->next = newNode;

	return head;
}

Node* add(int data, int n) {
	// Prepare newNode
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	Node* curr = head;

	// handle the special case when list is empty
	if(curr == NULL) {
		head = newNode;
		return head;
	}
	
	// validate n is a valid position for addition or not?
	if(n < (getNoOfNodes()-1) ) {
		// special case for first position
		if(n == 0) {
			newNode->next = head;
			head = newNode;
		} else {
			// iterate to the prevToNthPosition element of linkedlist
			for(int i=0; i<n-1; i++) curr = curr->next;

			Node* nthNode = curr->next;
			curr->next = newNode;
			newNode->next = nthNode;
		}

		return head;
	} else {
		printf("Position %d is invalid for this linkedlist; Hence returning the same linkedlist head\n", n);
		return head;
	}
}

Node* remove(int n) {

	Node* firstNode = head;
	if(n == 0) {
		head = firstNode->next;
		delete firstNode;
		return head;
	}

	Node* prevOfNthNode = head;
	for(int i =0; i < n-1; i++) {
		prevOfNthNode = prevOfNthNode->next;
	}

	Node* nthNode = prevOfNthNode->next;
	prevOfNthNode->next = nthNode->next;
	delete nthNode;
	return head;
}

void print() {
	Node* current = head;
	while(current != NULL) {
		printf("%d->", current->data);
		current = current-> next;
	}

	printf("NULL\n");
}

void print(Node* p) {
	if(p == NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d->", p->data);
	print(p->next);
}

void printReverse(Node* p) {
	if(p == NULL) {
		return;
	}

	printReverse(p->next);
	printf("%d ", p->data);
}

Node* reverse(Node* head) {
	// temp nodes for bookeeping
	Node* current = head;
	Node* prev = NULL;
	Node* next = NULL;

	// iterate till end
	while(current != NULL) {
		next = current->next; // bookeeping for next node
		
		current->next = prev; // reverse the link

		prev = current; // bookeeping for prev node
		current = next; // move forward 
	}

	// reset head
	head = prev;

	return head;
}

int getNoOfNodes() {
	Node* curr = head;
	int size = 0;

	while(curr != NULL) {
		size++;
		curr = curr->next;
	}

	return size;
}

void testAdd() {
	head = add(2);
	head = add(4);
	head = add(1);
	head = add(3);
	head = add(7, 1); // 2->7->4->1->3->NULL
	head = add(9, 3); // 2->7->4->9->1->3->NULL
	head = add(0, 0); // 0->2->7->4->9->1->3->NULL
	head = add(99); // 0->2->7->4->9->1->3->99->NULL
	printf("count is: %d\n", getNoOfNodes());
	print();
}