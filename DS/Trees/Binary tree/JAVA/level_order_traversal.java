import java.util.LinkedList;

import java.util.Queue;

//node class
class btNode{
    int data;
    btNode left;
    btNode right;

    // Constructor to create a new node
    btNode(int num){
        data = num;
        left = null;
        right = null;
    }
}

public class Main {
    public static void main(String[] args) {
        btNode root = null;

        root = Insert(root, 10);
        root = Insert(root, 8);
        root = Insert(root, 9);
        root = Insert(root, 7);
        root = Insert(root, 25);
        root = Insert(root, 30);
        root = Insert(root, 15);

        System.out.println("Levelorder: ");
        levelOrder(root);
    }

    // insert function

    public static btNode Insert(btNode pointer, int data){
        if(pointer == null){
            pointer = new btNode(data);
        }
        else if(data<=pointer.data){
            pointer.left = Insert(pointer.left, data);
        }
        else{
            pointer.right = Insert(pointer.right, data);
        }
        return pointer;
    }

    // levelorder traversal

    public static void levelOrder(btNode root){
        Queue<btNode> Q = new LinkedList<>();
        Q.add(root);

        while (!Q.isEmpty()){
            btNode node = Q.peek();
            System.out.print(node.data + " ");

            if(node.left!=null) Q.add(node.left);
            if(node.right!=null) Q.add(node.right);
            Q.remove();
        }
    }
}

// output:
// Levelorder:
// 10 8 25 7 9 15 30
