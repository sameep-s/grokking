#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> mergeSort(std::vector<int> &arr)
    {
        return arr;
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
