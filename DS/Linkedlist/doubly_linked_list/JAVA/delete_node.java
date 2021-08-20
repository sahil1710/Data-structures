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
        int nodeCount;          //nodeCount counts number of nodes

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
        //delete node
        public void remove(int index){
            node temp = head;
            if(index<0||index>nodeCount) {
                System.out.println("Invalid index");
            }
            else if(index==1){
                head = temp.next;
                head.prev = null;
            }
            else{
                index -= 1;
                //going at index node
                while ((index--)>0){
                    temp = temp.next;
                }

                //if node to be deleted is not the last node
                //change next
                if(temp.next!=null) temp.next.prev = temp.prev;

                //if node to be deleted is not the head node
                //change prev
                if(temp.prev!=null) temp.prev.next = temp.next;
            }
            nodeCount--;
        }

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
        dll.insertAtEnd(1);
        dll.insertAtEnd(2);
        dll.insertAtEnd(3);
        dll.insertAtEnd(4);

        System.out.print("list: ");
        dll.print();

        //remove one element
        dll.remove(1);
        System.out.print("After removing element: ");
        dll.print();
    }
}

//output:
//list: 1 2 3 4
//After removing element: 2 3 4
