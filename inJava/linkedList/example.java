package inJava.linkedList;

public class example {
    // All Methods:
    // addFirst(int val); --> adds val at the head of the list
    // add(int val, int index); --> adds val at the index specified
    // addLast(int val); --> adds val at the end of the list
    // extend(int[] arr); --> appends the array elements to the list at the end
    // removeFirst(); --> removes the first element
    // remove(int index); --> removes the element at the specified index
    // removeLast(); --> removes the element at the end of the list
    // getFirst(); --> returns the first element
    // get(int index); --> returns the element at the specified index
    // getLast(); --> returns the element at the end
    // display(); --> displays the list as a string
    // toArray(); --> returns an array with the elements in the list
    public static void main(String[] args){
        List myList = new List();
        myList.add(15);
        myList.display();
        // int[] toExtend = {1, 2, 3, 4};
        myList.extend(1, 2, 3, 4); // myList.extend(toExtend); Also works
        myList.display();
        // Also supports iteration
        for (Integer a : myList) {
            System.out.println(a);
        }
        int[] myArr = myList.toArray();
    }
}
