class Node:
    def __init__(self, num):
        self.data = num
        self.link = None


class LinkedList:

    def __init__(self):
        self.head = None

    # insert node at the end of linked list
    def append(self, num):
        temp = Node(num)
        if self.head is None:
            self.head = temp
            return

        temp1 = self.head
        while temp1.link is not None:
            temp1 = temp1.link

        temp1.link = temp

    def reverse(self):
        stack = []
        temp = self.head
        while temp is not None:
            stack.append(temp)
            temp = temp.link

        temp = stack.pop()
        self.head = temp

        while len(stack) != 0:
            temp.link = stack.pop()
            temp = temp.link

        temp.link = None

    # print
    def print_list(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.link


if __name__ == '__main__':
    l_list = LinkedList()

    l_list.append(1)
    l_list.append(2)
    l_list.append(3)
    l_list.append(4)
    l_list.append(5)

    l_list.reverse()

    l_list.print_list()

# output: 5 4 3 2 1
