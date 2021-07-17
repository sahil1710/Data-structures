def prefix(str1, n):
    stack = []

    n -= 1

    while n >= 0:
        if str1[n].isnumeric():
            stack.append(int(str1[n]))

        else:
            if str1[n] == '+':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op2 + op1)

            elif str1[n] == '-':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op2 - op1)

            elif str1[n] == '*':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op2 * op1)

            elif str1[n] == '/':
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(op2 / op1)
        n -= 1

    return stack.pop()


s = "-+*23*549"
print(prefix(s, len(s)))

# output: 17