package Examples;

class InsertionSort {
    public static void main(String[] args) {
        int[] arr = new int[]{1, 29, 643, 25, -5};
        System.out.println(arr);
    }

    public void insertion(int[] arr) {
        int i, key, j;
        for (i = 1; i < arr.length; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
}