def postfix(str1):
    stack = []

    for i in str1:
        if i.isnumeric():
            stack.append(int(i))

        else:
            if i == '+':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op1 + op2)

            elif i == '-':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op1 - op2)

            elif i == '*':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op1 * op2)

            elif i == '/':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op1 / op2)

    return stack.pop()


s = "23*54*+9-"
print(postfix(s))

# output: 17
