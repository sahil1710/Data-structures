def balanced_parentheses(str1, n):
    stack = []

    for i in range(n):
        c = str1[i]
        if c == '(' or c == '[' or c == '{':
            stack.append(c)

        elif c == ')' or c == ']' or c == '}':
            if len(stack) == 0:
                return "parentheses are not balanced"

            elif c == ')' and stack.pop() != '(':
                return "parentheses are not balanced"

            elif c == '}' and stack.pop() != '{':
                return "parentheses are not balanced"

            elif c == ']' and stack.pop() != '[':
                return "parentheses are not balanced"

    if not stack:
        return "parentheses are balanced"

    else:
        return "parentheses are not balanced"


s = "{}[](){[()][]}"
print(balanced_parentheses(s, len(s)))

output: "parentheses are balanced"
