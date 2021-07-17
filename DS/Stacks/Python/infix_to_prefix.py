def pre(ch):
    if ch == '*' or ch == '/':
        return 1
    elif ch == '+' or ch == '-':
        return 0
    else:
        return -1


def infix_to_prefix(s, n):
    stack = []
    top = -1
    n -= 1

    result = ""
    while n >= 0:
        if s[n].isalnum():
            result += s[n]

        elif s[n] == ')':
            stack.append(s[n])
            top += 1

        elif s[n] == '(':
            while stack[top] != ')':
                result += stack[top]
                top -= 1
                stack.pop()
            top -= 1
            stack.pop()

        else:
            while len(stack) != 0 and pre(s[n]) <= pre(stack[top]):
                result += stack[top]
                stack.pop()
                top -= 1
            stack.append(s[n])
            top += 1
        n -= 1

    while len(stack) != 0:
        result += stack.pop()

    return result[::-1]


s = "((A*B)+(C*D))-E"
print(infix_to_prefix(s, len(s)))

# output: -+*AB*CDE