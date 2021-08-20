//create class DoublyLinkedList
class DoublyLinkedList{
        //node class to create node
        static class node{
            int data;
            node next;
            node prev;

            //Constructor to create a new node
            node(int num){
                data = num;
                prev = null;
                next = null;
            }
        }

        node head;              //head pointer

        //insert node at the end of doublylinked list
        public void insertAtEnd(int data){
            node temp = new node(data);     //create new node
            if(head==null){
                head = temp;
            }
            else{
                node temp1 = head;

                //going at last node
                while (temp1.next!=null){
                    temp1 = temp1.next;
                }
                //changing links to add new node at end
                temp1.next = temp;
                temp.prev = temp1;
            }
        }

        public void print(){
            node temp = head;
            while (temp!=null){
                System.out.print(temp.data+" ");
                temp = temp.next;
            }
            System.out.print("\n");
        }

        //print linked list in reverse order
        public void reversePrint(){
            node temp = head;
            
            //going at last node
            while (temp.next!=null){ 
                temp = temp.next;
            }
            
            //traversing backward by using prev pointer
            while (temp!=null){
                System.out.print(temp.data+" ");
                temp = temp.prev;
            }
            System.out.print("\n");
        }
}

public class Main {

    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();  //create empty list
        dll.head = null;

        //insert elements
        dll.insertAtEnd(1);
        dll.insertAtEnd(2);
        dll.insertAtEnd(3);
        dll.insertAtEnd(4);
        System.out.print("List: ");
        dll.print();

        System.out.print("Reversed list: ");
        dll.reversePrint();
    }
}

//output:
//List: 1 2 3 4
//Reversed list: 4 3 2 1
