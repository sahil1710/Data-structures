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

        System.out.println("MAX: " + findMax(root));
        System.out.println("MIN: " + findMin(root));
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

    // function to find max integer in BST

    public static int findMax(bstNode root){
       if(root==null){
           System.out.println("Error: tree is empty");
           return 0;
       }

       while (root.right!=null){
           root = root.right;
       }

       return root.data;
    }

    // function to find min integer in BST

    public static int findMin(bstNode root){
        if(root==null){
            System.out.println("Error: tree is empty");
            return 0;
        }

        while (root.left!=null){
            root = root.left;
        }

        return root.data;
    }
}

// output:
// MAX: 30
// MIN: 7
