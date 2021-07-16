package JAVA.Recursion_problems;

import JAVA.Linkedlist;

import java.util.Scanner;

public class linkedlist {

    static class Node
    {
        int data;
        Node link;

        Node(int num){
            data = num;
            link = null;
        }
    }
    Node head;

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

    //reverse function
    public void reverse(Node pointer){
        if(pointer.link==null){
            head = pointer;
            return;
        }
        reverse(pointer.link);
        Node temp = pointer.link;
        temp.link = pointer;
        pointer.link = null;
    }

    //print list
    public void print(Node pointer){
        if(pointer==null) return;

        System.out.print(pointer.data + " ");
        print(pointer.link);
    }

    //main
    public static void main(String[] args){
        linkedlist list = new linkedlist();
        list.head = null;
        
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);
      
        list.reverse(list.head);
        list.print(list.head);
    }
}
