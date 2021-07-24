import java.lang.Math.*;

//node class
class bstNode{
    int data;
    bstNode left;
    bstNode right;

    // Constructor to create a new node
    bstNode(int num){
        data = num;
        left = null;
        right = null;
    }
}

public class Main {
    public static void main(String[] args) {
        bstNode root = null;

        root = Insert(root, 10);
        root = Insert(root, 8);
        root = Insert(root, 9);
        root = Insert(root, 7);
        root = Insert(root, 25);
        root = Insert(root, 30);
        root = Insert(root, 15);
        root = Insert(root, 45);

        System.out.println("Height of binary tree: "+ findHeight(root));
    }

    // insert function

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

    // function to find height

    public static int findHeight(bstNode root){
       if(root==null){
           return -1;
       }
      int leftheight = findHeight(root.left);
      int rightheight = findHeight(root.right);

      return Math.max(leftheight, rightheight) + 1;
    }
}

// output:
// Height of binary tree: 3
