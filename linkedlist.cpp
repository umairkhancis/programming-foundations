#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	Node* next;
};

Node* insert(int data, int n);
Node* remove(int n);
Node* reverse(Node* head);
void print();
void print(Node* p);
void printReverse(Node* p);

Node* head = NULL; // empty list
int main() {
	// // Insert elements at nth position; 0 based index
	head = insert(2, 0); 
	// print(); // 2
	head = insert(3, 0);
	// print(); // 3, 2
	head = insert(4, 1);
	// print(); // 3, 4, 2
	head = insert(6, 0);
	print();  // 6, 3, 4, 2

	// // Remove elements from nth position; 0 based index
	// head = remove(0);
	// print(); // 3, 4, 2
	// head = remove(1);
	// print(); // 3, 2

	// // Print elements of linked list using recurrsion
	// print(head);  // 6, 3, 4, 2
	// printReverse(head);  // 2, 4, 3, 6

	// // Reverse the linked list using iterative method
	printf("head->data = %d \n", head->data); // 6
	head = reverse(head);
	print(); // 2, 4, 3, 6
	printf("head->data = %d \n", head->data); // 2
}

Node* insert(int data, int n) {
	// create temp node
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	// handle special case for inserting at the begining of the linked list
	if(n == 0) {
		newNode->next = head;
		head = newNode;
		return head;
	}

	// iterate till (n-1)th node 
	Node* temp1 = head;
	for(int i = 0; i < n-1; i++) {
		temp1 = temp1->next;
	}

	// fix the links
	Node* temp2 = temp1->next; // nth Node
	temp1->next = newNode;
	newNode->next = temp2;

	return head;
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




