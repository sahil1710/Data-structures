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

        System.out.print("preorder: ");
        preorder(root);

        System.out.print("\ninorder: ");
        inorder(root);

        System.out.print("\npostorder: ");
        postorder(root);
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

    // preorder traversal

    public static void preorder(btNode root) {
        if (root == null) return;

        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    // preorder traversal

    public static void inorder(btNode root) {
        if (root == null) return;

        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    // postorder traversal

    public static void postorder(btNode root) {
        if (root == null) return;

        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
    }
}

// output:
// Preorder: 10 8 7 9 25 15 30
// Inorder: 7 8 9 10 15 25 30
// Postorder: 7 9 8 15 30 25 10
