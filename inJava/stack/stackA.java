package inJava.stack;

public class stackA {
    int maxLength = 100;
    private int[] data = new int[maxLength];
    private int k = 0;

    public stackA() {
    }

    public stackA(int size) {
        this.maxLength = size;
        this.data = new int[maxLength];
    }

    public int peek() {
        if (this.k == 0)
            throw new ArrayIndexOutOfBoundsException();
        return data[k - 1];
    }

    public int push(int val) {
        if (this.k == maxLength)
            throw new ArrayIndexOutOfBoundsException();
        this.data[this.k] = val;
        this.k += 1;
        return this.k + 1;
    }

    public int pop() {
        if (this.k == 0)
            throw new ArrayIndexOutOfBoundsException();
        int val = this.data[this.k - 1];
        this.k -= 1;
        return val;
    }

    public boolean isEmpty() {
        if (this.k == 0)
            return true;
        return false;
    }

    public int[] data() {
        return this.data;
    }

    public int k() {
        return this.k;
    }
}
