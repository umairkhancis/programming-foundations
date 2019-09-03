bool isOpeningBrace(brace: String) {
	return (brace == "(" || brace == "{" || brace == "[")
}

bool isClosingBrace(brace: String) {
	return ( brace == ")" || brace == "}" || brace == "]" )
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
	println("${2+2}")
}

