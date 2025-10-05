package binary_trees.transversals;

class Node
{
    int data;
    Node left;
    Node right;
    public Node(int key)
    {
        data=key;
    }
}

public class Main
{
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.right = new Node(5);

        // Just to verify the tree is created
        System.out.println("Root: " + root.data);
        System.out.println("Left Child: " + root.left.data);
        System.out.println("Right Child: " + root.right.data);
        System.out.println("Left-Right Child: " + root.left.right.data);
    }
}