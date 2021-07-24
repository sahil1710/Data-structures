import java.lang.Math.*;

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
        root = Insert(root, 45);

        System.out.println("Height of binary tree: "+ findHeight(root));
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

    // function to find height

    public static int findHeight(btNode root){
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
