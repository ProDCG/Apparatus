public class Matrix {
    protected native void transpose();

    protected native Matrix add(Matrix other);

    protected native Matrix subtract(Matrix other);

    public void print() {
        System.out.println("Hello World!");
    }
}