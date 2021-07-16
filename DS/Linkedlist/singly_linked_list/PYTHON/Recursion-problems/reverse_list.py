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
        

def reverse_list(self, pointer):
    temp = pointer
    if pointer.link is None:
        self.head = pointer
        return
    reverse_list(self, pointer.link)
    temp = pointer.link
    temp.link = pointer
    pointer.link = None
    

# print list
def print_list(pointer):
    if pointer is None:
        return
    print(pointer.data, end=" ")
    print_list(pointer.link)


if __name__ == '__main__':

    l_list = LinkedList()
    
    l_list.append(1)
    l_list.append(2)
    l_list.append(3)
    l_list.append(4)
    l_list.append(5)

    reverse_list(l_list, l_list.head)
    print_list(l_list.head)
