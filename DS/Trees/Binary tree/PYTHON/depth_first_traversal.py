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


# preorder traversal
def preorder(root):
    if root is None:
        return

    print(root.data, end=" ")
    preorder(root.left)
    preorder(root.right)

# inorder traversal
def inorder(root):
    if root is None:
        return

    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)

# postorder traversal
def postorder(root):
    if root is None:
        return

    postorder(root.left)
    postorder(root.right)
    print(root.data, end=" ")


if __name__ == "__main__":
    root = None

    root = Insert(root, 10)
    root = Insert(root, 8)
    root = Insert(root, 9)
    root = Insert(root, 7)
    root = Insert(root, 25)
    root = Insert(root, 30)
    root = Insert(root, 15)

    print("Preorder:",end=" ")
    preorder(root)

    print("\nInorder:", end=" ")
    inorder(root)

    print("\nPostorder:", end=" ")
    postorder(root)

# output:
# Preorder: 10 8 7 9 25 15 30 
# Inorder: 7 8 9 10 15 25 30 
# Postorder: 7 9 8 15 30 25 10 
