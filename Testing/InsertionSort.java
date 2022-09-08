package Testing;

import java.util.Random;

class InsertionSort {

    public static void main(String[] args) {
        int[] arr = new int[10000];        
        Random rand = new Random();
        for (int i = 0; i < 10000; i++) {
            arr[i] = rand.nextInt(10000);
        }
        long timeTotal = 0;
        // for (int i = 0; i < 100; i++) {
        //     long startTime = System.currentTimeMillis();
        //     quickSort(arr, 0, arr.length - 1);
        //     long endTime = System.currentTimeMillis();
        //     // timeTotal += ((endTime - startTime) / 100000);
        //     timeTotal += (endTime - startTime);
        // }
        long startTime = System.currentTimeMillis();
        quickSort(arr, 0, arr.length - 1);
        long endTime = System.currentTimeMillis();
        // timeTotal += ((endTime - startTime) / 100000);
        timeTotal = (endTime - startTime);
        System.out.println(timeTotal);
        // System.out.println( (float)timeTotal / 100);
    }

    static void swap(int[] arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static int partition(int[] arr, int low, int high)
{
      
    // pivot
    int pivot = arr[high]; 
      
    // Index of smaller element and
    // indicates the right position
    // of pivot found so far
    int i = (low - 1); 
  
    for(int j = low; j <= high - 1; j++)
    {
          
        // If current element is smaller 
        // than the pivot
        if (arr[j] < pivot) 
        {
              
            // Increment index of 
            // smaller element
            i++; 
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

static void quickSort(int[] arr, int low, int high)
{
    if (low < high) 
    {
          
        // pi is partitioning index, arr[p]
        // is now at right place 
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
}