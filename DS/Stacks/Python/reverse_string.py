def reverseString(str1, n):
    stack = []
    for i in range(n):
        stack.append(str1[i])

    str1 = ""

    for i in range(n):
        str1 = str1 + stack.pop()

    return str1


s = "HELLO"
print(reverseString(s, len(s)))

# output: OLLEH