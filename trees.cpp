#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};

BSTNode* createNode(int data);
BSTNode* insert(BSTNode* root, int data);
BSTNode* searchNode(BSTNode* root, int data);
BSTNode* findMax(BSTNode* root);
BSTNode* findMin(BSTNode* root);
void traverseLevelOrder(BSTNode* root);

int main() {
	BSTNode* root = NULL; // empty Tree

	root = insert(root, 20); // 	NULL/20\NULL
	root = insert(root, 10); // 	10/20\NULL
	root = insert(root, 30); // 	10/20\30
	root = insert(root, 8); // 		10/20\30 => 8/10\NULL 
	root = insert(root, 15); // 	10/20\30 => 8/10\15
	root = insert(root, 22); // 	10/20\30 => 8/10\15 22/30\NULL
	root = insert(root, 35); // 	10/20\30 => 8/10\15 22/30\35

	BSTNode* node = searchNode(root, 10); // found!

	printf("Min data in Tree is: %d\n", findMin(root)->data);
	printf("Max data in Tree is: %d\n", findMax(root)->data);

	traverseLevelOrder(root);

	return 0;
}

void traverseLevelOrder(BSTNode* root) {

	// Empty Tree Check!!
	if(root == NULL) {
		return;
	}

	queue<BSTNode*> q;
	q.push(root);

	while(!q.empty()) {
		BSTNode* current = q.front();
		printf("%d, ", current->data);

		if(current->left != NULL) {
			q.push(current->left);
		} 
		if(current->right != NULL) {
			q.push(current->right);
		} 

		q.pop();
	}

	printf("\n");
}

BSTNode* findMin(BSTNode* root) {
	if(root == NULL) {
		printf("Empty Tree!\n");
		exit(1);
	}


	if(root->left == NULL) {
		return root;
	} else {
		return findMin(root->left);
	}
}

BSTNode* findMax(BSTNode* root) {
	if(root == NULL) {
		printf("Empty Tree!\n");
		exit(1);
	}


	if(root->right == NULL) {
		return root;
	} else {
		return findMax(root->right);
	}
}

BSTNode* searchNode(BSTNode* root, int data) {
	if(root == NULL) {
		printf("Node Not Found!\n");
		return NULL;
	} 

	if(data < root->data) {
		searchNode(root->left, data);
	} else if(data > root->data) {
		searchNode(root->right, data);
	} else {
		printf("Node Found!\n");
	}

	return root;
}

BSTNode* insert(BSTNode* root, int data) {
	if(root == NULL) {
		root = createNode(data);
		return root;
	}

	if(data <= root->data) {
		root->left = insert(root->left, data);
	} else {
		root->right = insert(root->right, data);
	}

	return root;
}

BSTNode* createNode(int data) {
	BSTNode* node = new BSTNode();
	node->data = data;
	node->left = node->right = NULL;

	return node;
}



