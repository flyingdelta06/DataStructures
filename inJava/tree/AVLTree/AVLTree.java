package inJava.tree.AVLTree;

import java.util.NoSuchElementException;

class AVLNode {
    AVLNode parent = null;
    AVLNode left = null;
    AVLNode right = null;
    int leftHeight;
    int rightHeight;
    int key;

    AVLNode(int key) {
        this.key = key;
    }

    boolean isRight() {
        if (this.parent.right == this)
            return true;
        return false;
    }

    boolean isLeft() {
        if (this.parent.left == this)
            return true;
        return false;
    }
}

public class AVLTree {
    private AVLNode root = null;

    public AVLNode getRoot() {
        return this.root;
    }

    private int getMaxHeight(AVLNode a) {
        if (a.leftHeight > a.rightHeight)
            return a.leftHeight;
        return a.rightHeight;
    }

    private void fixHeight(AVLNode a) {
        a.leftHeight = 0;
        a.rightHeight = 0;
        if (a.left != null)
            a.leftHeight = this.getMaxHeight(a.left) + 1;
        if (a.right != null)
            a.rightHeight = this.getMaxHeight(a.right) + 1;
    }

    private int getBalanceFactor(AVLNode a) {
        return (a.leftHeight - a.rightHeight);
    }

    private AVLNode search(int key) {
        AVLNode curr = this.root;
        while (curr != null && curr.key != key) {
            if (key < curr.key) {
                curr = curr.left;
            } else {
                curr = curr.right;
            }
        }
        return curr;
    }

    private AVLNode getSuccessor(AVLNode a) {
        AVLNode curr = a.right;
        while (curr.left != null)
            curr = curr.left;
        return curr;
    }

    private void rotateRight(AVLNode a) {
        AVLNode b = a.left;
        AVLNode parent = a.parent;
        if (this.root == a)
            this.root = b;
        else {
            if (a.isRight())
                parent.right = b;
            else
                parent.left = b;
        }
        b.parent = parent;
        a.left = b.right;
        if (a.left != null)
            a.left.parent = a;
        b.right = a;
        a.parent = b;
        fixHeight(a);
        fixHeight(b);
    }

    private void rotateLeft(AVLNode a) {
        AVLNode b = a.right;
        AVLNode parent = a.parent;
        if (this.root == a) {
            this.root = b;
        } else {
            if (a.isLeft())
                parent.left = b;
            else
                parent.right = b;
        }
        b.parent = parent;
        a.right = b.left;
        if (a.right != null)
            a.right.parent = a;
        b.left = a;
        a.parent = b;
        fixHeight(a);
        fixHeight(b);
    }

    private void rebalanceTree(AVLNode a) {
        AVLNode curr = a;
        while (curr != null) {
            AVLNode parent = curr.parent;
            fixHeight(curr);
            int balance = getBalanceFactor(curr);
            if (balance == -2) {
                // Right heavy
                if (getBalanceFactor(curr.right) < 0) {
                    rotateLeft(curr);
                } else {
                    // Right Left
                    rotateRight(curr.right);
                    rotateLeft(curr);
                }
            } else if (balance == 2) {
                // Left heavy
                if (getBalanceFactor(curr.left) > 0) {
                    // Left Left
                    rotateRight(curr);
                } else {
                    // Left Right
                    rotateLeft(curr.left);
                    rotateRight(curr);
                }
            }
            curr = parent;
        }
    }

    public AVLTree(int... arr) {
        for (int i : arr) {
            insert(i);
        }
    }

    public AVLTree() {
    }

    public void insert(int key) {
        AVLNode newNode = new AVLNode(key);
        if (this.root == null) {
            this.root = newNode;
        } else {
            AVLNode curr = this.root;
            while (true) {
                if (newNode.key < curr.key) {
                    if (curr.left == null) {
                        newNode.parent = curr;
                        curr.left = newNode;
                        break;
                    }
                    curr = curr.left;
                } else {
                    if (curr.right == null) {
                        newNode.parent = curr;
                        curr.right = newNode;
                        break;
                    }
                    curr = curr.right;
                }
            }
            rebalanceTree(newNode);
        }
    }

    private void inorderT(AVLNode a, StringBuffer res) {
        if (a.left != null)
            inorderT(a.left, res);
        res.append(a.key + ", ");
        if (a.right != null)
            inorderT(a.right, res);
    }

    public String inorder() {
        if (this.root == null)
            return "This tree is empty...";
        StringBuffer toReturn = new StringBuffer("[");
        inorderT(this.root, toReturn);
        String res = toReturn.substring(0, toReturn.length() - 2);
        return res + "]";
    }

    public void delete(int key) {
        AVLNode reqNode = search(key);
        if (reqNode == null) {
            try {
                throw new NoSuchElementException("The given key was not found in the tree!");
            } catch (Exception e) {
                System.out.println(e);
            }
        } else {
            AVLNode successor = null;
            if (reqNode.left == null && reqNode.right == null) {
                // Leaf node
            } else if (reqNode.left != null && reqNode.right != null) {
                // left and right
                successor = getSuccessor(reqNode);
                if (reqNode.right == successor) {
                    // Immediate right
                    successor.left = reqNode.left;
                } else {
                    // Not immediate right
                    AVLNode r = reqNode.right;
                    r.left = successor.right;
                    if (successor.right != null)
                        successor.right.parent = r;
                    successor.right = r;
                    r.parent = successor;
                    successor.left = reqNode.left;
                    if (reqNode.left != null)
                        reqNode.left.parent = successor;
                }
            } else {
                if (reqNode.right != null) {
                    successor = reqNode.right;
                } else
                    successor = reqNode.left;
            }
            if (reqNode.parent == null) {
                successor.parent = null;
                this.root = successor;
            } else {
                if (reqNode.isRight())
                    reqNode.parent.right = successor;
                else
                    reqNode.parent.left = successor;
                if (successor != null)
                    successor.parent = reqNode.parent;
            }
            rebalanceTree(reqNode.parent);
        }
    }

    public String toString() {
        return this.inorder();
    }

    public void picture() {

    }
}
