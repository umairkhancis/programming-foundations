bool isOpeningBrace(brace: String) {
	return (strcmp(b, "(") == 0 || strcmp(b, "{") == 0 || strcmp(b, "[") == 0);
}

bool isClosingBrace(brace: String) {
	return (brace == ")" || brace == "}" || brace == "]")
}

fun isBalanced(exp: String): Boolean {
	stack<string> s;
	for (int i = 0; i < exp.length(); ++i) {
		if(isOpeningBrace(exp[i])) {
			s.push(exp[i]);
		} else if(isClosingBrace(exp[i]) && isPair(exp[i], s.top())) {
			s.push(exp[i]);
		}
	}
}

fun main(args: Array<String>) {
	printf("%d\n", isBalanced("( A + B )"));
	printf("%d\n", isBalanced("{ A + B }"));
	printf("%d\n", isBalanced("[ A + B + {c - ed} ]"));
	printf("%d\n", isBalanced(")("));
	printf("%d\n", isBalanced("}"));
}

