def balanced_parentheses(str1):
    stack = []

    for i in str1:
        if i == '(' or i == '[' or i == '{':
            stack.append(i)

        elif i == ')' or i == ']' or i == '}':
            if len(stack) == 0:
                return "parentheses are not balanced"

            elif i == ')' and stack.pop() != '(':
                return "parentheses are not balanced"

            elif i == '}' and stack.pop() != '{':
                return "parentheses are not balanced"

            elif i == ']' and stack.pop() != '[':
                return "parentheses are not balanced"

    if not stack:
        return "parentheses are balanced"

    else:
        return "parentheses are not balanced"


s = "{}[](){[()][]}"
print(balanced_parentheses(s))

output: "parentheses are balanced"
