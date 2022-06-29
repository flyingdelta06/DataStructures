package inJava.tree.binaryTree;

import java.util.NoSuchElementException;

class binaryTree {
    private Node root = null;
    private void inorderT(Node a){
        if (a.left != null)  inorderT(a.left);
        System.out.printf("%d, ", a.key);
        if (a.right != null) inorderT(a.right);
    }
    private Node search(int key){
        Node currNode = this.root;
        while (key != currNode.key) {
            if (key < currNode.key) currNode = currNode.left;
            else if (key > currNode.key) currNode = currNode.right;
            if (currNode == null){
                return null;
            }
        }
        return currNode;
    }
    private Node getSuccessor(Node a){
        Node temp = a.right;
        while (temp.left != null) temp = temp.left;
        return temp;
    }
    void insert(int key){
        Node newNode = new Node(key);
        if (this.root == null){
            this.root = newNode;
            return;
        }
        Node currNode = this.root;
        while (currNode != null){
            if (key <= currNode.key) {
                if (currNode.left == null){
                    newNode.parent = currNode;
                    currNode.left = newNode;
                    break;
                } else currNode = currNode.left;
            } else {
                if (currNode.right == null){
                    newNode.parent = currNode;
                    currNode.right = newNode;
                    break;
                } else currNode = currNode.right;
            }
        }
    }
    void inorder(){
        if (this.root == null) {
            System.out.println("The tree is empty...");
            return;
        }
        System.out.printf("[");
        inorderT(this.root);
        System.out.printf("\b\b] \n");
    }
    void delete(int key){
        Node toDelete = search(key);
        if (toDelete == null) throw new NoSuchElementException("No such element found!");
        if (toDelete.left != null && toDelete.right != null) {
            Node y = getSuccessor(toDelete);
            if (y == toDelete.right){
                if (toDelete.parent != null) {
                    y.left = toDelete.left;
                    y.left.parent = y;
                    if (toDelete.parent.right == toDelete){
                        toDelete.parent.right = y;
                    } else toDelete.parent.left = y;
                    y.parent = toDelete.parent;
                } else {
                    this.root = y;
                    y.parent = null;
                    y.left = toDelete.left;
                    y.left.parent = y;
                }
            } else {
                Node r = toDelete.right;
                Node x = y.right;
                r.left = x;
                if (x != null) x.parent = r;
                y.right = r;
                if (x != null) r.parent = y;
                y.left = toDelete.left;
                y.left.parent = y;
                if (toDelete.parent != null) {
                    toDelete.parent.right = y;
                    y.parent = toDelete.parent;
                }
                else {
                    this.root = y;
                    y.left = toDelete.left;
                    y.left.parent = y;
                }
            }
        } else if (toDelete.left != null || toDelete.right != null){
            Node subTree = (toDelete.left != null)? toDelete.left : toDelete.right;
            if (toDelete.parent != null){
                if (toDelete.parent.right == toDelete) {
                    toDelete.parent.right = subTree;
                    subTree.parent = toDelete.parent;
                } else {
                    toDelete.parent.left = subTree;
                    subTree.parent = toDelete.parent;
                }
            } else {
                this.root = subTree;
                subTree.parent = null;
            }
        } else {
            if (toDelete.parent != null) {
                if (toDelete.parent.right == toDelete) {
                    toDelete.parent.right = null;
                } else toDelete.parent.left = null;
            } else this.root = null;
        }
    }
    // int[] toList();

}

final class Node{
    Node parent = null;
    Node left = null;
    Node right = null;
    int key = 0;
    Node(int val){
        this.key = val;
    }
    Node(int val, Node parent, Node left, Node right){
        this.key = val;
        this.left = left;
        this.right = right;
        this.parent = parent;
    }
}