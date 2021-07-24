# node class
class BtNode:
    def __init__(self, num):
        self.data = num
        self.left = None
        self.right = None


# insert function

def Insert(pointer, data):
    if pointer is None:
        pointer = BtNode(data)

    elif data <= pointer.data:
        pointer.left = Insert(pointer.left, data)

    else:
        pointer.right = Insert(pointer.right, data)

    return pointer


# levelorder traversal
def levelorder(root):
    Q = []
    Q.append(root)

    while len(Q) != 0:
        node = Q.pop(0)

        print(node.data, end=" ")

        if node.left is not None:
            Q.append(node.left)

        if node.right is not None:
            Q.append(node.right)


if __name__ == "__main__":
    root = None

    root = Insert(root, 10)
    root = Insert(root, 8)
    root = Insert(root, 9)
    root = Insert(root, 7)
    root = Insert(root, 25)
    root = Insert(root, 30)
    root = Insert(root, 15)

    print("Levelorder:")
    levelorder(root)

# output:
# 10 8 25 7 9 15 30 
