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

    # insert node at the front of linked list
    def insert_head(self, num):
        temp = Node(num)
        if self.head is None:
            head = temp
            return

        temp.link = self.head
        self.head = temp
    
    # insert a node at given position
    def insert_nth(self, loc, num):
        temp = Node(num)
        if loc == 1:
            temp.link = self.head
            self.head = temp
            return
        loc -= 2

        temp1 = self.head
        while loc:
            temp1 = temp1.link
            loc -= 1

        temp.link = temp1.link
        temp1.link = temp
    
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
    l_list.insert_head(6)
    l_list.insert_nth(3, 10)
    
    l_list.print_list()
    
    
