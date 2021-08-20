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
        int nodeCount = 0;      //nodeCount counts number of nodes

        //insert node at the front of doublylinked list
        public void insertAtHead(int data){
            node temp = new node(data);     //create new node

            if(head!=null){
                temp.next = head;
                head.prev = temp;
            }
            head = temp;
            nodeCount++;
        }

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
            nodeCount++;
        }

        //insert node at given index
        public void insert(int index, int data){
            if(index>nodeCount){
                System.out.println("Invalid index");
                return;
            }
            node temp = new node(data);
            if (index==1){
                head.prev = temp;
                temp.next = head;
                head = temp;
                return;
            }

            index -= 2;
            node temp1 = head;

            //going at (index-1) node
            while ((index--)>0){
                temp1 = temp1.next;
            }
            //changing links to add new node at given index
            temp.next = temp1.next;
            temp.prev = temp1;
            temp1.next = temp;
            nodeCount++;
        }

        //print linked list
        public void print(){
            node temp = head;
            while (temp!=null){
                System.out.print(temp.data+" ");
                temp = temp.next;
            }
            System.out.print("\n");
        }
}

public class Main {

    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();  //create empty list
        dll.head = null;

        //insert elements
        dll.insertAtHead(1);
        dll.insertAtEnd(3);
        dll.insertAtEnd(4);
        dll.insert(2,2);
        System.out.print("list: ");
        dll.print();
    }
}

//output:
//list: 1 2 3 4
