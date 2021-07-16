class Node:
    def __init__(self, num):
        self.data = num
        self.link = None


class LinkedList:

    def __init__(self):
        self.head = None
        
    # insert node
    def append(self, num):
        temp = Node(num)
        if self.head is None:
            self.head = temp
            return

        temp1 = self.head
        while temp1.link is not None:
            temp1 = temp1.link

        temp1.link = temp

# print list
def print_list(pointer):
    if pointer is None:
        return
    print(pointer.data, end=" ")
    print_list(pointer.link)

# print list in reverse order
def print_reverse(pointer):
    if pointer is None:
        return
    print_reverse(pointer.link)
    print(pointer.data, end=" ")


if __name__ == '__main__':

    l_list = LinkedList()
    
    l_list.append(1)
    l_list.append(2)
    l_list.append(3)
    l_list.append(4)
    l_list.append(5)

    print_list(l_list.head)
    print_reverse(l_list.head)
