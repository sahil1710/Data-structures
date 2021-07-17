def reverseString(str1, n):
    stack = []
    for i in str1:
        stack.append(i)

    str1 = ""

    for i in range(n):
        str1 = str1 + stack.pop()

    return str1


s = "HELLO"
print(reverseString(s, len(s)))

# output: OLLEH
