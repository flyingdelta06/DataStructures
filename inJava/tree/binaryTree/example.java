package inJava.tree.binaryTree;

import java.util.Scanner;

import inJava.stack.stackA;

class myTree extends binaryTree {

    private void pic(Node a, int height, stackA st) {
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
        pic(this.root(), 0, m);
    }
}

public class example {

    static public int[] takeInput(String prompt, Scanner sc) {
        System.out.printf("Enter , seperated numbers: ");
        String inpString = sc.nextLine();
        String[] chars = inpString.split(",");
        int[] nums = new int[chars.length];
        for (int i = 0; i < chars.length; i++) {
            chars[i] = chars[i].trim();
            nums[i] = Integer.parseInt(chars[i]);
        }
        return nums;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        myTree myTree = new myTree();
        char inp = 'i';
        while (inp != 'e') {
            System.out.printf("i - input, d - delete, p - print, e - end\n");
            System.out.printf("Operation: ");
            inp = (sc.nextLine().toCharArray())[0];
            switch (inp) {
                case 'i': {
                    int[] nums = takeInput("Enter , seperated numbers: ", sc);
                    for (int a : nums)
                        myTree.insert(a);
                    myTree.inorder();
                }
                    break;
                case 'd': {
                    int[] nums = takeInput("Enter , seperated numbers: ", sc);
                    for (int a : nums)
                        myTree.delete(a);
                    myTree.inorder();
                }
                    break;
                case 'p':
                    myTree.picture();
                    break;
            }
        }
        sc.close();
    }
}
