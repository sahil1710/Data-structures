import java.util.Stack;

public class Linkedlist {
    Node head;

    static class Node
    {
        int data;
        Node link;

        Node(int num){
            data = num;
            link = null;
        }
    }

    //insert a node at the end of linked list
    public void append(int num){
        Node temp = new Node(num);
        if(head == null){
            head = temp;
            return;
        }
        Node temp1 = head;
        while (temp1.link!=null){
            temp1 = temp1.link;
        }

        temp1.link = temp;
    }

    public void reverse() {
        Node temp = head;
        Stack<Node> stack = new Stack<Node>();
        while (temp != null) {
            stack.push(temp);
            temp = temp.link;
        }
        temp = stack.peek();
        head = temp;
        stack.pop();

        while (!stack.empty()){
            temp.link = stack.peek();
            temp = temp.link;
            stack.pop();
        }
        temp.link = null;
    }

    //print linked list
    public void print(){
        Node temp = head;
        while (temp!=null){
            System.out.print(temp.data + " ");
            temp = temp.link;
        }
    }

    //main
    public static void main(String[] args){
        Linkedlist list = new Linkedlist();
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);

        list.reverse();

        list.print();
    }
}

// output: 5 4 3 2 1
