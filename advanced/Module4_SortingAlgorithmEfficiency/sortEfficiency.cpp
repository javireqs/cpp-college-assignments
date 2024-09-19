// Javier Hernandez Requena
// CS 110 B - Max Lutrell
// Module 4 Assignment - Sort Efficiency

#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 100;

/** Swap - swaps integers passed by reference
 * @pre x and y are integers
 * @post values for x and y are swapped
 * @param x first integer passed by reference
 * @param y second integer passed by reference **/
void swap(int& x, int& y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

// function to find max value
int findMax(int array[], int size) 
{
   int max = array[1];
   for(int i = 2; i<=size; i++) 
   {
      if(array[i] > max)
        max = array[i];
   }
   return max; //the max element from the array
}

/** Bubble Sort Algorithm - sorts array of length n using bubble sort algorithm
 * @pre None.
 * @post array is sorted into ascending order; n is unchanged
 * @param array the array to be sorted
 * @param size the size of array **/
void bubbleSort(int array[], int size)
{
    bool sorted;
    int counter = 0;    // Counter Variable

    do
    {
        sorted = false;
        for (int i = 0; i < (size - 1); i++)
        {
            if (array[i] > array[i+1])
            {
                swap(array[i], array[i+1]);
                sorted = true;
                counter+=2;
            }
        }
    } while (sorted);
}

/** Merges two sorted array segements theArray[first..mid] and theArray[mid+1..last] into one sorted array
 * @pre first <= mid <= last. The subarrays array[first..mid] and array[mid+1..last] are each sorted in increasing order
 * @post array[first..last] is sorted.
 * @param array  The given array
 * @param first   The index of the beginning of the first segment in array.
 * @param mid   The index of the end of the first segment in theArray; mid + 1 marks the beginning of the second segment in array
 * @param last  The index of the last element in the second segment in array.
 * @note This function merges the two subarrays into a temporary array and copies the result into the original array array. **/
void merge(int array[], int first, int mid, int last)
{
    int tempArray[MAX_SIZE]; // Temporary array
    int counter = 0;        // Counter variable

    // Initialize the local indices to indicate the subarrays
    int first1 = first;             // Beginning of the first subarray
    int last1 = mid;                // End of the first subarray
    int first2 = mid + 1;           // Beginning of the second subarray
    int last2 = last;               // End of the second subarray

    // While both subarrays are not empty, copy the smaller item into the temporary array
    int index = first1;         // Next available location in tempArray
    while ((first <= last1) && (first2 <= last2))
    {
        // At this point, tempArray[first..index-1] is in order
        if (array[first1] <= array[first2])
        {
            tempArray[index] = array[first1];
            first1++;
            counter+=2;
        }
        else
        {
            tempArray[index] = array[first2];
            first2++;
            counter+=2;
        } // end if
        index++;
    } // end while
    // Finish off the first subarray, if necessary
    while (first1 <= last1)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = array[first1];
        first1++;
        index++;
        counter+=2;
    } // end while
    // Finish off the second subarray, if necessary
    while (first2 <= last2)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = array[first2];
        first2++;
        index++;
        counter+=2;
    } // end while

    // Copy the result back into the original array
    for (index = first; index <= last; index++)
        array[index] = tempArray[index];
        counter+=2;
} // end merge

/** Sorts the items in an array into ascending order using merge sort algorithm.
 * @pre array[first..last] is an array.
 * @post array[first..last] is sorted into ascending order.
 * @param array The given array.
 * @param first The index of the first element to consider in array.
 * @param last  The index of the last element to consider in array. **/
void mergeSort(int array[], int first, int last)
{
    if (first < last)
    {
        // Sort each half
        int mid = first + (last - first) / 2; // Index of midpoint

        // Sort left half theArray[first..mid]
        mergeSort(array, first, mid);

        // Sort right half theArray[mid+1..last]
        mergeSort(array, mid + 1, last);

        // Merge the two halves
        merge(array, first, mid, last);
    } // end if
} // end mergeSort

/** Counting Sort - sorts the items in an array into ascending order using count sort algorithm
 * @pre array is an array of integers and size is an integer
 * @post array is sorted into ascending order
 * @param array the array to be sorted
 * @param size the size of the array **/
void countSort(int array[], int size)
{
    int max = findMax(array, size);
    int sortedArray[size+1];
    int countArray[max+1];
    int counter = 0;        // Counter variable


    // Initialize countArray with zeros
    for (int i = 0; i <= max; i++)
    {
        countArray[i] = 0;
        counter++;
    } // end for

    // Store the count of each element
    for (int i = 1; i <= size; i++)
    {
        countArray[array[i]]++;
        counter++;
    } // end for

    // Store the total count of each array
    for (int i = 1; i <= max; i++)
    {
        countArray[i] += countArray[i - 1];
        counter+=2;
    } // end for

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size; i >= 1; i--) 
    {
        sortedArray[countArray[array[i]] - 1] = array[i];
        countArray[array[i]]--;
        counter+=3;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i <= size; i++) 
    {
        array[i] = sortedArray[i];
        counter+=2;
    }

}

/** printArray - function to print array
 * @pre array is an array of integers and size is an integer
 * @post array is printed..no changes
 * @param array the array to be sorted
 * @param size the size of the array **/
void printArray(int array[], int size) 
{
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main() 
{
    int smallArray[8];
    int midArray[32];
    int largeArray[128];

    for(int i = 0; i < 8; i++)
    {
        smallArray[i] = rand()%100; // generate random number between 0-100
    }

    for (int i = 0; i < 32; i++)
    {
        midArray[i] = rand()%100; // generate random number between 0-100
    }

    for(int i = 0; i < 128; i++)
    {
        largeArray[i] = rand()%100; // generate random number between 0-100
    }

    cout << "Sorting small array using bubble sort: " << endl;
    bubbleSort(smallArray, 8);
    printArray(smallArray, 8);
    cout << "Sorting midsize array using bubble sort: " << endl;
    bubbleSort(midArray, 32);
    printArray(midArray, 32);
    cout << "Sorting large array using bubble sort: " << endl;
    bubbleSort(largeArray, 128);
    printArray(largeArray, 128);

    for(int i = 0; i < 8; i++)
    {
        smallArray[i] = rand()%100; // generate random number between 0-100
    }

    for (int i = 0; i < 32; i++)
    {
        midArray[i] = rand()%100; // generate random number between 0-100
    }

    for(int i = 0; i < 128; i++)
    {
        largeArray[i] = rand()%100; // generate random number between 0-100
    }

    cout << "Sorting small array using merge sort: " << endl;
    mergeSort(smallArray, 0, 8);
    printArray(smallArray, 8);
    cout << "Sorting midsize array using merge sort: " << endl;
    mergeSort(midArray, 0, 32);
    printArray(midArray, 32);
    cout << "Sorting large array using merge sort: " << endl;
    mergeSort(largeArray, 0, 128);
    printArray(largeArray, 128);

    for(int i = 0; i < 8; i++)
    {
        smallArray[i] = rand()%100; // generate random number between 0-100
    }

    for (int i = 0; i < 32; i++)
    {
        midArray[i] = rand()%100; // generate random number between 0-100
    }

    for(int i = 0; i < 128; i++)
    {
        largeArray[i] = rand()%100; // generate random number between 0-100
    }

    cout << "Sorting small array using count sort: " << endl;
    countSort(smallArray, 8);
    printArray(smallArray, 8);
    cout << "Sorting midsize array using count sort: " << endl;
    countSort(midArray, 32);
    printArray(midArray, 32);
    cout << "Sorting large array using count sort: " << endl;
    countSort(largeArray, 128);
    printArray(largeArray, 128);

}



/**
 * Sample Output
 * Sorting small array using bubble sort: 
7 30 44 49 58 72 73 78 
Sorting midsize array using bubble sort: 
3 3 9 9 10 12 12 16 21 23 26 27 29 33 33 35 40 40 42 49 57 60 65 67 69 78 79 79 87 92 97 99 
Sorting large array using bubble sort: 
1 1 1 1 1 3 4 4 5 5 5 6 6 6 8 8 8 9 12 12 13 13 13 14 15 16 16 17 19 20 21 22 23 23 23 24 24 25 26 28 28 28 29 30 30 31 31 33 35 35 35 36 36 37 37 38 38 38 40 42 42 44 44 44 45 45 49 51 52 52 53 53 54 57 57 57 58 60 60 62 63 65 65 66 66 67 67 68 68 68 69 70 71 71 72 72 75 77 77 79 81 82 82 85 88 89 90 90 90 91 93 94 94 94 94 94 95 95 95 95 96 97 97 98 98 98 98 99 
Sorting small array using merge sort: 
26 34 37 38 44 37 63 66 
Sorting midsize array using merge sort: 
11 15 15 17 18 20 23 23 25 26 33 34 34 11 35 39 44 35 44 44 15 18 26 33 47 47 50 59 47 17 20 23 
Sorting large array using merge sort: 

many bugs in program, my apologies.
 * 
 */