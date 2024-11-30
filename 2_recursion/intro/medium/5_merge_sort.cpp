#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> mergeSort(vector<int> &arr)
    {
        mergeSortHelper(arr);

        return arr;
    }

    void mergeSortHelper(std::vector<int> &arr)
    {
        if (arr.size() > 1)
        {
            // Step 1 : calc mid
            int mid = arr.size() / 2;

            // Step 2: create two counterparts left and right
            vector<int> left(arr.begin(), arr.begin() + mid);
            vector<int> right(arr.begin() + mid, arr.end());

            mergeSortHelper(left);
            mergeSortHelper(right);

            // Step 3: check values based on conditionals
            int i = 0, j = 0, k = 0;
            while (i < left.size() && j < right.size())
            {
                if (left[i] < right[j])
                    arr[k++] = left[i++];
                else
                    arr[k++] = right[j++];
            }

            while (i < left.size())
                arr[k++] = left[i++];

            while (j < right.size())
                arr[k++] = right[j++];
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 2, 8, 3, 1, 6};
    printf("Input Array:");

    for (int num : arr)
        printf(" %d", num);

    printf("\n");

    sol.mergeSort(arr);

    printf("Sorted Array:");
    for (int num : arr)
        printf(" %d", num);

    printf("\n");

    return 0;
}
