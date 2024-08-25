#include <iostream>
using namespace std;

// Add new node
// Iterative approach
void insertMinHeap(int arr[], int &n, int value)
{
    // Increment n
    n++;
    int index = n - 1;

    while (index > 0 && value < arr[(index - 1) / 2])
    {
        arr[index] = arr[(index - 1) / 2];
        index = (index - 1) / 2;
    }

    arr[index] = value;
}

// Shows the min heap
void printMinHeap(int heap[], int n)
{
    cout << "Min Heap: ";
    for (int index = 0; index < n; index++)
    {
        cout << heap[index] << " ";
    }
    cout << endl;
}

int main()
{
    const int maximumSize = 100;
    int minHeap[maximumSize];
    int heapSize = 0;

    // Test case 1
    insertMinHeap(minHeap, heapSize, 5);
    printMinHeap(minHeap, heapSize);

    // Test case 2
    insertMinHeap(minHeap, heapSize, 2);
    printMinHeap(minHeap, heapSize);

    // Test case 3
    insertMinHeap(minHeap, heapSize, 8);
    printMinHeap(minHeap, heapSize);

    return 0;
}