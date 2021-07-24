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


# function to find height
def findheight(root):
    if root is None:
        return -1

    leftheight = findheight(root.left)
    rightheight = findheight(root.right)

    return max(leftheight, rightheight) + 1


if __name__ == "__main__":
    root = None

    root = Insert(root, 10)
    root = Insert(root, 8)
    root = Insert(root, 9)
    root = Insert(root, 7)
    root = Insert(root, 25)
    root = Insert(root, 30)
    root = Insert(root, 15)
    root = Insert(root, 45)

    print("Height of binary tree: " + str(findheight(root)))

# output:
# Height of binary tree: 3
