class Matrix {
    protected native void print();

    protected native void transpose();

    protected native Matrix add(Matrix other);

    protected native Matrix subtract(Matrix other);

    protected native void add(Matrix other);

    protected native void subtract(Matrix other);

    // constant math
    protected native void add(double num);

    protected native void subtract(double num);

    protected native void multiply(double num);

    protected native void divide (double num);


    public void print() {
        System.out.println("Hello World!");
    }
}