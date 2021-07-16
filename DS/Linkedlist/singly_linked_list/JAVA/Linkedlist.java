package JAVA;

import java.util.Scanner;

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

    //insert a node at the front of linked list
    public void head(int num){
        Node temp = new Node(num);
        if(head==null){
            head = temp;
            return;
        }
        temp.link = head;
        head = temp;
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

    //insert a node at given position in linked list
    public void insert(int num, int loc){
        Node temp = new Node(num);
        if(loc==1){
            temp.link = head;
            head = temp;
        }
        loc -= 2;
        Node temp1 = head;
        while (loc>0){
            temp1 = temp1.link;
            loc--;
        }
        temp.link = temp1.link;
        temp1.link = temp;
    }

    //delete a node

    public void delete(int loc){
        Node temp = head;
        if(loc==1){
            head = temp.link;
            return;
        }
        loc -=2;
        while (loc>0){
            temp = temp.link;
            loc--;
        }

        Node temp1 = temp.link;
        temp.link = temp1.link;
    }

    //reverse list
    public void reverse(){
        Node prev,temp,next;
        temp = head;
        prev = null;
        while (temp!=null){
            next = temp.link;
            temp.link = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
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
        Scanner scan = new Scanner(System.in);
        Linkedlist list = new Linkedlist();
        int size = scan.nextInt();

        while (size>0)
        {
            list.append(scan.nextInt());
            size--;
        }
        list.print();
        scan.close();
    }
}
