package inJava.linkedList;

class List {
    private Node head = null;
    private Node tail = null;
    int length = 0;
    List(int[] inpArr){
        this.head = new Node(inpArr[0], null, null);
        Node currNode = this.head;
        for (int i = 1; i < inpArr.length; i++){
            Node newNode = new Node(inpArr[i], currNode, null);
            currNode.next = newNode;
            currNode = currNode.next;
            if (i != inpArr.length - 1) currNode = currNode.next;
        }
        this.tail = currNode;
        this.length = inpArr.length;
    }

    private Node getNode(int index){
        Node currNode = this.head;
        int i = 0;
        // Check if index < this.length / 2
        while (i != index){
            currNode = currNode.next;
            i++;
        }
        return currNode;
    }

    int length(){
        return this.length;
    }

    int addFirst(int val){
        if (this.length == 0) {
            this.head = new Node(val);
            this.tail = this.head;
            this.length += 1;
            return this.length;
        }
        Node newNode = new Node(val);
        newNode.next = this.head;
        this.head.previous = newNode;
        this.head = newNode;
        this.length += 1;
        return this.length;
    }
    int add(int val, int index){
        if (index < 0 || index >= this.length){
            throw new ArrayIndexOutOfBoundsException(index);
        }
        if (this.length == 0) {
            this.head = new Node(val);
            this.tail = this.head;
            this.length += 1;
            return this.length;
        }
        if (index == 0) {
            Node newNode = new Node(val);
            newNode.next = this.head;
            this.head.previous = newNode;
            this.head = newNode;
            this.length += 1;
            return this.length;
        }
        else if (index == this.length - 1){
            Node newNode = new Node(val);
            newNode.previous = this.tail;
            this.tail.next = newNode;
            this.tail = newNode;
            this.length += 1;
            return this.length;
        } 
        else {
            Node pvNode = getNode(index - 1);
            Node nextNode = getNode(index);
            Node newNode = new Node(val);
            newNode.previous = pvNode;
            pvNode.next = newNode;
            newNode.next = nextNode;
            nextNode.previous = newNode;
            this.length += 1;
            return this.length;
        }
    }
    int add(int val){
        return addFirst(val);
    }
    int addLast(int val){
        if (this.length == 0) {
            this.head = new Node(val);
            this.tail = this.head;
            this.length += 1;
            return this.length;
        }
        Node newNode = new Node(val);
        newNode.previous = this.tail;
        if (this.tail != null) this.tail.next = newNode;
        this.tail = newNode;
        this.length += 1;
        return this.length;
    }
    int extend(int[] a){
        for (int i = 0; i < a.length; i++){
            this.addLast(a[i]);
        }
        return this.length;
    }
    int removeFirst(){
        if (this.length == 0) {
            throw new ArrayIndexOutOfBoundsException(0);
        } else if (this.length == 1) {
            int data = this.head.data;
            this.head = null;
            this.tail = null;
            this.length -= 1;
            return data;
        }
        int data = this.head.data;
        this.head = this.head.next;
        if (this.head != null) this.head.previous = null;
        this.length -= 1;
        return data;
    }
    int removeLast(){
        if (this.length == 0) {
            throw new ArrayIndexOutOfBoundsException(0);
        } else if (this.length == 1) {
            int data = this.head.data;
            this.head = null;
            this.tail = null;
            this.length -= 1;
            return data;
        }
        int data = this.tail.data;
        this.tail = this.tail.previous;
        if (this.tail != null) this.tail.next = null;
        this.length -= 1;
        return data;
    }
    int remove(int index){
        if (index < 0 || index >= this.length){
            throw new ArrayIndexOutOfBoundsException(index);
        } else if (this.length == 1) {
            int data = this.head.data;
            this.head = null;
            this.tail = null;
            this.length -= 1;
            return data;
        }
        if (index == 0) {
            this.head = this.head.next;
            this.head.previous = null;
            this.length -= 1;
            return this.length;
        }
        else if (index == this.length - 1){
            this.tail = this.tail.previous;
            this.tail.next = null;
            this.length -= 1;
            return this.length;
        } 
        else {
            Node pvNode = getNode(index - 1);
            Node nextNode = getNode(index + 1);
            pvNode.next = nextNode;
            nextNode.previous = pvNode;
            this.length -= 1;
            return this.length;
        }
    }
    int getFirst(){
        if (this.length == 0) {
            throw new ArrayIndexOutOfBoundsException(0);
        }
        return this.head.data;
    }
    int getLast(){
        if (this.length == 0) {
            throw new ArrayIndexOutOfBoundsException(0);
        }
        return this.tail.data;
    }
    int get(int index){
        if (index < 0 || index >= this.length){
            throw new ArrayIndexOutOfBoundsException(index);
        }
        return this.getNode(index).data;
    }
    void display(){
        if (this.length == 0) {
            System.out.println("The list is empty...");
            return;
        }
        Node curNode = this.head;
        System.out.printf("[");
        while (curNode.next != null){
            System.out.printf("%d, ", curNode.data);
            curNode = curNode.next;
        }
        System.out.printf("%d]\n", curNode.data);
    }
    int[] toArray(){
        if (this.length == 0) {
            return new int[0];
        }
        int[] Arr = new int[this.length];
        Node currNode = this.head;
        for (int i = 0; i < this.length; i++){
            Arr[i] = currNode.data;
            currNode = currNode.next;
        }
        return Arr;
    }
}

final class Node{
    int data = 0;
    Node next = null;
    Node previous = null;
    Node(int val){
        this.data = val;
        this.next = null;
        this.previous = null;
    }
    Node(int val, Node previous, Node next){
        this.data = val;
        this.next = next;
        this.previous = previous;
    }
}