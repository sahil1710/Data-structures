def postfix(str1, n):
    stack = []

    for i in range(n):
        if str1[i].isnumeric():
            stack.append(int(str1[i]))

        else:
            if str1[i] == '+':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op1 + op2)

            elif str1[i] == '-':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op1 - op2)

            elif str1[i] == '*':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op1 * op2)

            elif str1[i] == '/':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op1 / op2)

    return stack.pop()


s = "23*54*+9-"
print(postfix(s, len(s)))

# output: 17
