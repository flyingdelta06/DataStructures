package inJava.tree.AVLTree;

import inJava.stack.stackA;

class myTree extends AVLTree {
    myTree(int... a) {
        for (int i : a) {
            insert(i);
        }
    }

    private void pic(AVLNode a, int height, stackA st) {
        int h = height * 3;
        st.push(1);
        if (a != null)
            pic(a.right, height + 1, st);
        st.pop();
        int pv = 0;
        if (!st.isEmpty())
            System.out.printf("   ");
        for (int i = 0; i < st.k(); i++) {
            if (i != 0) {
                if (pv + st.data()[i] == 0)
                    System.out.printf("|  ");
                else
                    System.out.printf("   ");
            }
            pv = st.data()[i];
        }
        if (a == null)
            System.out.printf("|- nil\n");
        if (a != null)
            System.out.printf("|- %d\n", a.key);
        st.push(-1);
        if (a != null)
            pic(a.left, height + 1, st);
        st.pop();
    }

    public void picture() {
        stackA m = new stackA();
        pic(this.getRoot(), 0, m);
        System.out.println("");
    }
}

public class example {
    public static void main(String[] args) {
        myTree myTree = new myTree(2, 4, 1);
        myTree.picture();
        myTree.insert(10);
        myTree.picture();
        myTree.insert(5);
        myTree.picture();
        myTree.insert(7);
        myTree.picture();
        myTree.insert(11);
        myTree.picture();
        myTree.delete(11);
        myTree.picture();
        myTree.delete(7);
        myTree.picture();
        myTree.delete(10);
        myTree.picture();
    }
}
