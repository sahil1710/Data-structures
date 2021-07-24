#class

class BstNode:
    def __init__(self, num):
        self.data = num
        self.left = None
        self.right = None

#insert function

def Insert(pointer, data):
    if pointer is None:
        pointer = BstNode(data)

    elif data <= pointer.data:
        pointer.left = Insert(pointer.left, data)

    else:
        pointer.right = Insert(pointer.right, data)

    return pointer

#search function

def Search(pointer, data):
    if pointer is None:
        return False
    if data == pointer.data:
        return True

    elif data < pointer.data:
        return Search(pointer.left, data)

    else:
        return Search(pointer.right, data)

if __name__ == "__main__":

    root = None

    root = Insert(root, 10)
    root = Insert(root, 8)
    root = Insert(root, 9)
    root = Insert(root, 7)
    root = Insert(root, 25)
    root = Insert(root, 30)
    root = Insert(root, 15)

    num = int(input("Enter a number: "))

    print("Found" if Search(root, num) else "Not found")
   
# input: 8
# output: Found
