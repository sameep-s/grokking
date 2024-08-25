#include <iostream>
using namespace std;

void printMinHeap(int arr[], int size)
{
    cout << "min heap: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int arr[], int size, int index)
{
    int smallestVal = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && arr[leftChild] < arr[smallestVal])
    {
        smallestVal = leftChild;
    }

    if (rightChild < size && arr[rightChild] < arr[smallestVal])
    {
        smallestVal = rightChild;
    }

    if (index != smallestVal)
    {
        swap(arr[smallestVal], arr[index]);
        heapify(arr, size, smallestVal);
    }
}

void insertMinHeap(int arr[], int &size, int val)
{
    // Insert values
    arr[size] = val;
    size++;

    for (int i = (size - 1) / 2; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}

int main()
{
    int arr[100]; // Assuming max heap size is 100
    int size = 0; // Current size of the heap

    // Test case 1
    insertMinHeap(arr, size, 5);
    printMinHeap(arr, size);

    // Test case 2
    insertMinHeap(arr, size, 2);
    printMinHeap(arr, size);

    // Test case 3
    insertMinHeap(arr, size, 8);
    printMinHeap(arr, size);

    return 0;
}