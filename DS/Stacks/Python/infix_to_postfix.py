def pre(ch):
    if ch == '*' or ch == '/':
        return 1
    elif ch == '+' or ch == '-':
        return 0
    else:
        return -1

def infix_to_postfix(s):
    stack = []
    top = -1

    result = ""
    for i in s:
        if i.isalnum():
            result += i

        elif i == '(':
            stack.append(i)
            top += 1

        elif i == ')':
            while stack[top] != '(':
                result += stack[top]
                top -= 1
                stack.pop()
            top -= 1
            stack.pop()

        else:
            while len(stack) != 0 and pre(i) <= pre(stack[top]):
                result += stack[top]
                stack.pop()
                top -= 1
            stack.append(i)
            top += 1

    while len(stack) != 0:
        result += stack.pop()

    return result

s = "((A+B)*C-D)*E"
print(infix_to_postfix(s))

# output : AB+C*D-E*