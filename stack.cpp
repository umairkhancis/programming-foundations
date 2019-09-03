#include<stdio.h>
#include<stdlib.h>
#define MAX 100

class Stack { 
    int top; 
  
public: 
    int a[MAX]; // Maximum size of Stack 
  
    Stack() { top = -1; } 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty();
    void print(); // just for debugging purpose. 
}; 
  
bool Stack::push(int x) 
{ 
    if (top >= (MAX - 1)) { 
        printf("Stack Overflow"); 
        return false; 
    } 
    else { 
        a[++top] = x; 
        printf("pushed into stack %d\n", x); 
        return true; 
    } 
} 
  
int Stack::pop() 
{ 
    if (top < 0) { 
    	printf("Stack Underflow\n");
        return 0; 
    } 
    else { 
        int x = a[top--];
		printf("Pop from stack %d\n", x);
        return x; 
    } 
} 
int Stack::peek() 
{ 
    if (top < 0) { 
    	printf("Stack is Empty\n");
        return 0; 
    } 
    else { 
        int x = a[top]; 
        return x; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 

void Stack::print() 
{ 
    for (int i = 0; i <= top; ++i) {
    	printf("%d ", a[i]);
    }

    printf("\n");
} 


int main() {
	Stack stack = Stack();
	stack.pop(); // underflow
	stack.push(2); stack.print(); // 2
	stack.push(5); stack.print(); // 2, 5
	stack.push(10); stack.print(); // 2, 5, 10
	stack.pop(); stack.print(); // 2, 5
	stack.pop(); stack.print(); // 2
	stack.pop(); stack.print();
	stack.pop(); stack.print(); // underflow
}



















