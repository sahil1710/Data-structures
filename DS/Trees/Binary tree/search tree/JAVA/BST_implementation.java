import java.util.Scanner;

class bstNode{
    int data;
    bstNode left;
    bstNode right;

    bstNode(int num){
        data = num;
        left = null;
        right = null;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        bstNode root = null;

        root = Insert(root, 10);
        root = Insert(root, 8);
        root = Insert(root, 9);
        root = Insert(root, 7);
        root = Insert(root, 25);
        root = Insert(root, 30);
        root = Insert(root, 15);

        System.out.println("Enter a number:");

        int num = scan.nextInt();
        if(search(root, num)){
            System.out.println("Found");
        }

        else {
            System.out.println("Not found");
        }
    }

    public static bstNode Insert(bstNode pointer, int data){
        if(pointer == null){
            pointer = new bstNode(data);
        }
        else if(data<=pointer.data){
            pointer.left = Insert(pointer.left, data);
        }
        else{
            pointer.right = Insert(pointer.right, data);
        }
        return pointer;
    }

    public static boolean search(bstNode pointer, int data){
        if(pointer == null) {
            return false;
        }
        if(pointer.data == data){
            return true;
        }

        else if(pointer.data>data){
            return search(pointer.left, data);
        }
        else {
            return search(pointer.right, data);
        }
    }
}
