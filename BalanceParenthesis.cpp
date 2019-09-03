#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<iostream>

using namespace std;

bool isOpeningBrace(string b) {
	return (strcmp(b, "(") == 0 || strcmp(b, "{") == 0 || strcmp(b, "[") == 0);
}

bool isClosingBrace(string b) {
	return (b == ")" || b == "}" || b == "]");
}

bool isBalanced(String exp) {
	stack<string> s;
	for (int i = 0; i < exp.length(); ++i) {
		if(isOpeningBrace(exp[i])) {
			s.push(exp[i]);
		} else if(isClosingBrace(exp[i]) && isPair(exp[i], s.top())) {
			s.push(exp[i]);
		}
	}
}

int main() {
	printf("%d\n", isBalanced("( A + B )"));
	printf("%d\n", isBalanced("{ A + B }"));
	printf("%d\n", isBalanced("[ A + B + {c - ed} ]"));
	printf("%d\n", isBalanced(")("));
	printf("%d\n", isBalanced("}"));
}

