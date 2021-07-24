# node class
class BstNode:
    def __init__(self, num):
        self.data = num
        self.left = None
        self.right = None


# insert function

def Insert(pointer, data):
    if pointer is None:
        pointer = BstNode(data)

    elif data <= pointer.data:
        pointer.left = Insert(pointer.left, data)

    else:
        pointer.right = Insert(pointer.right, data)

    return pointer


# function to find max integer in BST
def findmax(root):
    if root is None:
        return

    while root.right is not None:
        root = root.right

    return root.data


# function to find min integer in BST
def findmin(root):
    if root is None:
        print("Error: tree is empty")
        return

    while root.left is not None:
        root = root.left

    return root.data


if __name__ == "__main__":
    root = None

    root = Insert(root, 10)
    root = Insert(root, 8)
    root = Insert(root, 9)
    root = Insert(root, 7)
    root = Insert(root, 25)
    root = Insert(root, 30)
    root = Insert(root, 15)

    print("MAX: " + str(findmax(root)))
    print("MIN: " + str(findmin(root)))

# output:
# MAX: 30
# MIN: 7
